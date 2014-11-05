//
// IListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:17:11 2014 
// Last Update Mon Nov  3 13:31:14 2014 
//

#ifndef ILISTENER_HH_
# define ILISTENER_HH_

# include "core/LinkedToServer.hh"
# include "network/Client.hh"

class	IListener : protected LinkedToServer
{
protected:
  virtual ~IListener() {}

public:
  virtual bool	listenFromClient(Client* client, char* message) = 0;
};

#endif // !ILISTENER_HH_
