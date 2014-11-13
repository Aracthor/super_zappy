//
// outputs.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov 13 08:45:04 2014 
// Last Update Thu Nov 13 08:49:31 2014 
//

#include "debug/outputs.hh"

std::ostream&
operator<<(std::ostream& stream, const Inventory& inventory)
{
  unsigned int	i;

  for (i = 0; i < Hoopla::items_number; ++i)
    {
      if (inventory.getItemNumber(static_cast<Hoopla::EItem>(i)) > 0)
	stream << i << " : " << inventory.getItemNumber(static_cast<Hoopla::EItem>(i))
	       << std::endl;
    }

  stream << std::endl;

  return (stream);
}
