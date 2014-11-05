//
// AuthentificationListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:20:41 2014 
// Last Update Wed Nov  5 13:18:51 2014 
//

#ifndef AUTHENTIFICATION_LISTENER_HH_
# define AUTHENTIFICATION_LISTENER_HH_

# include "IListener.hh"
# include "data/Team.hh"

class	AuthentificationListener : public IListener
{
public:
  AuthentificationListener();
  ~AuthentificationListener();

private:
  void	sendTeamData(Client* client, const Team& team, unsigned int id);

private:
  void	graphicAuthentification(Client* client);
  void	teamAuthentification(Client* client);

public:
  bool	listenFromClient(Client* client, char* message);
};

#endif // !AUTHENTIFICATION_LISTENER_HH_
