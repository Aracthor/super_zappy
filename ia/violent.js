//
// test.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 14:34:12 2014 
// Last Update Wed Dec 10 13:28:43 2014 
//

load("violent/HunterScript.js");

function	Hunter()
{
    this.script = new HunterScript;
    this.perception = 80;
    this.strength = 60;
    this.crafting = 1;
    this.shoot = 4;
}

Hunter.prototype = new Class("hunter");

function	loadTeam(team)
{
    team.wealth = 50;
    team.genetic_hardening = 160;
    team.skill_capacity = 50;

    team.classes = new Array
    team.classes[0] = new Hunter;

    team.players = new Array;
    team.players[0] = new Player("Hunter1",	"hunter");
    // team.players[1] = new Player("Hunter2",	"hunter");
    // team.players[2] = new Player("Hunter3",	"hunter");
    // team.players[3] = new Player("Hunter4",	"hunter");
    // team.players[4] = new Player("Hunter5",	"hunter");
}
