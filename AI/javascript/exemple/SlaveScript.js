//
// SlaveScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Mon Jul 20 13:06:54 2015 Aracthor
//

function	SlaveScript()
{
}

SlaveScript.prototype = new ZappyScript;

SlaveScript.prototype.play = function()
{
    var bush
    var items;
    var destroyed;

    bush = search(g_objects.bush);
    if (bush == null)
    {
	print("Not found :(");
    }
    else
    {
	displace(bush.position.x, bush.position.y);
	destroy(bush.position.x, bush.position.y);
	displace(bush.position.x, bush.position.y);
	items = take();

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

	    item = dig();
	    if (item != null)
	    {
		print(item.id);
	    }
	}
    }
}
