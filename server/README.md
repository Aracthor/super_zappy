# Server

Core of the game, it coordonne graphic and AI clients.

## Compilation & installation

### Requirements

You must have SFML 2.X installed. (I use 2D vector class for calculs. I shouldn't.)

    sudo apt-get install libsfml-dev

I use ncurses library for server console. If you don't have it, install it the same way:

    sudo apt-get install libncurses-dev

### Compilation

From here, compile the server with this simple command:

    make

Your binary will be ready in the `bin` folder.

## Launch the server

The server need the folder `configurations` and everything inside in order to work.  
As it is not possible to give configurations folder path in arguments, you have to launch the server from its root folder. So precisely when you were when you compiled it.
There are several arguments possible to add, in order that you want:

 - **-n** *team1 team2 {teams}*: The only mandatory one. You'll have to give at least two teams names for your game.
 - **-d**: optional, but strongly recommanded. It will active the console mode for your server. Without it, you won't be able to start the game.
 - **-x** *width*: set island width. Values are from 4 to 256. Default value is **4**.
 - **-y** *height*: set island height. Values are from 4 to 256. Default value is **4**.
 - **-p** *port*: set server port. Default value is **4242**.
 - **-s** *speed*: set execution speed, which is microseconds number between each cycle. So the lower you set, the faster it will be. Values are from 1000 to 10000000. Default value is **10000**.
 - **-l** *log_file*: set log file path, which is the file where every log shall be recorded. Default file is **./zappy.log**.
 - **-g** *seed*: set random seed for island generation. Wihtout explicit value, it would be generated from unix time and process ID.

So here is a simple server launch with minimal configuration:

    ./bin/server -n foo bar -d

## Server execution

You should have a server running into a terminal, with an empty client list on your left, an almost empty log box on your right, and a prompt waiting for instructions at bottom.

You can switch between lists on your left with **Ctrl+right** and **Ctrl+left**.  
It will show you lists of connected clients, available teams, present players and debug logs. We will come back on this last point later.

### Logs

Logs are different stream of messages that are only usefull on a debug way. However, it still can be a good way to understand what is hapenning on the server just watching the console.  
The log list and their color codes are on one of the lists on your left, accessible with **Ctrl+right** and **Ctrl+left**.  
On this list, you can see some of them are *on*, and some others *off*. Those that are *off* won't print their debug outputs, as well in console as in log file.  
You can choose which log is active or unactive with commands, as explained below.

### Commands

In console mode, there are several commands that you can use:

 - **start**: start the game.
 - **stop**: pause the game. The next start will restart the game at paused point.
 - **reset**: cancel and reboot the game.
 - **rebuild**: make new island.
 - **rebuild** *X Y*: make new island with *X* width and *Y* height.
 - **speed** *speed*: change speed to *speed* parameter. As speed gave in arguments, it must be between 1000 and 10000000.
 - **log** *name* **active**: turn on log *name*.
 - **log** *name* **disactive**: turn off log *name*.

### Test it

Start a simple server as explained in the `Launch the server` part, and go to the [graphic folder readme file](../graphic/java/README.md) to the next part.
