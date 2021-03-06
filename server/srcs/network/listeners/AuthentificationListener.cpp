//
// AuthentificationListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Thu Dec 11 10:02:49 2014 
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


static void
sendTeam(const Team& team, Client& client)
{
  client << team;
}

void
AuthentificationListener::graphicAuthentification(Client* client)
{
  const Server*	server = this->getServerData();
  char		buffer[0x1000];

  client->setGraphic();

  sprintf(buffer, "ISL %d %d %d\n",
	  server->getSpeed(), server->getWidth(), server->getHeight());
  *client << buffer;

  this->getServerData()->doToTeams(&sendTeam, *client);

  LogManagerSingleton::access()->connection->print("Client %d authentified as graphic.",
						   client->getFd());
}

void
AuthentificationListener::teamAuthentification(Client* client)
{
  client->setTeam();

  LogManagerSingleton::access()->connection->print("Client %d authentified as team.",
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
    LogManagerSingleton::access()->error->print("Client %d authentified as sucker.",
						client->getFd());

  return (authentified);
}
