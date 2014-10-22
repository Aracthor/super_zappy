//
// CondVar.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 21 11:43:48 2014 
// Last Update Tue Oct 21 11:51:18 2014 
//

#ifndef COND_VAR_HH_
# define COND_VAR_HH_

# include "Mutex.hh"

class	CondVar
{
private:
  Mutex			m_mutex;
  pthread_cond_t	m_condvar;

public:
  CondVar();
  ~CondVar();

public:
  void	wait();
  void	signal();
  void	broadcast();
};

#endif // !COND_VAR_HH_
