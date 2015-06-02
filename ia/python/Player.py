#!/usr/bin/python3
## Player.py for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/python
## 
## Made by aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Wed Feb 25 09:38:51 2015 aracthor
## Last Update Wed Feb 25 13:48:43 2015 aracthor
##

import  copy
import  threading

class   PlayerThread(threading.Thread):
    def __init__(self, player, script):
        super().__init__()
        self.player = player
        self.script = script

    def run(self, client):
        self.script.start(client)


class   Player:
    def __init__(self, name, role):
        self.name = name
        self.role = role

    def setScript(self, script, client):
        self.script = copy.deepcopy(script)
        self.thread = PlayerThread(self, self.script)
        self.client = client


    def play(self):
        self.thread.run(self.client)

    def interrupt(self):
        self.script.stop()
