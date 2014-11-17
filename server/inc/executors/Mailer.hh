//
// Mailer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 14:41:32 2014 
// Last Update Fri Nov 14 14:41:44 2014 
//

#ifndef MAILER_HH_
# define MAILER_HH_

# include "IExecutor.hh"

class	Mailer : public IExecutor
{
public:
  Mailer();
  ~Mailer();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !MAILER_HH_
