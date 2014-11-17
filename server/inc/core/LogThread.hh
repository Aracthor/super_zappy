//
// LogThread.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 17:57:24 2014 
// Last Update Sun Nov 16 18:02:55 2014 
//

#ifndef LOG_THREAD_HH_
# define LOG_THREAD_HH_

# include "threading/AZappyThread.hh"

class	LogThread : public AZappyThread
{
public:
  LogThread();
  ~LogThread();

protected:
  bool	loopCycle();
};

#endif // !LOG_THREAD_HH_
