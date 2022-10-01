from tkinter import *
import tkinter
import socket
from threading import Thread


def receive():
    while True:
        try:
            message = s.recv(1024).decode("utf8")
            message_list.insert(tkinter.END, message)
        except:
            break


def send():
    message = my_message.get()
    my_message.set("")
    s.send(bytes(message, "utf8"))

    if message == "#quit":
        s.close()
        window.quit()


def closing():
    my_message.set("#quit")
    send()


host = input("Enter Host IP : ")
port = int(input("Enter Port : "))

window = Tk()
window.title("Chat Room")
window.configure(bg="white")

message_frame = Frame(window, height=100, width=100, bg="black")

my_message = StringVar()
my_message.set("")

scroll_bar = Scrollbar(message_frame)

message_list = Listbox(
    message_frame,
    height=15,
    width=100,
    bg="black",
    fg="white",
    yscrollcommand=scroll_bar.set,
)

scroll_bar.pack(side=RIGHT, fill=Y)
message_list.pack(side=LEFT, fill=BOTH)
message_frame.pack()

button_label = Label(window, text="Enter Your Message", bg="white")
button_label.pack()

text_field = Entry(window, textvariable=my_message, bg="white", width=50)
text_field.pack()

send_button = Button(window, text="Send", bg="white", command=send)
send_button.pack()

window.protocol("WM_DELETE_WINDOW", closing)

s = socket.socket()
try:
    s.connect((host, port))
except:
    print("Please Verify Host IP and Port Number")
    sys.exit(0)
recieve_thread = Thread(target=receive)
recieve_thread.start()

mainloop()
