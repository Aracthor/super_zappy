//
// Network.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:38:52 2014 
// Last Update Tue Oct 21 11:53:15 2014 
//

#ifndef NETWORK_HH_
# define NETWORK_HH_

# include "Client.hh"
# include "Socket.hh"
# include "containers/Pool.hh"
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

public:
  Network(unsigned int port);
  virtual ~Network();

public:
  void	kickClient(Client* client, bool disconnected);

public:
  inline const Socket&		getSocket() const;
  inline int			getFd() const;
  inline const ClientsPool&	getClients() const;
  inline ClientsPool&		getClients();
  inline CondVar&		getSpeakRing();

public:
  inline void	lockClients();
  inline void	unlockClients();
};

#include "Network.hpp"

#endif // !NETWORK_HH_
