//
// SlaveScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Fri Nov 14 18:02:24 2014 
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

    bush = this.search(g_objects.bush);
    if (bush == null)
    {
	print("Not found :(");
    }
    else
    {
	this.displace(bush.position.x, bush.position.y);
	this.destroy(bush.position.x, bush.position.y);
	this.displace(bush.position.x, bush.position.y);
	items = this.take();

	if (items == null)
	{
	    this.sendMail("SALAUD !!!");
	}
	else
	{
	    this.displace(bush.position.x + 3, bush.position.y);
	    this.craft(g_items.wooden_javelin);
	    this.equip(g_items.wooden_javelin);
	    this.sendMail("J'ai !");
	    item = this.dig();
	    if (item != null)
	    {
		print(item.id);
	    }
	}
    }
}
