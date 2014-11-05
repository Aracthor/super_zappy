//
// AuthentificationListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Wed Nov  5 13:19:00 2014 
//

#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "network/Protocol.hh"
#include "network/listeners/AuthentificationListener.hh"

#include <cstdio>
#include <cstring>

AuthentificationListener::AuthentificationListener()
{
}

AuthentificationListener::~AuthentificationListener()
{
}


void
AuthentificationListener::sendTeamData(Client* client, const Team& team, unsigned int id)
{
  char	buffer[0x1000];

  sprintf(buffer, "TDC %d %s %d", id, team.getName(), team.isDiscalified());
  *client << buffer;
}


void
AuthentificationListener::graphicAuthentification(Client* client)
{
  const Server*	server = this->getServerData();
  const Team*	teams = server->getTeams();
  unsigned int	i;
  char		buffer[0x1000];

  client->setGraphic();

  sprintf(buffer, "ISL %d %d %d",
	  server->getSpeed(), server->getWidth(), server->getHeight());
  *client << buffer;

  for (i = 0; i < server->getTeamsNumber(); ++i)
    this->sendTeamData(client, teams[i], i);

  LogManagerSingleton::access()->connection.print("Client %d authentified as graphic.",
						  client->getFd());
}

void
AuthentificationListener::teamAuthentification(Client* client)
{
  client->setTeam();

  LogManagerSingleton::access()->connection.print("Client %d authentified as team.",
						  client->getFd());
}

bool
AuthentificationListener::listenFromClient(Client* client, char* message)
{
  bool	authentified;

  authentified = true;
  if (!strcmp(message, AUTHENTIFICATION_GRAPHICAL))
    this->graphicAuthentification(client);
  else if (!strcmp(message, AUTHENTIFICATION_IA))
    this->teamAuthentification(client);
  else
    authentified = false;

  if (authentified == false)
    LogManagerSingleton::access()->error.print("Client %d authentified as sucker.",
					       client->getFd());

  return (authentified);
}
