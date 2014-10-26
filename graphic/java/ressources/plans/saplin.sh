#!/bin/bash
## saplin.sh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/graphic/java/ressources/plans
## 
## Made by 
## Login   <aracthor@epitech.net>
## 
## Started on  Sun Oct 26 02:25:51 2014 
## Last Update Sun Oct 26 03:28:00 2014 
##

function vertex
{
    echo v $1 $2 $3 | tr -d '~'
    echo vc $color1 $color2 $color3
}

echo -e "\n## Base"
pi=3.14159265359
color1=0.0
color2=0.3
color3=0.0

vertex 0 0 1
vertex 0 0 5

# Trunc
angle=0
color1=0.4
color2=0.2
color3=0.0
while (($angle < 360))
do
    x=$(calc "cos($angle * $pi / 180)")
    y=$(calc "sin($angle * $pi / 180)")
    vertex $(calc "$x / 4") $(calc "$y / 4") -0.5
    vertex $(calc "$x / 4") $(calc "$y / 4") 1
    angle=$(($angle + 20))
done

# Leaves
angle=0
color1=0.0
color2=0.3
color3=0.0
while (($angle < 360))
do
    x=$(calc "cos($angle * $pi / 180)")
    y=$(calc "sin($angle * $pi / 180)")
    vertex $(calc "$x / 2") $(calc "$y / 2") 1
    angle=$(($angle + 20))
done

echo -e "\n## Trunc"
i=2
while (($i < 36))
do
    echo f $(($i + 0)) $(($i + 1)) $(($i + 2))
    echo f $(($i + 3)) $(($i + 1)) $(($i + 2))
    ((i += 2))
done
echo f $(($i + 0)) $(($i + 1)) 2
echo f 3 $(($i + 1)) 2
((i += 2))

echo -e "\n## Leaves"
while (($i < 54))
do
    # echo f $(($i + 0)) $(($i + 1)) 0
    echo f $(($i + 0)) $(($i + 1)) 1
    ((i += 1))
done
# echo f $(($i + 0)) 39 0
echo f $(($i + 0)) 39 1
