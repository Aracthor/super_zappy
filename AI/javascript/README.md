# Scripted AI

## Installation

The AI is executed by Rhino. If you don't have it, you can install it by typing:

    sudo apt-get install rhino

## Launch

Open two terminals to launch the script two times.

    ./launch.sh exemple toto
    ./launsh.sh violent titi

Then use *start* server command, to watch the script work.  
Re-run it using *speed* server command to slow down the game and understand better how it works.

## Code explanations

Take a look at `exemple` code. The most interesting is the `exemple/SlaveScript.js` part.

### Research

The first part looks like this:

    bush = search(g_objects.bush);
    if (bush == null)
    {
	    print("Not found :(");
    }
	else
	{
	    [...]
	}

The `search` function take as parameter an enum corresponding to the object to search, here a bush. It returns null if no corresponding object was found on player field of view, else a corresponding data on found object.  
So the first thing to do with this return value is to check for a null return value, which means nothing around. else we can execute next part.

### Movement and gathering

	displace(bush.position.x, bush.position.y);
	destroy(bush.position.x, bush.position.y);
	displace(bush.position.x, bush.position.y);
	items = take();

Those four code lines are four players actions:

 - Move as close as possible to bush position. Logically on border.
 - Punch it to destruction. It makes its tile free to move on and drop some items on it.
 - Move precisely on tile where bush was. This movement is only one tile long.
 - Take any items droped by bush destruction.

Note that normaly, those function should all have their return values checked, as we did for `search`. It didn't to make code easier to read, but this is not a good sample.

### Communication and crafting

	if (items == null)
	{
	    sendMail("BASTARD !!!");
	}
	else
	{
	    displace(bush.position.x + 3, bush.position.y);
	    craft(g_items.wooden_javelin);
	    equip(g_items.wooden_javelin);
	    sendMail("I got !");

        [...]
	}

As we did for `search` function, the first thing to do with `take` function is to check for a null return value.  
In that case, as a bush shall obviously drop some items on destruction, the only possible explanation to not got something is that someone saw the same bush than you, and desctructed/picked items before you. So in that case, the following line:

    sendMail("BASTARD !!!");

Is designed to insult the one who stole your items. Unhofully, when you yield something, everyone shall hear you. Even your friends. But it is a detail.

However, if you got it, you execute next actions:

    displace(bush.position.x + 3, bush.position.y);
    craft(g_items.wooden_javelin);
    equip(g_items.wooden_javelin);
    sendMail("I got !");

First, we move three tiles on the left. This worth nothing in utility.  
Then, we use the `craft` command to create a *wooden javelin*. It is possible only if we have necessary amount of sticks in player's inventory, but if you just picked items from a bush destruction, you should have some ones.  
And finally, equip the created javelin and tell to everyone that you have it.

Once again, those functions return booleans to indicate their success, so we should have checked them.

### Digging

It works as the `search` or `take` functions work. You will gather an item from the tile type where you are located.

    item = dig();
    if (item != null)
    {
        print(item.id);
    }

### Listen friends

You could notice that this script sometimes yield messages, but never listen what other could say. If you want an exemple of listening or wait for instruction, the file `exemple/KingScript.js` should answer to your questions.
