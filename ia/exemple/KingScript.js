//
// KingScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Sun Nov  9 08:50:15 2014 
//

function	KingCutTree()
{
    var bush = this.search(objects.bush);

    if (bush == null)
    {
	print("Not found :(");
    }
    else
    {
	print(bush.position.x + ", " + bush.position.y);
	this.displace(bush.position.x, bush.position.y);
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

