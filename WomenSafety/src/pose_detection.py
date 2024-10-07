import cv2
from ultralytics import YOLO

# Initialize YOLOv8n-pose model
model = YOLO('yolov8n-pose.pt')  # Ensure correct path to your model file

def detect_pose(frame):
    """
    Detect poses in a given frame.
    
    Parameters:
    - frame: The frame from the webcam.

    Returns:
    - annotated_frame: The frame with pose detection annotations.
    """
    # Convert the frame to RGB
    img_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Perform inference
    results = model(img_rgb)

    # Annotate the frame with pose detection results
    annotated_frame_rgb = results[0].plot()  # Plot pose detection results onto the RGB frame

    # Convert back to BGR for display
    annotated_frame = cv2.cvtColor(annotated_frame_rgb, cv2.COLOR_RGB2BGR)
    
    return annotated_frame
