//
// Server.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:36:11 2014 
// Last Update Wed Oct 22 13:25:57 2014 
//

#ifndef SERVER_HH_
# define SERVER_HH_

# include "core/GameData.hh"
# include "core/SingletonManager.hh"
# include "map/Map.hh"
# include "network/Network.hh"
# include "threading/ThreadManager.hh"

class		Server : public SingletonManager,
			 public GameData,
			 public Map,
			 public Network,
			 public ThreadManager
{
private:
  static Server*		s_server;

public:
  static inline Server*		accessServer();


public:
  Server(const Configs& configs);
  ~Server();

private:
  void	loop();

public:
  void	start();
};

#include "Server.hpp"

#endif // !SERVER_HH_
