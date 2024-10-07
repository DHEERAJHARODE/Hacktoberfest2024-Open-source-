import cv2
import numpy as np

# Load OpenCV’s DNN face detector
prototxt = 'models/opencv_face_detector.pbtxt'
model_file = 'models/opencv_face_detector_uint8.pb'
net = cv2.dnn.readNetFromTensorflow(model_file, prototxt)

def detect_faces(frame):
    """
    Detect faces in the frame using OpenCV's DNN face detector.
    
    Args:
        frame: The input frame from which faces are to be detected.

    Returns:
        List of bounding boxes for detected faces.
    """
    blob = cv2.dnn.blobFromImage(frame, 1.0, (300, 300), (104.0, 177.0, 123.0))
    net.setInput(blob)
    detections = net.forward()
    faces = []
    h, w = frame.shape[:2]
    for i in range(detections.shape[2]):
        confidence = detections[0, 0, i, 2]
        if confidence > 0.5:  # Confidence threshold
            box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])
            (startX, startY, endX, endY) = box.astype("int")
            faces.append((startX, startY, endX, endY))
    return faces
