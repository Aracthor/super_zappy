//
// test.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 14:34:12 2014 
// Last Update Sun Nov  9 08:50:09 2014 
//

load("exemple/KingScript.js");
load("exemple/SoldierScript.js");
load("exemple/RangerScript.js");
load("exemple/SlaveScript.js");

function	King()
{
    this.script = new KingScript;
    this.perception = 50;
}

function	Soldier()
{
    this.script = new SoldierScript;
}

function	Ranger()
{
    this.script = new RangerScript;
}

function	Slave()
{
    this.script = new SlaveScript;
}

King.prototype = new Class("king");
Soldier.prototype = new Class("soldier");
Ranger.prototype = new Class("ranger");
Slave.prototype = new Class("slave");

function	loadTeam(team)
{
    team.wealth = 50;
    team.genetic_hardening = 100;
    team.skill_capacity = 100;

    team.classes = new Array
    team.classes[0] = new King;
    team.classes[1] = new Soldier;
    team.classes[2] = new Ranger;
    team.classes[3] = new Slave;

    team.players = new Array;
    team.players[0] = new Player("Boromir",	"king");
    // team.players[1] = new Player("Gandalf",	"soldier");
    // team.players[2] = new Player("Gimli",	"soldier");
    // team.players[3] = new Player("Legolas",	"ranger");
    // team.players[4] = new Player("Aragorn",	"ranger");
    // team.players[5] = new Player("Frodon",	"slave");
    // team.players[6] = new Player("Sam",		"slave");
    // team.players[7] = new Player("Merry",	"slave");
    // team.players[8] = new Player("Pipin",	"slave");
}
