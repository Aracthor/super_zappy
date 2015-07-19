#!/usr/bin/python3
## ZappyException.py for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/python
## 
## Made by aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Tue Feb 24 10:09:53 2015 aracthor
## Last Update Tue Feb 24 12:22:56 2015 aracthor
##

class   ZappyException(Exception):
    def __init__(self, message):
        super().__init__()
        self.message = message

    def what(self):
        return (self.prefix + " error: " + self.message)


class   ConfigException(ZappyException):
    def __init__(self, message):
        super().__init__(message)
        self.prefix = "Config"

class   NetworkException(ZappyException):
    def __init__(self, message):
        super().__init__(message)
        self.prefix = "Network"

class   SyntaxException(ZappyException):
    def __init__(self, message):
        super().__init__(message)
        self.prefix = "Syntax"
