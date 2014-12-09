//
// SlaveScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Tue Dec  9 12:34:57 2014 
//

function	HunterScript()
{
    this.javelins = 0;
}

HunterScript.prototype = new ZappyScript;

function	makeWeapons(player)
{
    var		bush
    var		items;

    bush = player.search(g_objects.bush);
    if (bush == null)
    {
	print("Not found :(");
    }

    else
    {
	if (player.displace(bush.position.x, bush.position.y) == true &&
	    player.destroy(bush.position.x, bush.position.y) == true &&
	    player.displace(bush.position.x, bush.position.y) == true)
	{
	    items = player.take();
	    if (items != null)
	    {
		for (var i = 0; i < items.number; ++i)
		{
		    player.craft(g_items.wooden_javelin);
		}
		player.javelins += items.number;
	    }
	    else
	    {
		print("SALAUD !");
	    }
	}
	else
	{
	    print("BLOQUED !");
	}
    }
}

function	hunt(player)
{
    var		ennemy;

    ennemy = player.locateEnnemy();
    if (ennemy == null)
    {
	print("Y'a personne putain !");
    }
    else
    {
	print("Je sais pas tirer putain !");
    }
}

HunterScript.prototype.play = function()
{
    while (42)
    {
	if (this.javelins < 5)
	{
	    makeWeapons(this);
	}
	else
	{
	    hunt(this);
	}
    }
}
