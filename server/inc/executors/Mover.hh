//
// Mover.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 03:09:45 2014 
// Last Update Sun Nov  9 03:12:08 2014 
//

#ifndef MOVER_HH_
# define MOVER_HH_

# include "IExecutor.hh"

class	Mover : public IExecutor
{
public:
  Mover();
  ~Mover();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !MOVER_HH_
