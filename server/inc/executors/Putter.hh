//
// Putter.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 15:51:29 2014 
// Last Update Wed Nov 12 16:02:31 2014 
//

#ifndef PUTTER_HH_
# define PUTTER_HH_

# include "IExecutor.hh"

class	Putter : public IExecutor
{
public:
  Putter();
  ~Putter();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !PUTTER_HH_
