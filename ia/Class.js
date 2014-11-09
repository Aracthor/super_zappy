//
// Class.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 17:58:53 2014 
// Last Update Thu Nov  6 19:06:20 2014 
//

load("EAction.js");

function	Class(name)
{
    this.name = name;

    this.strength = 10;
    this.perception = 0;
    this.dexterity = 10;
    this.toughness = 10;
    this.intuition = 0;
    this.speed = 1;
    this.orientation = 1;
}

Class.prototype.presentationMessage = function()
{
    return (EAction.classDescription + ' ' +
	    this.name + ' ' +
	    this.strength + ' ' +
	    this.perception + ' ' +
	    this.dexterity + ' ' +
	    this.toughness + ' ' +
	    this.intuition + ' ' +
	    this.speed + ' ' +
	    this.orientation
	   );
}
