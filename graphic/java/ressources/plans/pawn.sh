#!/bin/bash
## test.sh for lemIPC in /home/bonnet_v/programs/projects/system_unix/lemIPC
## 
## Made by Bonnet Vivien
## Login   <bonnet_v@epitech.net>
## 
## Started on  Tue Mar 18 17:34:14 2014 Bonnet Vivien
## Last Update Fri Nov  7 12:52:40 2014 
##

function	vertice
{
    echo v $1 $2 $3 | tr -d '~'
}

pi=3.14159265359
angle=0
while (($angle < 360))
do
    x=$(calc "cos($angle * $pi / 180)")
    y=$(calc "cos(($angle + 90) * $pi / 180)")
    vertice $(calc "$x / 2") $(calc "$y / 2") 0
    vertice $(calc "$x / 4") $(calc "$y / 4") 1.5
    vertice $(calc "$x * 3 / 8") $(calc "$y * 3 / 8") 2
    vertice $(calc "$x * 5 / 16") $(calc "$y * 5 / 16") 2.5
    ((angle += 20))
done
echo v 0 0 3

f=0
while (($f < 68))
do
    echo f $(($f + 0)) $(($f + 1)) $(($f + 5))
    echo f $(($f + 0)) $(($f + 5)) $(($f + 4))
    echo f $(($f + 1)) $(($f + 2)) $(($f + 6))
    echo f $(($f + 1)) $(($f + 6)) $(($f + 5))
    echo f $(($f + 2)) $(($f + 3)) $(($f + 7))
    echo f $(($f + 2)) $(($f + 7)) $(($f + 6))
    echo f $(($f + 3)) $((72)) $(($f + 7))
    ((f += 4))
done

echo f $(($f + 0)) $(($f + 1)) 1
echo f $(($f + 0)) 1 0
echo f $(($f + 1)) $(($f + 2)) 2
echo f $(($f + 1)) 2 1
echo f $(($f + 2)) $(($f + 3)) 3
echo f $(($f + 2)) 3 2
echo f $(($f + 3)) 72 3


#Arrow
echo v 2 0 1
echo v 1.5 0.5 1
echo v 1.5 -0.5 1

echo f 73 74 75
