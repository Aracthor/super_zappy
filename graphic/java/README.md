I use Eclipse to launch it.

Switch to workspace super_zappy. Go to graphic/java/src/Main/GraphicClient.java and try to launch application.

If an error message "Invalid arguments" appear, go into "run configurations", "arguments" and set them to "localhost 4242".  
If it cannot reach LWJGL, good luck with native locations library in build path.
