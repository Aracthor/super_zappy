//
// Client.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 13:20:02 2014 
// Last Update Tue Nov  4 15:01:53 2014 
//

load("EAction.js");
load("ECommand.js");
load("Interpretor.js");

WELCOME_MESSAGE=	"WELCOME";
KICK_MESSAGE=		"GET THE FUCK OUT";

function	Client(host, port)
{
    this.socket = new java.net.Socket(host, port);
    this.input = this.socket.getInputStream();
    this.output = this.socket.getOutputStream();
    this.isr = new java.io.InputStreamReader(this.input);
    this.buffer = new java.io.BufferedReader(this.isr);

    this.interpretor = new Interpretor;

    this.commands = [];
    this.commands[ECommand.presentation] = this.interpretor.readServerPresentation;
};


Client.prototype.sendTeamDetails = function(team)
{
    var teamPresentation = (EAction.presentation + ' ' +
			    team.name + ' ' +
			    team.population + ' ' +
			    team.wealth + ' ' +
			    team.versatility + ' ' +
			    team.genetic_hardening + ' ' +
			    team.skill_capacity + ' ');
    var i;

    this.send("TEAM");
    this.send(teamPresentation);

    for (i = 0; i < team.classes.length; ++i)
    {
	this.send(team.classes[i].presentationMessage());
    }
    for (i = 0; i < team.players.length; ++i)
    {
	this.send(team.players[i].presentationMessage());
    }
}


Client.prototype.send = sync(function(message)
{
    var bytes = new Array(message.length);

    for (i = 0; i < message.length; ++i)
    {
	bytes[i] = message[i].charCodeAt(0);
    }
    bytes[message.length] = '\n'.charCodeAt(0);
    this.output.write(bytes);
    this.output.flush();
});

Client.prototype.recvPacket = function(packet)
{
    var	args;
    var	interpretation;

    if (packet == WELCOME_MESSAGE)
    {
	print("Connection established.");
    }
    else if (packet == KICK_MESSAGE)
    {
	print("\033[01;31mServer kicked me :(\033[0m");
	this.loop = false;
    }
    else
    {
	args = packet.split(' ');

	interpretation = this.commands[args[0]];
	if (interpretation == null)
	{
	    throw new Error("Invalid command " + args[0]);
	}
	interpretation(this, args);
    }
};

Client.prototype.listenServer = function()
{
    var line;

    try
    {
	this.loop = true;
	while (this.loop == true && (line = this.buffer.readLine()) != null)
	{
	    this.recvPacket(line);
	}
    }
    catch (error)
    {
	if (this.socket.isClosed() == false)
	{
	    throw new Error("Error parsing data : " + error.message);
	}
    }
    
    if (this.loop == true)
    {
	throw new Error("Connection lost !");
    }
};


Client.prototype.disconnect = function()
{
    this.socket.shutdownInput();
    this.socket.shutdownOutput();
    this.socket.close();
    this.input.close();
    this.output.close();
    this.buffer.close();
    this.isr.close();
};
