//
// Exceptions.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 14:36:36 2014 
// Last Update Sat Nov  8 20:38:27 2014 
//

USAGE =	"\nUsage : " + arguments[0] + " -f file -n name [-h host] [-p port]";

function	Exception()
{
}


function	ConfigException(message)
{
    this.message = message;
}


function	SyntaxException(message)
{
    this.message = message;
    this.message += USAGE;
}

SyntaxException.prototype = new Exception;

ConfigException.prototype = new Exception;
