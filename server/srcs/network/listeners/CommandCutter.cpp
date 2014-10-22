//
// CommandCutter.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 21 12:25:28 2014 
// Last Update Tue Oct 21 12:36:08 2014 
//

#include "debug/LogManager.hh"
#include "network/listeners/CommandCutter.hh"

#include <cstring>

CommandCutter::CommandCutter()
{
}

CommandCutter::~CommandCutter()
{
}


bool
CommandCutter::cutInArgs(CommandCutter::CuttedLine& cuttedLine, char* line)
{
  char*	arg;
  bool	valid;

  cuttedLine.args[0] = strtok(line, GRAPHIC_ARGS_SEPARATOR);
  cuttedLine.argsNumber = 1;
  valid = true;

  while (valid && (arg = strtok(NULL, GRAPHIC_ARGS_SEPARATOR)) != NULL)
    {
      if (cuttedLine.argsNumber == GRAPHIC_MAX_ARGS_NUMBER)
	{
	  LogManagerSingleton::access()->error.print("Too many args !");
	  valid = false;
	}
      else
	{
	  cuttedLine.args[cuttedLine.argsNumber] = arg;
	  ++cuttedLine.argsNumber;
	}
    }

  return (valid);
}
