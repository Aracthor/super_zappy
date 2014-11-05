//
// CommandListener.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 08:48:14 2014 
// Last Update Mon Nov  3 14:09:07 2014 
//

template <class T>
void
CommandListener::initCommand(const char* name, unsigned int argsNumber,
			     bool (T::*command)(Client* client, char* const* args))
{
  m_commands[m_commandId].name = name;
  m_commands[m_commandId].argsNumber = argsNumber;
  m_commands[m_commandId].execution = reinterpret_cast<CommandExecution>(command);
  ++m_commandId;
}

template <class T>
void
CommandListener::initCommand(const char* name, unsigned int argsNumber,
			     bool (T::*command)(Client* client, char* const* args) const)
{
  m_commands[m_commandId].name = name;
  m_commands[m_commandId].argsNumber = argsNumber;
  m_commands[m_commandId].execution = reinterpret_cast<CommandExecution>(command);
  ++m_commandId;
}
