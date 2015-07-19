#!/usr/bin/python3
## Configs.py for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/python
## 
## Made by aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Tue Feb 24 09:37:58 2015 aracthor
## Last Update Tue Feb 24 12:24:33 2015 aracthor
##

from    Exceptions      import SyntaxException

class   Configs:
    DEFAULT_HOST = "localhost"
    DEFAULT_PORT = 4242

    def __init__(self, argc, argv):
        self.host = self.DEFAULT_HOST
        self.port = self.DEFAULT_PORT
        self.script = None
        self.name = None

        self.reader = None

        self.readers = {
            'p': self.changePort,
            'h': self.changeHost,
            'n': self.changeName,
            'f': self.changeScript
        }

        for arg in argv[1:]:
            self.readArg(arg)

        if self.script == None:
            raise SyntaxException("Please give a script (with -f)")
        if self.name == None:
            raise SyntaxException("Please give a name (with -n)")


    def readArg(self, arg):
        if (arg[0] == '-'):
            self.changeReader(arg[1])
        elif (self.reader == None):
            raise SyntaxException("missing flag before arg")
        else:
            self.reader(arg)

    def changeReader(self, flag):
        if flag not in self.readers:
            raise SyntaxException("unknow flag " + flag)
        self.reader = self.readers[flag]

    
    def changePort(self, port):
        self.port = port
    
    def changeHost(self, host):
        self.host = host
    
    def changeName(self, name):
        self.name = name
    
    def changeScript(self, script):
        self.script = script
