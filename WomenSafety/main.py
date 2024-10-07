# Modified code plz checkout

# 
# 


# 

import cv2
import time
from src.gender_detection import detect_gender
from src.lone_woman_detection import detect_lone_woman
from src.detect_faces import detect_faces
from src.pose_detection import detect_pose  # Import the pose detection function

def main():
    # Open webcam
    webcam = cv2.VideoCapture(0)

    # Variables for lone woman detection
    tracking_start_time = time.time()

    # Main loop
    while webcam.isOpened():
        status, frame = webcam.read()
        if not status:
            break

        # Perform face detection
        faces = detect_faces(frame)  # No need to pass the network as it's now handled inside detect_faces
        frame, male_count, female_count = detect_gender(frame, faces)

        # Detect lone woman
        tracking_start_time = detect_lone_woman(female_count, male_count, tracking_start_time)

        # Perform pose detection
        annotated_frame = detect_pose(frame)

        # Display the annotated frame
        cv2.imshow('Pose Detection', annotated_frame)

        # Press 'q' to exit
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release resources
    webcam.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
