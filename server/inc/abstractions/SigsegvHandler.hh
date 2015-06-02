//
// SigsegvHandler.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server/code_qui_fait_segfault_valgrind
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 21 09:58:01 2014 
// Last Update Tue Feb 24 15:30:27 2015 aracthor
//

#ifndef SIGSEGV_HANDLER_HH_
# define SIGSEGV_HANDLER_HH_

# include "SignalHandler.hh"
# include "core/LinkedToServer.hh"

class	SigsegvHandler : public SignalHandler<SIGSEGV>,
			 private LinkedToServer
{
public:
  SigsegvHandler();
  ~SigsegvHandler();

public:
  void	onCatch();
};

#endif // !SIGSEGV_HANDLER_HH_
