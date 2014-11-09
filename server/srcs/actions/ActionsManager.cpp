//
// ActionsManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:31:48 2014 
// Last Update Sun Nov  9 06:36:25 2014 
//

#include "actions/ActionsManager.hh"
#include "debug/LogManager.hh"

ActionsManager::ActionsManager(unsigned int speed) :
  m_actions(MAX_WAITING_ACTIONS),
  m_executionSpeed(speed)
{
}

ActionsManager::~ActionsManager()
{
}


void
ActionsManager::insertAction(Action action)
{
  unsigned int	i;
  unsigned int	pos;
  int		timer;

  timer = action.getTimer();

  pos = 0;
  i = 0;
  while (i < m_actions.getSize())
    {
      if (m_actions[i].getPlayer() == action.getPlayer())
	{
	  action.setTimer(m_actions[i].getTimer() + timer);
	  pos = i + 1;
	}
      else if (action.getTimer() >= m_actions[i].getTimer())
	pos = i + 1;
      ++i;
    }


  LogManagerSingleton::access()->debug.print("Action %d prepared for player %s.",
					     action.getAction(),
					     action.getPlayer()->getName());
  m_actions.pushAt(action, pos);
}
