##
## README.txt for super_zappy in /home/aracthor/programs/projects/hub/super_zappy
## 
## Made by 
## Login   <aracthor@epitech.net>
## 
## Started on  Sat Oct  4 19:38:33 2014 
## Last Update Mon Jun  8 09:55:31 2015 Aracthor
##

SERVER:

You must have SFML installed. (I use 2D vector class for calcs. I shouldn't.)
sudo apt-get install libsfml-dev

Go into the server folder.
./bin/server -d -n toto titi -x 10 -y 10

commands:
start: start the game
reset: stop the game
rebuild: make new island
rebuid X Y: make new island with X width and Y height



GRAPHIC:
I use Eclipse to launch it.
Switch to workspace super_zappy. Go into graphic/java/src/Main/GraphicClient.java and try to launch application.
If an error message "Invalid arguments" appear, go into "run configurations", "arguments" and set them to "localhost 4242".
If it cannot reach LWJGL, good luck with native locations library in build path.



IA:
Use javascript version.
Go into the ia/javascript folder in two terminals.
./launch.sh exemple toto
./launsh.sh violent titi
Don't forget to use "start" command on server side, they won't move else.
