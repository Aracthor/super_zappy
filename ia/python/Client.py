#!/usr/bin/python3
## Client.py for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/python
## 
## Made by aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Tue Feb 24 12:08:47 2015 aracthor
## Last Update Wed Feb 25 09:11:36 2015 aracthor
##

import  errno
import  socket
import  threading

from    Exceptions      import NetworkException
from    Protocol        import Protocol

class   Client:
    instance = None

    def __init__(self, host, port):
        try:
            self.socket = socket.socket()
            self.socket.connect((host, port))
            self.socket.setblocking(True)
            self.inBuffer = "";
            self.lock = threading.Lock()

        except socket.error as exception:
            if exception.args[0] == errno.ECONNREFUSED:
                raise NetworkException("Cannot connect to " + host + ":" + str(port))
            else:
                raise exception

    def sendTeamDetails(self, team, name):
        self.send("TEAM")
        self.send(team.presentationMessage(name))

        for role in team.classes:
            self.send(role.presentationMessage())

        # TODO players description

        self.team = team
        self.listenServer()

    def send(self, message):
        message += '\n'
        size = len(message)
        sent = 0

        with self.lock:
            while sent < size:
                data = message[sent:]
                data = str(data)
                sent += self.socket.send(bytearray(str.encode(data)))

    def listenServer(self):
        data = b""
        self.running = True

        while self.running:
            data = self.socket.recv(0x1000)
            if not data:
                raise NetworkException("Connection lost !")
            self.inBuffer += data.decode("utf-8")
            while '\n' in self.inBuffer:
                (line, self.inBuffer) = self.inBuffer.split("\n", 1)
                self.recvPacket(line)
            

    def recvPacket(self, packet):
        if packet == Protocol.WELCOME:
            print("Connection established.")
        elif packet == Protocol.KICK:
            print("Server kicked me :(")
            self.running = False
        elif packet == Protocol.REBOOT:
            print("Server kicked me :(")
            self.running = False
        elif packet == Protocol.WIN:
            print("FUCKING SUCCEED !!!")
            self.running = False
        else:
            print(packet)
            

    def disconnect(self):
        self.socket.close()


    def create(host, port):
        instance = Client(host, port)
        return (instance)

    def access():
        return (instance)
