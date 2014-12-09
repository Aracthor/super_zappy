//
// Object.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:46:52 2014 
// Last Update Thu Dec  4 09:50:26 2014 
//

const Production&
Object::getProduction() const
{
  return (m_production);
}

unsigned int
Object::getDestroyTime() const
{
  return (m_destroyTime);
}

bool
Object::isDestroyable() const
{
  return (m_destroyable);
}
