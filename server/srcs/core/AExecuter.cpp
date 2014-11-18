//
// AExecuter.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:21:30 2014 
// Last Update Tue Nov 18 10:57:27 2014 
//

#include "core/AExecuter.hh"
#include "debug/LogManager.hh"

AExecuter::AExecuter() :
  m_index(0)
{
}

AExecuter::~AExecuter()
{
}

const char*
AExecuter::getNextToken(const char* params) const
{
  const char*	ptr;

  ptr = strchr(params, ' ');
  if (ptr != NULL)
    while (*ptr == ' ')
      ++ptr;

  return (ptr);
}

unsigned int
AExecuter::tokenSize(const char* token) const
{
  const char*	ptr;
  unsigned int	size;

  ptr = strchr(token, ' ');
  if (ptr == NULL)
    size = strlen(token);
  else
    size = static_cast<unsigned int>(ptr - token);

  return (size);
}


unsigned int
AExecuter::calcCommandSize(const char* command) const
{
  const char*	ptr;
  unsigned int	size;

  ptr = strchr(command, ' ');
  if (ptr == NULL)
    size = strlen(command);
  else
    size = static_cast<unsigned int>(ptr - command);

  return (size);
}


void
AExecuter::executeCommand(const char* command)
{
  const char*	params;
  char		buffer[0x100];
  unsigned int	size;
  unsigned int	i;
  bool		found;

  size = this->calcCommandSize(command);
  found = false;

  for (i = 0; found == false && i < m_index; ++i)
    if (strlen(m_commands[i]) == size && !strncmp(command, m_commands[i], size))
      {
	params = &command[size + 1];
	while (*params == ' ')
	  ++params;
	(this->*m_executions[i])(params);
	found = true;
      }

  if (found == false)
    {
      strncpy(buffer, command, size);
      buffer[size] = '\0';
      LogManagerSingleton::access()->error->print("Command %s unknown.", buffer);
    }
}

void
AExecuter::executeCommand(const char* name, const char* params)
{
  unsigned int	i;
  bool		found;

  found = false;

  for (i = 0; found == false && i < m_index; ++i)
    if (!strcmp(name, m_commands[i]))
      {
	(this->*m_executions[i])(params);
	found = true;
      }

  if (found == false)
    LogManagerSingleton::access()->error->print("Command %s unknown.", name);
}
