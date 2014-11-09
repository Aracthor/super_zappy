//
// ExpertDisplacer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:14:33 2014 
// Last Update Sun Nov  9 02:09:39 2014 
//

#ifndef EXPERT_DISPLACER_HH_
# define EXPERT_DISPLACER_HH_

# include "DisplacerMethod.hh"

class	ExpertDisplacer : public DisplacerMethod
{
public:
  ExpertDisplacer();
  ~ExpertDisplacer();

public:
  bool	search(const sf::Vector2u& origin, const sf::Vector2u& dest);
};

#endif // !EXPERT_DISPLACER_HH_
