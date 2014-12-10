//
// Hurtable.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 12:50:29 2014 
// Last Update Wed Dec 10 10:42:57 2014 
//

unsigned int
Hurtable::getMaxLife() const
{
  return (m_maxLife);
}

unsigned int
Hurtable::getCurrentLife() const
{
  return (m_currentLife);
}

bool
Hurtable::isAlive() const
{
  return (m_currentLife > 0);
}

bool
Hurtable::isDead() const
{
  return (m_currentLife == 0);
}
