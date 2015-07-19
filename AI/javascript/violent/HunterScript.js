//
// SlaveScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Tue Dec 16 11:03:44 2014 
//

function	HunterScript()
{
}

HunterScript.prototype = new ZappyScript;

function	makeWeapons(javelins)
{
    var		bush
    var		items;

    bush = search(g_objects.bush);
    if (bush == null)
    {
	print("Not found :(");
    }

    else
    {
	if (displace(bush.position.x, bush.position.y) == true &&
	    destroy(bush.position.x, bush.position.y) == true &&
	    displace(bush.position.x, bush.position.y) == true)
	{
	    items = take();
	    if (items != null)
	    {
		for (var i = 0; i < items.number; ++i)
		{
		    craft(g_items.wooden_javelin);
		}
		javelins += items.number;
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

    return (javelins);
}

function	hunt(javelins)
{
    var		ennemy;
    var		hit;

    ennemy = locateEnnemy();
    if (ennemy == null)
    {
	print("Y'a personne putain !");
    }
    else
    {
	equip(g_items.wooden_javelin);
	hit = attack(ennemy.position.x, ennemy.position.y);
	--javelins;
	if (hit)
	{
	    print("TOUCHE !");
	}
	else
	{
	    print("ET MERDEUH ! RATE !");
	}
    }

    return (javelins);
}

HunterScript.prototype.play = function()
{
    var	javelins;

    javelins = 0;
    while (42)
    {
	if (javelins < 5)
	{
	    javelins = makeWeapons(javelins);
	}
	else
	{
	    javelins = hunt(javelins);
	}
    }
}
