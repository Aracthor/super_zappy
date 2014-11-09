//
// Displacer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 00:57:44 2014 
// Last Update Sun Nov  9 03:09:41 2014 
//

#ifndef DISPLACER_HH_
# define DISPLACER_HH_

# include "IExecutor.hh"
# include "displacers/DisplacerMethod.hh"

class	Displacer : public IExecutor
{
private:
  DisplacerMethod*	m_methods[Class::skill_level_max];

public:
  Displacer();
  ~Displacer();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !DISPLACER_HH_
