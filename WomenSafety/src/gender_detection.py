import cv2
import numpy as np
from tensorflow.keras.preprocessing.image import img_to_array
from tensorflow.keras.models import load_model
import tensorflow as tf
from src.gender_counter import count_gender

# Check if GPU is available and print out device information
gpus = tf.config.list_physical_devices('GPU')
if gpus:
    print(f"Gender Detection running on GPU: {gpus}")
    try:
        # Set memory growth to avoid issues with memory allocation (optional)
        for gpu in gpus:
            tf.config.experimental.set_memory_growth(gpu, True)
    except RuntimeError as e:
        print(f"Error setting GPU memory growth: {e}")
else:
    print("Gender Detection running on CPU")

# Define the classes (male and female)
classes = ['man', 'woman']

# Load the gender detection model
model = load_model('models/gender_detection.model')

def detect_gender(frame, faces):
    """
    Detect the gender for each face in the frame using the loaded gender model.
    Returns the frame with labels and the counts of males and females.
    """
    face_batches = []
    bounding_boxes = []

    # Initialize male and female counts to 0
    male_count = 0
    female_count = 0

    # Process each face in the detected faces
    for (startX, startY, endX, endY) in faces:
        face_crop = np.copy(frame[startY:endY, startX:endX])
        
        # Skip very small face crops
        if (face_crop.shape[0] < 10) or (face_crop.shape[1] < 10):
            continue
        
        # Resize and preprocess the face
        face_crop = cv2.resize(face_crop, (96, 96))
        face_crop = face_crop.astype("float") / 255.0
        face_crop = img_to_array(face_crop)
        
        # Append the face to the batch
        face_batches.append(face_crop)
        bounding_boxes.append((startX, startY, endX, endY))

    # If any faces were processed, make predictions
    if face_batches:
        face_batches = np.array(face_batches)
        predictions = model.predict(face_batches)

        # Count the number of males and females
        male_count, female_count = count_gender(predictions)

        # Draw labels and bounding boxes around detected faces
        for i, (startX, startY, endX, endY) in enumerate(bounding_boxes):
            conf = predictions[i]
            idx = np.argmax(conf)
            label = classes[idx]
            label = "{}: {:.2f}%".format(label, conf[idx] * 100)
            Y = startY - 10 if startY - 10 > 10 else startY + 10
            cv2.putText(frame, label, (startX, Y), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            cv2.rectangle(frame, (startX, startY), (endX, endY), (0, 255, 0), 2)

    # Return the frame with labels and the counts of males and females
    return frame, male_count, female_count