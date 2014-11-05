//
// Server.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:36:11 2014 
// Last Update Mon Nov  3 15:57:27 2014 
//

#ifndef SERVER_HH_
# define SERVER_HH_

# include "core/LinkedToServer.hh"
# include "core/SingletonManager.hh"
# include "data/GameData.hh"
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
  Server(const Configs& configs);
  ~Server();

private:
  void	loop();

public:
  void	start();

  friend class	LinkedToServer;
};

#endif // !SERVER_HH_
