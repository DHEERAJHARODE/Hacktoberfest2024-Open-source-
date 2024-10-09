# src/gender_counter.py
def count_gender(predictions):
    """
    Count the number of males and females from the model's predictions.
    """
    male_count = 0
    female_count = 0

    for pred in predictions:
        if pred[0] > pred[1]:  # Index 0 is 'man', index 1 is 'woman'
            male_count += 1
        else:
            female_count += 1

    return male_count, female_count