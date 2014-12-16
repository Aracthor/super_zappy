//
// ActionFactory.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 23:07:04 2014 
// Last Update Tue Dec 16 09:57:17 2014 
//

#include "actions/ActionFactory.hh"
#include "actions/timecalcs/AttackTimeCalculator.hh"
#include "actions/timecalcs/CraftTimeCalculator.hh"
#include "actions/timecalcs/DestroyerTimeCalculator.hh"
#include "actions/timecalcs/DiggerTimeCalculator.hh"
#include "debug/LogManager.hh"

#include <cstdlib>
#include <cstring>

ActionFactory::ActionFactory()
{
  memset(m_actionNames, 0, sizeof(m_actionNames));
  memset(m_actionTimers, 0, sizeof(m_actionTimers));
  memset(m_timeCalcs, 0, sizeof(m_timeCalcs));

  m_actionNames[Action::displace]	= "DIS";
  m_actionTimers[Action::displace]	= 10;
  m_actionReaders[Action::displace]	= &ActionFactory::readPositionData;

  m_actionNames[Action::search]		= "SRH";
  m_actionTimers[Action::search]	= 5;
  m_actionReaders[Action::search]	= &ActionFactory::readIdData;

  m_actionNames[Action::destroy]	= "DES";
  m_timeCalcs[Action::destroy]		= new DestroyerTimeCalculator;
  m_actionReaders[Action::destroy]	= &ActionFactory::readPositionData;

  m_actionNames[Action::dig]		= "DIG";
  m_timeCalcs[Action::dig]		= new DiggerTimeCalculator;
  m_actionReaders[Action::dig]		= NULL;

  m_actionNames[Action::take]		= "TAK";
  m_actionTimers[Action::take]		= 10;
  m_actionReaders[Action::take]		= NULL;

  m_actionNames[Action::put]		= "PUT";
  m_actionTimers[Action::put]		= 10;
  m_actionReaders[Action::put]		= &ActionFactory::readItemData;

  m_actionNames[Action::equip]		= "EQU";
  m_actionTimers[Action::equip]		= 5;
  m_actionReaders[Action::equip]	= &ActionFactory::readIdData;

  m_actionNames[Action::craft]		= "CRF";
  m_timeCalcs[Action::craft]		= new CraftTimeCalculator;
  m_actionReaders[Action::craft]	= &ActionFactory::readIdData;

  m_actionNames[Action::mail]		= "MAIL";
  m_actionTimers[Action::mail]		= 2;
  m_actionReaders[Action::mail]		= &ActionFactory::readTextData;

  m_actionNames[Action::locateEnnemy]	= "LEN";
  m_actionTimers[Action::locateEnnemy]	= 5;
  m_actionReaders[Action::locateEnnemy]	= &ActionFactory::readTextData;

  m_actionNames[Action::attack]		= "ATT";
  m_timeCalcs[Action::attack]		= new AttackTimeCalculator;
  m_actionReaders[Action::attack]	= &ActionFactory::readPositionData;
}

ActionFactory::~ActionFactory()
{
  unsigned int	i;

  for (i = 0; i < Action::actions_number; ++i)
    if (m_timeCalcs[i] != NULL)
      delete (m_timeCalcs[i]);
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
    LogManagerSingleton::access()->error->print("Invalid action position read");

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
    LogManagerSingleton::access()->error->print("Invalid action id read");

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
    LogManagerSingleton::access()->error->print("Invalid action item read");

  return (valid);
}

bool
ActionFactory::readTextData(Action::UData& data,
			    const CommandCutter::CuttedLine& args) const
{
  bool		valid;
  unsigned int	size;
  unsigned int	i;

  size = 0;
  for (i = 0; i < args.argsNumber; ++i)
    size += strlen(args.args[i]);
  valid = (size < MAIL_BUFFER_SIZE);

  if (valid)
    {
      data.text[0] = '\0';
      for (i = 0; i < args.argsNumber; ++i)
	strcat(data.text, args.args[i]);
    }
  else
    LogManagerSingleton::access()->error->print("Too long text in action read");

  return (valid);
}


bool
ActionFactory::createAction(Action& action, const char* actionName, Player* player,
			    const CommandCutter::CuttedLine& args)
{
  unsigned int	id;
  unsigned int	time;
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
	{
	  time = m_actionTimers[id];
	  if (m_timeCalcs[id] != NULL)
	    time = m_timeCalcs[id]->calcTime(player, data);
	  action = Action(player, static_cast<Action::EAction>(id), time, data);
	}
    }

  return (valid);
}
