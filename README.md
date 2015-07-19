# Super Zappy

The initial goal of this project is to provide a programming game, with teams of AI executing a script on a generated island to achieve as quicly as possible a goal, like destroy every other team.

AIs would have different actions and capabilities, that could be chose at start of the game. They would be able to dig, destroy objects like trees, pick or put items, use them to craft other items or build something on the ground, etc.

**This project is abandonned.** Because there are too many network bugs on server side, but mainly because of complicated personal reasons.  
But there is still some functional parts.

The actual project is composed of:

 - A C++ server that generate an island, and manage game loop.
 - A Java graphic client that can show the island and the action on it.
 - A JavaScript AI client that can execute some actions on different players in the same team.

All those parts have their own readme file. I suggest you to start by the server one.
