//
// IAListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:20:41 2014 
// Last Update Tue Oct 21 10:05:22 2014 
//

#ifndef IA_LISTENER_HH_
# define IA_LISTENER_HH_

# include "IListener.hh"

class	IAListener : public IListener
{
public:
  IAListener();
  ~IAListener();

public:
  bool	listenFromClient(Client* client, char* message);
};

#endif // !IA_LISTENER_HH_
