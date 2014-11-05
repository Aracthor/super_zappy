//
// LinkedToServer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 13:15:18 2014 
// Last Update Mon Nov  3 13:30:45 2014 
//

#ifndef LINKED_TO_SERVER_HH_
# define LINKED_TO_SERVER_HH_

class	Server;

class	LinkedToServer
{
public:
  LinkedToServer();
  virtual ~LinkedToServer();

protected:
  const Server*	getServerData() const;
  Server*	getServerData();
};

#endif // !LINKED_TO_SERVER_HH_
