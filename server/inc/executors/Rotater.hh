//
// Rotater.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 03:10:10 2014 
// Last Update Wed Nov 12 17:41:57 2014 
//

#ifndef ROTATER_HH_
# define ROTATER_HH_

# include "IExecutor.hh"

class	Rotater : public IExecutor
{
public:
  Rotater();
  ~Rotater();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !ROTATER_HH_
