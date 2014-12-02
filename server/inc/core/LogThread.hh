//
// LogThread.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 14:19:57 2014 
// Last Update Thu Nov 20 11:26:05 2014 
//

#ifndef LOG_THREAD_HH_
# define LOG_THREAD_HH_

# include "abstractions/Clock.hh"
# include "threading/AZappyThread.hh"

class		ControlPanel;

class		LogThread : public AZappyThread
{
private:
  Clock		m_clock;
  ControlPanel*	m_controlPanel;

public:
  LogThread(ControlPanel* controlPanel);
  ~LogThread();

protected:
  bool	loopCycle();
};

#endif // !LOG_THREAD_HH_
