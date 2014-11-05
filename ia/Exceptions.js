//
// Exceptions.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 14:36:36 2014 
// Last Update Mon Nov  3 14:37:25 2014 
//

function	Exception(message)
{
    this.message = message;
}


function	ConfigException(message)
{
    Exception.call(this, message);
}

function	SyntaxException(message)
{
    Exception.call(this, message);
}
