# src/lone_woman_detection.py
import time

def detect_lone_woman(female_count, male_count, tracking_start_time):
    """
    Detect if a lone woman is present and log this if detected for more than 5 seconds.
    """
    current_time = time.time()
    if female_count == 1 and male_count == 0:
        if current_time - tracking_start_time >= 5:
            print("Lone woman detected for more than 5 seconds.")
            # Log or save the event with a timestamp
            # Save to JSON or another file as required
        return tracking_start_time
    else:
        return current_time