#!/usr/bin/python3
## Class.py for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/python
## 
## Made by aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Wed Feb 25 09:13:41 2015 aracthor
## Last Update Wed Feb 25 09:20:14 2015 aracthor
##

from    Enums   import EAction

class   Class:
    def __init__(self, name):
        self.name = name

        self.strength = 10
        self.perception = 0
        self.dexterity = 10
        self.toughness = 10
        self.intuition = 0

        self.speed = 1
        self.orientation = 1
        self.crafting = 0
        self.building = 0
        self.shoot = 0


    def presentationMessage(self):
        return (EAction.CLASS_DESCRIPTION + ' ' +
                self.name + ' ' +
                str(self.strength) + ' ' +
                str(self.perception) + ' ' +
                str(self.dexterity) + ' ' +
                str(self.toughness) + ' ' +
                str(self.intuition) + ' ' +
                str(self.speed) + ' ' +
                str(self.orientation) + ' ' +
                str(self.crafting) + ' ' +
                str(self.building) + ' ' +
                str(self.shoot)
        )
