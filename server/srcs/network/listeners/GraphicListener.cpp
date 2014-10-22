//
// GraphicListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Wed Oct 22 12:40:18 2014 
//

#include "debug/LogManager.hh"
#include "network/listeners/GraphicListener.hh"

#include <cstring>

GraphicListener::GraphicListener()
{
  this->initCommand( 0, "CHK", 3, &GraphicMessages::sendChunkData);
  this->initCommand( 1, "CAS", 3, &GraphicMessages::sendHooplaData);
  this->initCommand( 2, "PDC", 2, NULL);
  this->initCommand( 3, "TDC", 2, NULL);
}

GraphicListener::~GraphicListener()
{
}


void
GraphicListener::initCommand(unsigned int id,
			     const char* name, unsigned int argsNumber,
			     GraphicListener::CommandExecution execution)
{
  m_commands[id].name = name;
  m_commands[id].argsNumber = argsNumber;
  m_commands[id].execution = execution;
}


bool
GraphicListener::executeCommand(Client* client,
				const CommandCutter::CuttedLine& cuttedCommand,
				const GraphicListener::Command& command)
{
  bool	valid;

  valid = (command.argsNumber == cuttedCommand.argsNumber);
  if (valid == true)
    valid = (this->*command.execution)(client, cuttedCommand.args);
  else
    LogManagerSingleton::access()->error.print("Bad args number for command %s.",
					       command.name);

  return (valid);
}

bool
GraphicListener::searchAndExecuteCommand(Client* client,
					 const CommandCutter::CuttedLine& command)
{
  unsigned int	i;
  bool		found;
  bool		valid;

  found = false;
  valid = false;

  for (i = 0; found == false && i < GRAPHIC_COMMANDS_NUMBER; ++i)
    {
      if (!strcmp(m_commands[i].name, command.args[0]))
	{
	  found = true;
	  valid = this->executeCommand(client, command, m_commands[i]);
	}
    }

  if (found == false)
    LogManagerSingleton::access()->error.print("Command %s doesn't exist !", command.args[0]);

  return (valid);
}


bool
GraphicListener::listenFromClient(Client* client, char* message)
{
  CommandCutter::CuttedLine	command;
  bool				valid;

  valid = this->cutInArgs(command, message);
  if (valid)
    valid = this->searchAndExecuteCommand(client, command);

  return (valid);
}
