//
// GraphicMessages.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 11:38:46 2014 
// Last Update Mon Oct 27 13:33:51 2014 
//

#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "network/listeners/GraphicMessages.hh"

#include <cstdio>
#include <cstdlib>

GraphicMessages::GraphicMessages() :
  m_server(NULL)
{
}

GraphicMessages::~GraphicMessages()
{
}


const Server*
GraphicMessages::getData()
{
  if (m_server == NULL)
    m_server = Server::accessServer();
  return (m_server);
}


void
GraphicMessages::sendHooplaData(Client* client, const Hoopla& hoopla,
				unsigned int x, unsigned int y)
{
  char	buffer[0x1000];

  sprintf(buffer, "CAS %d %d %d %d %d %d %d %d",
	  x, y,
	  hoopla.ground, (int)hoopla.height,
	  hoopla.item, hoopla.itemNumber,
	  hoopla.object, hoopla.player_id);
  *client << buffer;
}

void
GraphicMessages::sendTeamData(Client* client, const char* team, unsigned int id)
{
  char	buffer[0x1000];

  sprintf(buffer, "TDC %d %s", id, team);
  *client << buffer;
}


bool
GraphicMessages::sendChunkData(Client* client, char* const* args)
{
  const Map*	map = this->getData();
  const Chunk*	chunk;
  char		buffer[0x1000];
  unsigned int	x;
  unsigned int	y;
  unsigned int	hx;
  unsigned int	hy;
  bool		valid;

  x = atoi(args[1]);
  y = atoi(args[2]);

  valid = IS_GOOD_CHUNK_POS(x, y, map);
  if (valid == false)
    LogManagerSingleton::access()->error.print("Trying to get an invalid chunk : %d/%d.",
					       x, y);
  else
    {
      chunk = &map->getChunk(x, y);
      sprintf(buffer, "CHK %d %d", x, y);
      *client << buffer;
      for (hx = 0; hx < CHUNK_SIZE; ++hx)
	for (hy = 0; hy < CHUNK_SIZE; ++hy)
	  this->sendHooplaData(client, chunk->getHoopla(hx, hy),
			       x * CHUNK_SIZE + hx, y * CHUNK_SIZE + hy);
    }

  return (valid);
}

bool
GraphicMessages::sendHooplaData(Client* client, char* const* args)
{
  const Map*	map = this->getData();
  unsigned int	x;
  unsigned int	y;
  bool		valid;

  x = atoi(args[1]);
  y = atoi(args[2]);

  valid = IS_GOOD_HOOPLA_POS(x, y, map);
  if (valid == false)
    LogManagerSingleton::access()->error.print("Trying to get an invalid hoopla : %d/%d.",
					       x, y);
  else
    this->sendHooplaData(client,
			 map->getChunk(x / CHUNK_SIZE, y / CHUNK_SIZE)
			 .getHoopla(x % CHUNK_SIZE, y % CHUNK_SIZE),
			 x, y);

  return (valid);
}

bool
GraphicMessages::sendPlayerData(Client* client, char* const* args)
{
  (void)(client);
  (void)(args);
  return (true);
}

bool
GraphicMessages::sendTeamData(Client* client, char* const* args)
{
  const GameData*       gameData = this->getData();
  unsigned int		id;
  bool			valid;

  id = atoi(args[1]);
  valid = (id >= gameData->getTeams().getNumber());
  if (valid == false)
    LogManagerSingleton::access()->error.print("Invalid team id %d.", id);
  else
    this->sendTeamData(client, gameData->getTeams().getName(id), id);

  return (valid);
}
