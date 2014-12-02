//
// AZappyThread.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 15:18:03 2014 
// Last Update Thu Nov 20 11:26:08 2014 
//

#ifndef AZAPPY_THREAD_HH_
# define AZAPPY_THREAD_HH_

# include "AThread.hh"
# include "core/LinkedToServer.hh"

class		Server;

class		AZappyThread : public AThread,
			       protected LinkedToServer
{
private:
  const char*	m_name;
  bool		m_loop;

public:
  AZappyThread(const char* name);
  virtual ~AZappyThread();

protected:
  Server*	m_server;

public:
  void		start();

protected:
  void		run();
  virtual bool	loopCycle() = 0;

public:
  virtual void	interrupt();
};

#endif // !AZAPPY_THREAD_HH_
