//
// ActionFactory.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 23:07:04 2014 
// Last Update Wed Nov 12 17:41:33 2014 
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

  m_actionNames[Action::tryToDestroy]	= "DES";
  m_actionTimers[Action::tryToDestroy]	= 1;
  m_actionReaders[Action::tryToDestroy]	= &ActionFactory::readPositionData;

  m_actionNames[Action::take]		= "TAK";
  m_actionTimers[Action::take]		= 10;
  m_actionReaders[Action::take]		= NULL;

  m_actionNames[Action::put]		= "PUT";
  m_actionTimers[Action::put]		= 10;
  m_actionReaders[Action::put]		= &ActionFactory::readItemData;

  m_actionNames[Action::equip]		= "EQU";
  m_actionTimers[Action::equip]		= 5;
  m_actionReaders[Action::equip]	= &ActionFactory::readIdData;
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
ActionFactory::readItemData(Action::UData& data,
			    const CommandCutter::CuttedLine& args) const
{
  bool	valid;

  valid = (args.argsNumber == 2);
  if (valid)
    {
      data.item.id = static_cast<Hoopla::EItem>(atoi(args.args[0]));
      data.item.number = atoi(args.args[1]);
      valid = (data.item.id < Hoopla::items_number);
    }
  if (!valid)
    LogManagerSingleton::access()->error.print("Invalid action item read");

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
      if (m_actionReaders[id] != NULL)
	valid = (this->*m_actionReaders[id])(data, args);
      if (valid)
	action = Action(player, static_cast<Action::EAction>(id), m_actionTimers[id], data);
    }

  return (valid);
}
