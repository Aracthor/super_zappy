//
// ActionsManager.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:29:37 2014 
// Last Update Fri Nov 21 12:41:33 2014 
//

const ActionsManager::ActionsList&
ActionsManager::getActions() const
{
  return (m_actions);
}

ActionsManager::ActionsList&
ActionsManager::getActions()
{
  return (m_actions);
}

unsigned int
ActionsManager::getSpeed() const
{
  return (m_executionSpeed);
}


void
ActionsManager::lockActions()
{
  m_lock.lock();
}

void
ActionsManager::unlockActions()
{
  m_lock.unlock();
}

void
ActionsManager::resetActions()
{
  m_actions.clear();
}
