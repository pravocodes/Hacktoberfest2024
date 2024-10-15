import speech_recognition as sr
from colorama import Fore, Style, init
import pyttsx3
from intro import intro


init(autoreset=True)
engine = pyttsx3.init()
intro("TO-DO AI")
# Greet the user
print(Fore.GREEN + 'Hello Sir, Tell me what is your task')
engine.say('Hello Sir, Tell me what is your task')
engine.runAndWait()
print(Fore.YELLOW + "Listening...")

def get_voice_input():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
      
        audio = recognizer.listen(source)
        
        try:
            text = recognizer.recognize_google(audio)
            print(Fore.CYAN + f"You said: {Fore.LIGHTWHITE_EX + text}")
            return text
        except sr.UnknownValueError:
            print(Fore.RED + "Sorry, I did not understand the audio.")
        except sr.RequestError:
            print(Fore.RED + "Could not request results; check your network connection.")

def save_task_to_file(task, filename="daily_tasks.txt"):
    try:
        with open(filename, "r") as file:
            lines = file.readlines()
            task_number = len(lines) + 1
    except FileNotFoundError:
        task_number = 1

    with open(filename, "a") as file:
        file.write(f"{task_number}. {task}\n")

while True:
    task = get_voice_input()
    if task:
        if "exit" in task.lower():
            confirmation_message = f"Got it! I have added tasks to your list."
            print(Fore.MAGENTA + confirmation_message)
            engine.say(confirmation_message)
            engine.runAndWait()
            print(Fore.RED + "Exiting the program. Bye!")
            engine.say("Exiting the program. Bye!")
            engine.runAndWait()
            break
        save_task_to_file(task)
