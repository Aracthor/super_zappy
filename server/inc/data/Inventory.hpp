//
// Inventory.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 15:53:50 2014 
// Last Update Fri Nov 14 17:56:56 2014 
//

bool
Inventory::isFull() const
{
  return (this->getActualSize() == m_maxSize);
}

bool
Inventory::canHandleMore(Hoopla::EItem item, unsigned int number) const
{
  return (this->getActualSize() + number <= m_maxSize &&
	  (!this->hasNoMoreSlot() || this->getItemNumber(item) > 0));
}

unsigned int
Inventory::getMaxSize() const
{
  return (m_maxSize);
}
