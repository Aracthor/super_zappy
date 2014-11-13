//
// Taker.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 15:51:19 2014 
// Last Update Wed Nov 12 15:51:25 2014 
//

#ifndef TAKER_HH_
# define TAKER_HH_

# include "IExecutor.hh"

class	Taker : public IExecutor
{
public:
  Taker();
  ~Taker();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !TAKER_HH_
