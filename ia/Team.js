//
// Team.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 13:31:13 2014 
// Last Update Tue Nov  4 14:14:11 2014 
//

load("Class.js");
load("Exceptions.js");
load("Player.js");

function	Team(name)
{
    if (name.substr(name.length - 3, 3) != ".js")
    {
	name += ".js";
    }
    load(name);
    loadTeam(this);

    this.checkStats();

    this.population = this.players.length;
    this.versatility = this.classes.length;

    this.checkNames();
}


Team.prototype.checkStats = function()
{
    if (this.name == null ||
	this.players == null ||
	this.wealth == null ||
	this.classes == null ||
	this.genetic_hardening == null ||
	this.skill_capacity == null)
    {
	throw new ConfigException("Invalid config file");
    }
}

Team.prototype.classExist = function(name)
{
    var i;
    var	exist;

    exist = false;
    for (i = 0; exist == false && i < this.classes.length; ++i)
    {
	exist = (this.classes[i].name == name)
    }

    return (exist);
}

Team.prototype.checkPlayer = function(element)
{
    if (this.classExist(element.type) == false)
    {
	throw new ConfigException("Invalid player class : '" + element.type + "'");
    }
}

Team.prototype.checkNames = function()
{
    this.players.forEach(this.checkPlayer, this);
}
