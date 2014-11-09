//
// AdeptDisplacer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:14:33 2014 
// Last Update Sun Nov  9 02:09:34 2014 
//

#ifndef ADEPT_DISPLACER_HH_
# define ADEPT_DISPLACER_HH_

# include "DisplacerMethod.hh"

class	AdeptDisplacer : public DisplacerMethod
{
public:
  AdeptDisplacer();
  ~AdeptDisplacer();

public:
  bool	search(const sf::Vector2u& origin, const sf::Vector2u& dest);
};

#endif // !ADEPT_DISPLACER_HH_
