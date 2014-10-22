//
// ListenThread.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 16:46:26 2014 
// Last Update Tue Oct 21 10:32:48 2014 
//

#ifndef LISTEN_THREAD_HH_
# define LISTEN_THREAD_HH_

# include "network/Client.hh"
# include "network/listeners/AuthentificationListener.hh"
# include "network/listeners/GraphicListener.hh"
# include "network/listeners/IAListener.hh"
# include "threading/AZappyThread.hh"

# include <sys/time.h>
# include <sys/types.h>

class				ListenThread : public AZappyThread
{
private:
  AuthentificationListener	m_authentificationListener;
  GraphicListener		m_graphicListener;
  IAListener			m_iaListener;

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
};

#endif // !LISTEN_THREAD_HH_
