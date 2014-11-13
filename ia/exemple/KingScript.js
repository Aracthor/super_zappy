//
// KingScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Thu Nov 13 16:01:35 2014 
//

function	KingCutTree()
{
    var bush = this.search(objects.bush);
    var items;
    var	i;

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

	this.displace(bush.position.x + i + 1, bush.position.y);
	this.put(items.id, 1);
    }
}

function	KingScript()
{
    this.cutTree = KingCutTree;
}

KingScript.prototype = new ZappyScript;

KingScript.prototype.play = function()
{
    print("Je suis un roi biatch");
    this.cutTree();
}
