import cv2
import mediapipe as mp
import time


class HandDetector():
    def __init__(self, static_img_mode=False, max_hands=2, min_detection_confidence=0.5, min_tracking_confidence=0.5):
        self.static_img_mode = static_img_mode
        self.max_hands = max_hands
        self.min_detection_confidence = min_detection_confidence
        self.min_tracking_confidence = min_tracking_confidence

        self.mpHands = mp.solutions.mediapipe.python.solutions.hands
        self.hands = self.mpHands.Hands(
            self.static_img_mode, self.max_hands, self.min_detection_confidence, self.min_tracking_confidence)
        self.mpDraw = mp.solutions.mediapipe.python.solutions.drawing_utils

    def detectHand(self, img, draw=True):
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.hands.process(imgRGB)

        # lets open the processed object and extract the information
        # print(results.multi_hand_landmarks)

        if self.results.multi_hand_landmarks:
            # Check for every hands in the image
            for handLMS in self.results.multi_hand_landmarks:
                if draw:
                    # Draw thw hands using built in drawing utilities
                    self.mpDraw.draw_landmarks(
                        img, handLMS, self.mpHands.HAND_CONNECTIONS)

        return img

    # TODO: find the positions of all the points on the hands
    def detectPositions(self, img, handNumber=0, draw=True):
        landmarkList = []
        if self.results.multi_hand_landmarks:
            # Check for perticukar hand in the image(handNumber)
            myHand = self.results.multi_hand_landmarks[handNumber]

            for id, lm in enumerate(myHand.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x*w), int(lm.y*h)
                # print(id, cx, cy)
                landmarkList.append([id, cx, cy])
                # Draw a circle for id=0 wrist
                if draw:
                    cv2.circle(img, (cx, cy), 5, (255, 0, 0), cv2.FILLED)

        return landmarkList


def main():
    prevTime = 0
    CurrentTime = 0

    cap = cv2.VideoCapture(0)

    # Create an object of HandDetector
    detector = HandDetector()

    while True:
        success, img = cap.read()

        # Calling the detectHand function to detecet the hands
        img = detector.detectHand(img)
        # Get the landmark list for the hands
        lmList = detector.detectPositions(img, draw=False)

        # check if the list is empty or Not
        # if lmList:
        #     # print(lmList[12])
        #     # detect landmark 13
        #     cv2.circle(img, (lmList[13][1], lmList[13]
        #                [2]), 5, (255, 0, 0), cv2.FILLED)

        currentTime = time.time()
        fps = 1/(currentTime - prevTime)
        prevTime = currentTime

        # Write the fps into the image
        cv2.putText(img, str(int(fps)), (10, 78),
                    cv2.FONT_HERSHEY_TRIPLEX, 2, (255, 0, 255), 2)

        cv2.imshow("Image", img)
        cv2.waitKey(1)


if __name__ == "__main__":
    main()
