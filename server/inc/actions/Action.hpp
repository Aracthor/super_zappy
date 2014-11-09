//
// Action.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:08:42 2014 
// Last Update Sun Nov  9 06:26:47 2014 
//

void
Action::setTimer(int timer)
{
  m_timer = timer;
}

void
Action::decrementTimer()
{
  --m_timer;
}

Player*
Action::getPlayer()
{
  return (m_player);
}


Action::EAction
Action::getAction() const
{
  return (m_action);
}

const Player*
Action::getPlayer() const
{
  return (m_player);
}

const Action::UData&
Action::getData() const
{
  return (m_data);
}

int
Action::getTimer() const
{
  return (m_timer);
}
