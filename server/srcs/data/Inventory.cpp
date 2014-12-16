//
// Inventory.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 15:08:21 2014 
// Last Update Thu Dec 11 09:01:35 2014 
//

#include "abstractions/maths.hh"
#include "data/Inventory.hh"
#include "exceptions/ZappyException.hh"

#include <cstring>

Inventory::Inventory()
{
}

Inventory::Inventory(unsigned int maxSize) :
  m_maxSize(maxSize)
{
  memset(m_items, 0, sizeof(m_items));
  memset(m_numbers, 0, sizeof(m_numbers));
}

Inventory::~Inventory()
{
}


int
Inventory::getIndex(Hoopla::EItem item) const
{
  unsigned int	i;
  int		index;

  index = -1;

  for (i = 0; i < INVENTORY_MAX_SLOTS; ++i)
    if (m_items[i] == item)
      index = i;

  return (index);
}

int
Inventory::createSlot(Hoopla::EItem item)
{
  int	index;

  index = 0;
  while (index < INVENTORY_MAX_SLOTS && m_items[index] != Hoopla::none)
    ++index;

  if (index == INVENTORY_MAX_SLOTS)
    throw ZappyException("Trying to create a new slot in a full inventory.");

  m_items[index] = item;
  m_numbers[index] = 0;

  return (index);
}

unsigned int
Inventory::getActualSize() const
{
  unsigned int	size;
  unsigned int	i;

  size = 0;
  for (i = 0; i < INVENTORY_MAX_SLOTS; ++i)
    if (m_items[i] != Hoopla::none)
      size += m_numbers[i];

  return (size);
}


unsigned int
Inventory::add(Hoopla::EItem item, unsigned int quantity)
{
  int	index;

  index = this->getIndex(item);
  if (index == -1)
    index = this->createSlot(item);

  quantity = MIN(quantity, m_maxSize - this->getActualSize());
  m_numbers[index] += quantity;

  return (quantity);
}


void
Inventory::sub(Hoopla::EItem item, unsigned int quantity)
{
  int   index;

  index = this->getIndex(item);
  if (index == -1 || m_numbers[index] < quantity)
    throw ZappyException("Trying to sub too many data from an inventory.");

  m_numbers[index] -= quantity;
  if (m_numbers[index] == 0)
    m_items[index] = Hoopla::none;
}


bool
Inventory::hasNoMoreSlot() const
{
  unsigned int	i;
  bool		full;

  full = true;

  for (i = 0; full == true && i < INVENTORY_MAX_SLOTS; ++i)
    if (m_items[i] == Hoopla::none)
      full = false;

  return (full);
}

unsigned int
Inventory::getItemNumber(Hoopla::EItem item) const
{
  int		index;
  unsigned int	number;

  index = this->getIndex(item);

  if (index == -1)
    number = 0;
  else
    number = m_numbers[index];

  return (number);
}
