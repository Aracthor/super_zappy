//
// Server.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:36:11 2014 
// Last Update Fri Nov 21 12:27:05 2014 
//

#ifndef SERVER_HH_
# define SERVER_HH_

# include "actions/ActionsManager.hh"
# include "containers/Pool.hh"
# include "core/LinkedToServer.hh"
# include "core/SingletonManager.hh"
# include "data/GameData.hh"
# include "map/Map.hh"
# include "network/Network.hh"
# include "threading/ThreadManager.hh"

class		ControlPanel;

class		Server : public SingletonManager,
			 public ActionsManager,
			 public GameData,
			 public Map,
			 public Network,
			 public ThreadManager
{
private:
  static Server*		s_server;


private:
  const bool	m_consoleMode;
  ControlPanel*	m_controlPanel;
  const pid_t	m_pid;

public:
  Server(const Configs& configs);
  ~Server();

private:
  void	startControlPanel();
  void	wait() const;

public:
  void	start();
  void	stop();

public:
  inline pid_t	getServerPid() const;

  friend class	LinkedToServer;
};

# include "Server.hpp"

#endif // !SERVER_HH_
