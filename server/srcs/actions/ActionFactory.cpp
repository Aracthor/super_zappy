//
// ActionFactory.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 23:07:04 2014 
// Last Update Sun Nov  9 08:11:14 2014 
//

#include "actions/ActionFactory.hh"
#include "debug/LogManager.hh"

#include <cstdlib>
#include <cstring>

ActionFactory::ActionFactory()
{
  memset(m_actionNames, 0, sizeof(m_actionNames));

  m_actionNames[Action::displace]	= "DIS";
  m_actionTimers[Action::displace]	= 10;
  m_actionReaders[Action::displace]	= &ActionFactory::readPositionData;

  m_actionNames[Action::search]		= "SRH";
  m_actionTimers[Action::search]	= 5;
  m_actionReaders[Action::search]	= &ActionFactory::readIdData;
}

ActionFactory::~ActionFactory()
{
}


bool
ActionFactory::readPositionData(Action::UData& data,
				const CommandCutter::CuttedLine& args) const
{
  bool	valid;

  valid = (args.argsNumber == 2);
  if (valid)
    {
      data.position.x = atoi(args.args[0]);
      data.position.y = atoi(args.args[1]);
    }
  else
    LogManagerSingleton::access()->error.print("Invalid action position read");

  return (valid);
}

bool
ActionFactory::readIdData(Action::UData& data,
			  const CommandCutter::CuttedLine& args) const
{
  bool	valid;

  valid = (args.argsNumber == 1);
  if (valid)
    data.id = atoi(args.args[0]);
  else
    LogManagerSingleton::access()->error.print("Invalid action id read");

  return (valid);
}


bool
ActionFactory::createAction(Action& action, const char* actionName, Player* player,
			    const CommandCutter::CuttedLine& args)
{
  unsigned int	id;
  Action::UData	data;
  bool		valid;

  id = 0;
  while (id < Action::actions_number &&
	 (m_actionNames[id] == NULL || strcmp(m_actionNames[id], actionName)))
    ++id;

  valid = (id < Action::actions_number);
  if (valid)
    {
      valid = (this->*m_actionReaders[id])(data, args);
      if (valid)
	action = Action(player, static_cast<Action::EAction>(id), m_actionTimers[id], data);
    }

  return (valid);
}
