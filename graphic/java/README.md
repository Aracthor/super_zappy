# Graphic client

## Launch

I use Eclipse to launch it.

Switch to workspace super_zappy. Go to graphic/java/src/Main/GraphicClient.java and try to launch application.

If an error message "Invalid arguments" appear, go into "run configurations", "arguments" and set them to "localhost 4242".  
If it cannot reach LWJGL, good luck with native locations library in build path.

## Commands

There is an incomplete 2D mode and a complete 3D mode. The 2D mode does not include anything but island view, you won't be able to see players or items.  
You can switch between them with **F4** key.

### 2D mode commands

You can move the camera postion with **arrow keys**.  
You can zoom or unzoom with **W** and **S** keys.

Note that if you zoom to a certain position, some (ugly) vignettes shall appear to indicate tile objects.

### 3D mode commands

You can move the camera with **up and down arrows**.
You can turn the camera with **right and left arrows**.  

## Tests

If you succeed to display an island with it, I suggest you to use and abuse of *rebuild* server command to see many islands. This is definitly the funnest part of this project, because players gameplay is incomplete.

Once you launched it, see you on the [AI client readme](../../AI/javascript/README.md) for the last - and incomplete - part.
