//
// Client.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 13:20:02 2014 
// Last Update Fri Nov 14 13:33:47 2014 
//

load("EAction.js");
load("ECommand.js");

WELCOME_MESSAGE=	"WELCOME";
KICK_MESSAGE=		"GET THE FUCK OUT";

function	Client(host, port)
{
    this.socket = new java.net.Socket(host, port);
    this.input = this.socket.getInputStream();
    this.output = this.socket.getOutputStream();
    this.isr = new java.io.InputStreamReader(this.input);
    this.buffer = new java.io.BufferedReader(this.isr);
};


Client.prototype.sendTeamDetails = function(team, name)
{
    var i;

    this.send("TEAM");
    this.send(team.presentationMessage(name));

    for (i = 0; i < team.classes.length; ++i)
    {
	this.send(team.classes[i].presentationMessage());
    }

    for (i = 0; i < team.players.length; ++i)
    {
    	team.players[i].play(team.players[i]);
    }

    this.team = team;
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

Client.prototype.interprete = function(packet)
{
    var	interpretation;
    var	args;

    interpretation = false;
    args = packet.split(' ');
    player = this.team.getPlayer(args[0]);
    if (player != null)
    {
	args.shift();
	player.script.sendMessage(args);
    }
    else
    {
	throw new Error("Unknow packet recipient player " + args[0]);
    }
}

Client.prototype.recvPacket = function(packet)
{
    if (packet == WELCOME_MESSAGE)
    {
	print("Connection established.");
    }
    else if (packet == KICK_MESSAGE)
    {
	throw new Error("Server kicked me :(");
	this.loop = false;
    }
    else
    {
	this.interprete(packet);
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
	    print("Error parsing data : " + error.message);
	    this.loop = false;
	}
    }
    
    if (this.loop == true)
    {
	print("Connection lost !");
    }
};


Client.prototype.interruptThreads = function()
{
    var	i;

    for (i = 0; i < this.team.players.length; ++i)
    {
    	this.team.players[i].interrupt();
    	this.team.players[i].thread.join();
    }
}


Client.prototype.disconnect = function()
{
    this.socket.shutdownInput();
    this.socket.shutdownOutput();
    this.socket.close();
    this.input.close();
    this.output.close();
    this.buffer.close();
    this.isr.close();
    this.interruptThreads();
};
