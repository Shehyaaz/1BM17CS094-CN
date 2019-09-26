#TCP server program
from socket import *
serverName="127.0.0.1"
serverPort=12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
print('Server ready to receive requests : ')
while True:
    connSocket, addr = serverSocket.accept()
    sentence = connSocket.recv(1024).decode()
    try :
        file = open(sentence,'r')
        l = file.read(1024)
        connSocket.send(l.encode())
        file.close()
        connSocket.close()
    except IOError:
        print(sentence," not found")
                            
