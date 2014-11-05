//
// main.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 12:25:22 2014 
// Last Update Mon Nov  3 17:27:57 2014 
//

load("Client.js");
load("Configs.js");
load("Team.js");

function	main(argc, argv)
{
    var		configs = new Configs(argc, argv);
    var		team = new Team(configs.name);
    var		client = new Client(configs.host, configs.port);

    client.sendTeamDetails(team);
    client.listenServer();
    client.disconnect();

    return (0);
}
