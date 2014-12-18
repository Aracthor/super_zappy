//
// SlaveScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Wed Dec 17 12:57:09 2014 
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
	print(this.player.name + ' ' + "Found ! 1");
	displace(bush.position.x, bush.position.y);
	print(this.player.name + ' ' + "Found ! 2");
	destroy(bush.position.x, bush.position.y);
	print(this.player.name + ' ' + "Found ! 3");
	displace(bush.position.x, bush.position.y);
	print(this.player.name + ' ' + "Found ! 4");
	items = take();
	print(this.player.name + ' ' + "Found ! 5");

	if (items == null)
	{
	    sendMail("SALAUD !!!");
	}
	else
	{
	    displace(bush.position.x + 3, bush.position.y);
	    craft(g_items.wooden_javelin);
	    equip(g_items.wooden_javelin);
	    sendMail("J'ai !");
	    item = dig();
	    if (item != null)
	    {
		print(item.id);
	    }
	}
    }
}
