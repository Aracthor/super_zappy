//
// IExecutor.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 00:50:24 2014 
// Last Update Sun Nov  9 00:58:45 2014 
//

#ifndef IEXECUTOR_HH_
# define IEXECUTOR_HH_

# include "actions/Action.hh"
# include "core/LinkedToServer.hh"
# include "data/Player.hh"

class	IExecutor : protected LinkedToServer
{
public:
  virtual ~IExecutor() {}

public:
  virtual void	execute(Player* player, const Action::UData& data) = 0;
};

#endif // !IEXECUTOR_HH_
