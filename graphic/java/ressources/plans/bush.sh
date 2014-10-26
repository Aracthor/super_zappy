#!/bin/bash
## saplin.sh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/graphic/java/ressources/plans
## 
## Made by 
## Login   <aracthor@epitech.net>
## 
## Started on  Sun Oct 26 02:25:51 2014 
## Last Update Sun Oct 26 04:13:30 2014 
##

function vertex
{
    echo v $1 $2 $3 | tr -d '~'
    echo vc $color1 $color2 $color3
}

echo -e "\n## Base"
pi=3.14159265359
color1=0.0
color2=0.5
color3=0.0

vertex 0 0 1.5

angle=0
color1=0.0
color2=0.5
color3=0.0
while (($angle < 360))
do
    x=$(calc "cos($angle * $pi / 180)")
    y=$(calc "sin($angle * $pi / 180)")
    vertex $(calc "$x / 2") $(calc "$y / 2") -0.5
    vertex $(calc "$x / 4") $(calc "$y / 4") 1.0
    angle=$(($angle + 20))
done

i=1
while (($i < 35))
do
    echo f $(($i + 0)) $(($i + 1)) $(($i + 2))
    echo f $(($i + 3)) $(($i + 1)) $(($i + 2))
    echo f $(($i + 3)) $(($i + 1)) 0
    ((i += 2))
done
echo f $(($i + 0)) $(($i + 1)) 1
echo f 2 $(($i + 1)) 1
echo f 2 $(($i + 1)) 0
