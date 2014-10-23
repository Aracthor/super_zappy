//
// AuthentificationListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:20:41 2014 
// Last Update Wed Oct 22 13:48:26 2014 
//

#ifndef AUTHENTIFICATION_LISTENER_HH_
# define AUTHENTIFICATION_LISTENER_HH_

# include "GraphicMessages.hh"
# include "IListener.hh"

class	AuthentificationListener : public IListener,
				   public GraphicMessages
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
