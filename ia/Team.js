//
// Team.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 13:31:13 2014 
// Last Update Tue Dec 16 10:48:56 2014 
//

load("Class.js");
load("Exceptions.js");
load("Player.js");
load("ZappyScript.js");

function	Team(name)
{
    this.classes = new Array;
    this.players = new Array;
    this.wealth = 0;
    this.genetic_hardening = 0;
    this.skill_capacity = 0;

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
    if (this.players == null ||
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
    var	classRef;

    classRef = null;
    for (i = 0; classRef == null && i < this.classes.length; ++i)
    {
	if (this.classes[i].name == name)
	{
	    classRef = this.classes[i];
	}
    }

    return (classRef);
}

Team.prototype.checkPlayer = function(element)
{
    var classRef = this.classExist(element.type);
    if (classRef == null)
    {
	throw new ConfigException("Invalid player class : '" + element.type + "'");
    }
    else
    {
	element.setScript(classRef.script);
    }
}

Team.prototype.checkNames = function()
{
    this.players.forEach(this.checkPlayer, this);
}

Team.prototype.getPlayer = function(name)
{
    var i;
    var	player;

    player = null;
    for (i = 0; player == null && i < this.players.length; ++i)
    {
	if (this.players[i].name == name)
	{
	    player = this.players[i];
	}
    }

    return (player);
}


Team.prototype.presentationMessage = function(name)
{
    return (EAction.presentation + ' ' +
	    name + ' ' +
	    this.population + ' ' +
	    this.wealth + ' ' +
	    this.versatility + ' ' +
	    this.genetic_hardening + ' ' +
	    this.skill_capacity + ' ');
}
