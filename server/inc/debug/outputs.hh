//
// outputs.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov 13 08:44:12 2014 
// Last Update Thu Nov 13 09:33:02 2014 
//

#ifndef OUTPUTS_HH_
# define OUTPUTS_HH_

# include <iostream>

# include "data/Inventory.hh"

std::ostream&	operator<<(std::ostream& stream, const Inventory& inventory);

#endif // !OUTPUTS_HH_
