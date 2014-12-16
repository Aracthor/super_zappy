//
// CommandExecuter.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 17:37:57 2014 
// Last Update Mon Dec 15 13:33:35 2014 
//

#ifndef COMMAND_EXECUTER_HH_
# define COMMAND_EXECUTER_HH_

# include "AExecuter.hh"
# include "LinkedToServer.hh"
# include "debug/LogParameter.hh"
# include "map/Map.hh"

class		CommandExecuter : public AExecuter,
				  private LinkedToServer
{
private:
  LogParameter	m_logParameter;

public:
  CommandExecuter();
  virtual ~CommandExecuter();

private:
  bool	resize(Map* map, const char* width, const char* height);

private:
  void	startGame(const char* params);
  void  logAction(const char* params);
  void  resetGame(const char* params);
  void	rebuildMap(const char* params);
  void	changeSpeed(const char* params);

public:
  void	executeCommand(const char* command);
  void	executeCommand(const char* name, const char* param);
};

#endif // !COMMAND_EXECUTER_HH_
