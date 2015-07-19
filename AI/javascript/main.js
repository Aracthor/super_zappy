//
// main.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 12:25:22 2014 
// Last Update Tue Feb 24 09:27:14 2015 aracthor
//

load("Client.js");
load("Configs.js");
load("Team.js");
load("Utils.js");

var		client;

function	main(argc, argv)
{
    var		configs = new Configs(argc, argv);
    var		team = new Team(configs.script);

    client = new Client(configs.host, configs.port);

    client.sendTeamDetails(team, configs.name);
    client.listenServer();
    client.disconnect();

    return (0);
}
