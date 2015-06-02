//
// SigpipeHandler.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Feb 24 15:30:33 2015 aracthor
// Last Update Tue Feb 24 15:30:40 2015 aracthor
//

#ifndef SIGPIPE_HANDLER_HH_
# define SIGPIPE_HANDLER_HH_

# include "SignalHandler.hh"
# include "core/LinkedToServer.hh"

class	SigpipeHandler : public SignalHandler<SIGPIPE>,
			 private LinkedToServer
{
public:
  SigpipeHandler();
  ~SigpipeHandler();

public:
  void	onCatch();
};

#endif // !SIGPIPE_HANDLER_HH_
