import datetime
import time
import pygame

def set_alarm(alarm_time):
    print(f"Alarm set for {alarm_time}")

    while True:
        # Get the current time
        current_time = datetime.datetime.now().strftime("%H:%M:%S")
        print(f"Current Time: {current_time}", end="\r")

        # Check if the current time matches the alarm time
        if current_time == alarm_time:
            print("\nWake up! It's time!")

            # Initialize pygame mixer and play the alarm sound
            pygame.mixer.init()
            pygame.mixer.music.load('alarm_sound.mp3')  # Make sure your alarm sound is in the same directory
            pygame.mixer.music.play()

            # Wait for the music to finish
            while pygame.mixer.music.get_busy():
                time.sleep(1)

            break

        # Wait for 1 second before checking the time again
        time.sleep(1)

if __name__ == "__main__":
    # User input for the alarm time (HH:MM:SS format)
    alarm_time = input("Enter the alarm time (HH:MM:SS): ")
    set_alarm(alarm_time)
