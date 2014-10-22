//
// SpeakThread.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 21 10:56:31 2014 
// Last Update Tue Oct 21 11:54:36 2014 
//

#ifndef SPEAK_THREAD_HH_
# define SPEAK_THREAD_HH_

# include "threading/AZappyThread.hh"

class	SpeakThread : public AZappyThread
{
public:
  SpeakThread();
  ~SpeakThread();

private:
  bool	speakToClients();

protected:
  bool	loopCycle();

public:
  void	interrupt();
};

#endif // !SPEAK_THREAD_HH_
