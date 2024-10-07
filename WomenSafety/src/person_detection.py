# src/person_detection.py
import cv2
import torch
import warnings
from src.count_persons import count_persons

# Suppress FutureWarnings related to deprecated torch usage
warnings.filterwarnings("ignore", category=FutureWarning)

# Load the YOLOv5 model
model = torch.hub.load('ultralytics/yolov5', 'yolov5s', pretrained=True)

def detect_persons(frame):
    """
    Detect persons in the frame using YOLOv5 model and return the frame with
    bounding boxes and the number of persons detected.
    """
    height, width, _ = frame.shape
    img_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    
    # Perform detection
    results = model(img_rgb)
    predictions = results.pred[0]

    # Count the number of persons
    person_count = count_persons(predictions)

    # Draw bounding boxes for detected persons
    for *xyxy, conf, cls in predictions:
        if int(cls) == 0:  # Class 0 is 'person' in YOLOv5
            x1, y1, x2, y2 = map(int, xyxy)
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(frame, f'Person: {conf:.2f}', (x1, y1-10), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

    return frame, person_count