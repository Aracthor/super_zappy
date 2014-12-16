//
// Hurtable.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 12:49:44 2014 
// Last Update Thu Dec 11 12:39:53 2014 
//

#include "data/Hurtable.hh"

Hurtable::Hurtable()
{
}

Hurtable::Hurtable(unsigned int life) :
  m_maxLife(life),
  m_currentLife(life)
{
}

Hurtable::~Hurtable()
{
}


void
Hurtable::hurt(unsigned int damages)
{
  m_currentLife -= damages;
  if (m_currentLife <= 0)
    m_currentLife = 0;
}

void
Hurtable::heal(unsigned int healing)
{
  m_currentLife += healing;
  if (m_currentLife > m_maxLife)
    m_currentLife = m_maxLife;
}
