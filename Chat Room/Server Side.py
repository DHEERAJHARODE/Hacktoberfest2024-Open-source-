import socket
from threading import Thread

clients = {}
addresses = {}

host = socket.gethostname()
ip = socket.gethostbyname(host)
port = 8080

s = socket.socket()
s.bind((host, port))
print(host, ip)
print("Ask clients to enter host IP as :", ip, "and port as :", port)


def accept_client():
    while True:
        client_con, client_address = s.accept()
        client_con.send(
            "Hey! Welcome to the Chat Room. Enter Your Name To Continue.".encode("utf8")
        )
        addresses[client_address] = client_address
        t2 = Thread(target=handle_client, args=(client_con, client_address)).start()
        print(client_address, "Has Connected")


def broadcast(message, prefix=""):
    for x in clients:
        x.send(bytes(prefix, "utf8") + message)


def handle_client(con, adr):
    name = con.recv(1024).decode("utf8")
    welcome_message = (
        "Thanks for using this Chat Room "
        + name
        + ". You can use #quit if you want to exit"
    )
    con.send(bytes(welcome_message, "utf8"))
    print(name, "has joint the chat")

    message = name + " has joint the chat!"
    broadcast(bytes(message, "utf8"))

    clients[con] = name

    try:
        while True:
            message = con.recv(1024)
            if message != bytes("#quit", "utf8"):
                broadcast(message, name + ": ")
            else:
                con.close()
                del clients[con]
                broadcast(bytes(name + " has left the chat.", "utf8"))
    except:
        print(name + " has left the chat")


if __name__ == "__main__":
    s.listen()  # Only 5 clients can join
    print("The Server Is Now Online")
    t1 = Thread(target=accept_client)
    t1.start()
    t1.join()  # Waits for one thread to stop before running the next.
