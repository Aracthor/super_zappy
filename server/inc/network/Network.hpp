//
// Network.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 14 12:58:45 2014 
// Last Update Sun Nov  9 04:26:41 2014 
//

template <typename T>
void
Network::sayToGraphicClients(const T& message)
{
  unsigned int	i;

  FOREACH_OF_POOL(m_clients, i)
    if (m_clients[i].isGraphic())
      m_clients[i] << message;
}


const Socket&
Network::getSocket() const
{
  return (m_socket);
}

int
Network::getFd() const
{
  return (m_socket.getFd());
}

const Network::ClientsPool&
Network::getClients() const
{
  return (m_clients);
}

Network::ClientsPool&
Network::getClients()
{
  return (m_clients);
}

CondVar&
Network::getSpeakRing()
{
  return (m_speakRing);
}


void
Network::lockClients()
{
  m_clientsMutex.lock();
}

void
Network::unlockClients()
{
  m_clientsMutex.unlock();
}
