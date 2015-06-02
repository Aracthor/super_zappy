#!/usr/bin/python3
## exemple.py for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/python
## 
## Made by aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Tue Feb 24 10:58:10 2015 aracthor
## Last Update Wed Feb 25 09:38:38 2015 aracthor
##

from    Class   import Class
from    Player  import Player

class   King(Class):
    def __init__(self):
        super().__init__("king")
        self.perception = 80
        self.script = 0 # TODO

class   Soldier(Class):
    def __init__(self):
        super().__init__("soldier")
        self.script = 0 # TODO

class   Ranger(Class):
    def __init__(self):
        super().__init__("ranger")
        self.script = 0 # TODO

class   Slave(Class):
    def __init__(self):
        super().__init__("slave")
        self.perception = 50
        self.strength = 30
        self.script = 0 # TODO

def     loadTeam(team):
    team.wealth = 50
    team.geneticHardening = 100
    team.skillCapcity = 100
    
    team.classes = [King(),
                    Soldier(),
                    Ranger(),
                    Slave()
    ]

    team.players = [Player("Boromir",	"king"),
                    Player("Frodon",	"slave"),
                    Player("Sam",	"slave"),
                    Player("Merry",	"slave"),
                    Player("Pipin",	"slave")
    ]
