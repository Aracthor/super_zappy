//
// Configs.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 13:29:59 2014 
// Last Update Sat Nov  8 19:12:11 2014 
//

DEFAULT_HOST	= "127.0.0.1";
DEFAULT_PORT	= 4242;

function	Configs(argc, argv)
{
    this.host = DEFAULT_HOST;
    this.port = DEFAULT_PORT;
    this.script = null;
    this.name = null;

    this.reader = null;

    for (i = 1; i < argc; ++i)
    {
	this.readArg(argv[i]);
    }

    if (this.script == null)
    {
	throw new SyntaxException("Please give a script. (with -f)");
    }
    if (this.name == null)
    {
	throw new SyntaxException("Please give a name. (with -n)");
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
    this.name = name;
}

Configs.prototype.changeScript = function(script)
{
    this.script = script;
}


Configs.prototype.readArg = function(arg)
{
    if (arg[0] == '-')
    {
	this.changeReader(arg[1]);
    }
    else if (this.reader == null)
    {
	throw new SyntaxException("Syntax error : missing flag before arg");
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
    else if (flag == 'n')
    {
	this.reader = this.changeTeamName;
    }
    else if (flag == 'f')
    {
	this.reader = this.changeScript;
    }
    else
    {
	throw new SyntaxException("Syntax error : unknow flag " + flag);
    }
}
