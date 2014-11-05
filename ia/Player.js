//
// Player.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 17:20:56 2014 
// Last Update Tue Nov  4 15:02:11 2014 
//

function	Player(name, type)
{
    this.name = name;
    this.type = type;
}

Player.prototype.presentationMessage = function()
{
    return (EAction.playerDescription + ' ' +
	    this.name + ' ' +
	    this.type);
}
