//
// CommandExecuter.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 17:37:57 2014 
// Last Update Tue Nov 18 14:42:50 2014 
//

#ifndef COMMAND_EXECUTER_HH_
# define COMMAND_EXECUTER_HH_

# include "AExecuter.hh"
# include "LinkedToServer.hh"
# include "debug/LogParameter.hh"

class		CommandExecuter : public AExecuter,
				  private LinkedToServer
{
private:
  LogParameter	m_logParameter;

public:
  CommandExecuter();
  virtual ~CommandExecuter();

private:
  void	startGame(const char* params);
  void  logAction(const char* params);
  void  resetGame(const char* params);
};

#endif // !COMMAND_EXECUTER_HH_
