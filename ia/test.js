//
// test.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 14:34:12 2014 
// Last Update Tue Nov  4 14:59:11 2014 
//

function	King()
{
}

function	Soldier()
{
}

function	Ranger()
{
}

function	Slave()
{
}

King.prototype = new Class("king");
Soldier.prototype = new Class("soldier");
Ranger.prototype = new Class("ranger");
Slave.prototype = new Class("slave");

function	loadTeam(team)
{
    team.name = "yolo";
    team.wealth = 50;
    team.genetic_hardening = 100;
    team.skill_capacity = 100;

    team.classes = new Array
    team.classes[0] = new King;
    team.classes[1] = new Class("soldier");
    team.classes[2] = new Class("ranger");
    team.classes[3] = new Class("slave");

    team.players = new Array;
    team.players[0] = new Player("Boromir",	"king");
    team.players[1] = new Player("Gandalf",	"soldier");
    team.players[2] = new Player("Gimli",	"soldier");
    team.players[3] = new Player("Legolas",	"ranger");
    team.players[4] = new Player("Aragorn",	"ranger");
    team.players[5] = new Player("Frodon",	"slave");
    team.players[6] = new Player("Sam",		"slave");
    team.players[7] = new Player("Merry",	"slave");
    team.players[8] = new Player("Pipin",	"slave");
}
