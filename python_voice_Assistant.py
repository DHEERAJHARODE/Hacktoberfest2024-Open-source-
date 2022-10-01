import speech_recognition as sr
import pyttsx3
import pywhatkit
import datetime
import wikipedia
import pyjokes

listener = sr.Recognizer()
engine = pyttsx3.init()
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)


def talk(text):
    engine.say(text)
    engine.runAndWait()


def take_command():
    try:
        with sr.Microphone() as source:
            print('Listening...')
            voice = listener.listen(source)
            command = listener.recognize_google(voice)
            command = command.lower()
            if 'next' in command:
                command = command.replace('next', '')
                print(command)
    except:
        pass
    return command


def run_next():

    command = take_command()
    print(command)
    if 'play' in command:
        song = command.replace('play', '')
        talk('playing' + song)
        pywhatkit.playonyt(song)
    elif 'time' in command:
        time = datetime.datetime.now().strftime('%I:%M %p')
        print(time)
        talk('Current time is' + time)
    elif 'who is ' in command:
        person = command.replace('wiki', '')
        info = wikipedia.summary(person, 1)
        print(info)
        talk(info)
    elif 'wiki' in command:
        person = command.replace('wiki', '')
        info = wikipedia.summary(person, 1)
        print(info)
        talk(info)
    elif 'wikipedia' in command:
        person = command.replace('wikipedia', '')
        info = wikipedia.summary(person, 1)
        print(info)
        talk(info)
    elif 'joke' in command:
        talk(pyjokes.get_joke())
    elif 'who am i' in command:
        talk("You must be a Happy Person!")
    elif 'i am sad' in command:
        talk("Don't cry i will be with you forever!")
    elif 'love' in command:
        talk(wikipedia.summary(command, 1))
    else:
        talk('Please tell the command again!')


while True:
    run_next()