//
// MasterDisplacer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:14:33 2014 
// Last Update Sun Nov  9 02:09:29 2014 
//

#ifndef MASTER_DISPLACER_HH_
# define MASTER_DISPLACER_HH_

# include "DisplacerMethod.hh"

class	MasterDisplacer : public DisplacerMethod
{
public:
  MasterDisplacer();
  ~MasterDisplacer();

public:
  bool	search(const sf::Vector2u& origin, const sf::Vector2u& dest);
};

#endif // !MASTER_DISPLACER_HH_
