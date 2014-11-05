//
// CommandListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 08:39:41 2014 
// Last Update Tue Nov  4 14:17:34 2014 
//

#include "debug/LogManager.hh"
#include "network/listeners/CommandListener.hh"

#include <cstdarg>
#include <cstdio>
#include <cstring>

CommandListener::CommandListener() :
  m_commandId(0)
{
}

CommandListener::~CommandListener()
{
}


void
CommandListener::errorFromClient(const Client* client, const char* message, ...) const
{
  va_list	list;
  char		buffer[0x1000];

  va_start(list, message);
  {
    vsprintf(buffer, message, list);
    LogManagerSingleton::access()->error.print("Error from client %d : %s",
					       client->getFd(), buffer);
  }
  va_end(list);
}


bool
CommandListener::executeCommand(CommandExecution execution, Client* client, char* const*args)
{
  return ((this->*execution)(client, args));
}

bool
CommandListener::tryToExecuteCommand(Client* client,
				     const CommandCutter::CuttedLine& cuttedCommand,
				     const CommandListener::Command& command)
{
  bool	valid;

  valid = (command.argsNumber == cuttedCommand.argsNumber);
  if (valid == true)
    valid = this->executeCommand(command.execution, client, cuttedCommand.args);
  else
    LogManagerSingleton::access()->error.print("Bad args number for command %s.",
					       command.name);

  return (valid);
}

bool
CommandListener::searchAndExecuteCommand(Client* client,
					 const CommandCutter::CuttedLine& command)
{
  unsigned int	i;
  bool		found;
  bool		valid;

  found = false;
  valid = false;

  for (i = 0; found == false && i < m_commandId; ++i)
    {
      if (!strcmp(m_commands[i].name, command.args[0]))
	{
	  found = true;
	  valid = this->tryToExecuteCommand(client, command, m_commands[i]);
	}
    }

  if (found == false)
    LogManagerSingleton::access()->error.print("Command %s doesn't exist !", command.args[0]);

  return (valid);
}


bool
CommandListener::listenFromClient(Client* client, char* message)
{
  CommandCutter::CuttedLine	command;
  bool				valid;

  valid = this->cutInArgs(command, message);
  if (valid)
    valid = this->searchAndExecuteCommand(client, command);

  return (valid);
}
