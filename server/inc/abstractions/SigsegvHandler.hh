//
// SigsegvHandler.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server/code_qui_fait_segfault_valgrind
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 21 09:58:01 2014 
// Last Update Fri Nov 21 10:24:41 2014 
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
