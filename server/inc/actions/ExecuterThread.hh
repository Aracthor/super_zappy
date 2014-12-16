//
// ExecuterThread.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:18:40 2014 
// Last Update Mon Dec 15 13:27:14 2014 
//

#ifndef EXECUTER_THREAD_HH_
# define EXECUTER_THREAD_HH_

# include "abstractions/Clock.hh"
# include "actions/Action.hh"
# include "executors/IExecutor.hh"
# include "threading/AZappyThread.hh"

class		ExecuterThread : public AZappyThread
{
private:
  IExecutor*	m_executors[Action::actions_number];
  Clock		m_clock;
  unsigned int	m_loopCounter;

public:
  ExecuterThread();
  ~ExecuterThread();

private:
  void	decrementTimers();
  void	executeActions();
  void	execute();
  void	incrementLoop();
  void	checkVictory();
  void	wait() const;

protected:
  bool	loopCycle();
};

#endif // !EXECUTER_THREAD_HH_
