#!/bin/bash
## launch.sh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
## 
## Made by 
## Login   <aracthor@epitech.net>
## 
## Started on  Tue Dec  9 13:48:12 2014 
## Last Update Mon Jan 26 10:47:59 2015 aracthor
##

if (($# < 2))
then
    echo "Usage : $0 SCRIPT TEAM_NAME"
else
    rhino index.js -f $1 -n $2
fi
