//
// IExecutor.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 00:50:24 2014 
// Last Update Tue Dec  9 16:32:48 2014 
//

#ifndef IEXECUTOR_HH_
# define IEXECUTOR_HH_

# include "actions/Action.hh"
# include "core/Server.hh"
# include "data/Player.hh"

class		IExecutor : protected LinkedToServer
{
public:
  virtual ~IExecutor() {}

public:
  virtual void	execute(Player* player, const Action::UData& data) = 0;

protected:
  inline void	insertAction(const Action& action);
};

# include "IExecutor.hpp"

#endif // !IEXECUTOR_HH_
