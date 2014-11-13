//
// Inventory.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 15:53:50 2014 
// Last Update Wed Nov 12 15:57:07 2014 
//

bool
Inventory::isFull() const
{
  return (this->getActualSize() == m_maxSize);
}

unsigned int
Inventory::getMaxSize() const
{
  return (m_maxSize);
}
