//
// Network.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:38:52 2014 
// Last Update Tue Nov 18 08:22:31 2014 
//

#ifndef NETWORK_HH_
# define NETWORK_HH_

# include "Client.hh"
# include "Socket.hh"
# include "abstractions/Pipe.hh"
# include "containers/Pool.hh"
# include "data/Team.hh"
# include "threading/CondVar.hh"

class		Network
{
private:
  typedef Pool<Client>	ClientsPool;

private:
  Socket	m_socket;
  ClientsPool	m_clients;
  Mutex		m_clientsMutex;
  CondVar	m_speakRing;
  Pipe		m_listenPipe;

public:
  Network(unsigned int port);
  virtual ~Network();

public:
  void	discalifyTeam(Team* team);
  void	kickClient(Client* client, bool disconnected);
  void	vsayToGraphicClients(const char* message, ...);

public:
  template <typename T>
  void	sayToGraphicClients(const T& message);

public:
  inline const Socket&		getSocket() const;
  inline int			getFd() const;
  inline const ClientsPool&	getClients() const;
  inline ClientsPool&		getClients();
  inline CondVar&		getSpeakRing();
  inline const Pipe&		getListenPipe() const;

public:
  inline void	lockClients();
  inline void	unlockClients();
};

#include "Network.hpp"

#endif // !NETWORK_HH_
