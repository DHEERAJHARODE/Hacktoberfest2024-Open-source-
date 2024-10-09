# src/count_persons.py
def count_persons(predictions):
    """
    Count the number of persons in the predictions.
    """
    person_count = 0
    for *xyxy, conf, cls in predictions:
        if int(cls) == 0:  # Class '0' corresponds to a person in YOLOv5
            person_count += 1
    return person_count