//
// Configs.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 13:29:59 2014 
// Last Update Tue Nov  4 14:07:32 2014 
//

DEFAULT_HOST	= "127.0.0.1";
DEFAULT_PORT	= 4242;

function	Configs(argc, argv)
{
    this.host = DEFAULT_HOST;
    this.port = DEFAULT_PORT;
    this.name = null;

    this.reader = null;

    for (i = 1; i < argc; ++i)
    {
	this.readArg(argv[i]);
    }

    if (this.name == null)
    {
	throw new SyntaxError("Please give a team name. (with -f)");
    }
}


Configs.prototype.changePort = function(port)
{
    this.port = Number(port);
}

Configs.prototype.changeHost = function(host)
{
    this.host = host;
}

Configs.prototype.changeTeamName = function(name)
{
    if (this.name != null)
    {
	throw new SyntaxError("Please give only one team name.");
    }
    this.name = name;
}


Configs.prototype.readArg = function(arg)
{
    if (arg[0] == '-')
    {
	this.changeReader(arg[1]);
    }
    else if (this.reader == null)
    {
	throw new SyntaxError("Syntax error : missing flag before arg");
    }
    else
    {
	this.reader(arg);
    }
}

Configs.prototype.changeReader = function(flag)
{
    if (flag == 'p')
    {
	this.reader = this.changePort;
    }
    else if (flag == 'h')
    {
	this.reader = this.changeHost;
    }
    else if (flag == 'f')
    {
	this.reader = this.changeTeamName;
    }
    else
    {
	throw new SyntaxError("Syntax error : unknow flag " + flag);
    }
}
