//
// AuthentificationListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:20:41 2014 
// Last Update Tue Oct 21 10:07:32 2014 
//

#ifndef AUTHENTIFICATION_LISTENER_HH_
# define AUTHENTIFICATION_LISTENER_HH_

# include "IListener.hh"

class	AuthentificationListener : public IListener
{
public:
  AuthentificationListener();
  ~AuthentificationListener();

private:
  void	graphicAuthentification(Client* client);
  void	playerAuthentification(Client* client, char* team);

public:
  bool	listenFromClient(Client* client, char* message);
};

#endif // !AUTHENTIFICATION_LISTENER_HH_
