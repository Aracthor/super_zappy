//
// Inventory.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 15:06:24 2014 
// Last Update Thu Dec 11 09:01:17 2014 
//

#ifndef INVENTORY_HH_
# define INVENTORY_HH_

# include "map/Hoopla.hh"

# define INVENTORY_MAX_SLOTS	(10)

class		Inventory
{
private:
  Hoopla::EItem	m_items[INVENTORY_MAX_SLOTS];
  unsigned int	m_numbers[INVENTORY_MAX_SLOTS];
  unsigned int	m_maxSize;

public:
  Inventory(); // For container-conformity
  Inventory(unsigned int maxSize);
  ~Inventory();

private:
  int		getIndex(Hoopla::EItem item) const;
  int		createSlot(Hoopla::EItem item);
  unsigned int	getActualSize() const;

public:
  unsigned int	add(Hoopla::EItem item, unsigned int quantity);
  void	        sub(Hoopla::EItem item, unsigned int quantity);

public:
  bool		hasNoMoreSlot() const;
  unsigned int	getItemNumber(Hoopla::EItem item) const;

public:
  inline bool		isFull() const;
  inline bool		canHandleMore(Hoopla::EItem item, unsigned int number) const;
  inline unsigned int	getMaxSize() const;
};

# include "Inventory.hpp"

#endif // !INVENTORY_HH_
