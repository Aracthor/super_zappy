#!/usr/bin/python3
## Team.py for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/python
## 
## Made by aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Tue Feb 24 10:55:09 2015 aracthor
## Last Update Wed Feb 25 09:18:16 2015 aracthor
##

import  importlib

from    Enums           import EAction
from    Exceptions      import ConfigException

class   Team:
    def __init__(self, name):
        self.classes = []
        self.players = []
        self.wealth = 0
        self.geneticHardening = 0
        self.skillCapacity = 0

        # if name[-3:] != ".py":
        #     name += ".py"

        name = name.title()
        module = importlib.import_module(name)
        module.loadTeam(self)

        self.checkStats()

        self.population = len(self.players)
        self.versatility = len(self.classes)

        self.checkNames()


    def checkStats(self):
        if (self.players == None or
            self.wealth == None or
            self.classes == None or
            self.geneticHardening == None or
            self.skillCapacity == None):
            raise ConfigException("missing mandatory team elements")

    def classExist(self, name):
        searched = None
        for role in self.classes:
            if role.name == name:
                searched = role

        return (searched)


    def checkPlayer(self, player):
        role = self.classExist(player.role)
        if role == None:
            raise ConfigException("Invalid class: '" + player.role + "' for player '" + player.name + "'")

    def checkNames(self):
        for player in self.players:
            self.checkPlayer(player)


    def presentationMessage(self, name):
        return (EAction.PRESENTATION + ' ' +
                name + ' ' +
                str(self.population) + ' ' +
                str(self.wealth) + ' ' +
                str(self.versatility) + ' ' +
                str(self.geneticHardening) + ' ' +
                str(self.skillCapacity)
        )
