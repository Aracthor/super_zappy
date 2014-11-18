//
// ListenThread.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 16:46:26 2014 
// Last Update Tue Nov 18 08:21:14 2014 
//

#ifndef LISTEN_THREAD_HH_
# define LISTEN_THREAD_HH_

# include "network/Client.hh"
# include "network/listeners/AuthentificationListener.hh"
# include "network/listeners/GraphicListener.hh"
# include "network/listeners/TeamListener.hh"
# include "threading/AZappyThread.hh"

# include <sys/time.h>
# include <sys/types.h>

class				ListenThread : public AZappyThread
{
private:
  AuthentificationListener	m_authentificationListener;
  GraphicListener		m_graphicListener;
  TeamListener			m_iaListener;

public:
  ListenThread();
  ~ListenThread();

private:
  void	getNewClient();
  bool	readClientLine(Client* client, char* line);
  bool	tryToReadLines(Client* client);
  bool	listenClient(Client* client);

private:
  int	listClients(fd_set* clients) const;
  void	listenClients(fd_set* clients);

public:
  bool  loopCycle();
  void	interrupt();
};

#endif // !LISTEN_THREAD_HH_
