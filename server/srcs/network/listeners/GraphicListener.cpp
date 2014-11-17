//
// GraphicListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Sun Nov 16 16:08:06 2014 
//

#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "network/listeners/GraphicListener.hh"

#include <cstdio>
#include <cstdlib>

GraphicListener::GraphicListener()
{
  this->initCommand("CHK", 3, &GraphicListener::sendChunkData);
  this->initCommand("CAS", 3, &GraphicListener::sendHooplaData);
  this->initCommand("PDC", 2, &GraphicListener::sendPlayerData);
  this->initCommand("TDC", 2, &GraphicListener::sendTeamData);
}

GraphicListener::~GraphicListener()
{
}


bool
GraphicListener::sendChunkData(Client* client, char* const* args) const
{
  const Map*	map = this->getServerData();
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
    LogManagerSingleton::access()->error->print("Trying to get an invalid chunk : %d/%d.",
						x, y);
  else
    {
      chunk = &map->getChunk(x, y);
      sprintf(buffer, "CHK %d %d\n", x, y);
      *client << buffer;
      for (hx = 0; hx < CHUNK_SIZE; ++hx)
	for (hy = 0; hy < CHUNK_SIZE; ++hy)
	  *client << chunk->getHoopla(hx, hy);
    }

  return (valid);
}

bool
GraphicListener::sendHooplaData(Client* client, char* const* args) const
{
  const Map*	map = this->getServerData();
  unsigned int	x;
  unsigned int	y;
  bool		valid;

  x = atoi(args[1]);
  y = atoi(args[2]);

  valid = IS_GOOD_HOOPLA_POS(x, y, map);
  if (valid == false)
    LogManagerSingleton::access()->error->print("Trying to get an invalid hoopla : %d/%d.",
						x, y);
  else
    *client << map->getChunk(x / CHUNK_SIZE, y / CHUNK_SIZE).getHoopla(x % CHUNK_SIZE, y % CHUNK_SIZE);

  return (valid);
}

bool
GraphicListener::sendPlayerData(Client* client, char* const* args) const
{
  const GameData*       gameData = this->getServerData();
  const Player*	        player;
  bool			valid;

  player = gameData->getPlayer(args[1]);
  valid = (player != NULL);

  if (valid == false)
    LogManagerSingleton::access()->error->print("Invalid player %s.", args[1]);
  else
    *client << *player;

  return (valid);
}

bool
GraphicListener::sendTeamData(Client* client, char* const* args) const
{
  const GameData*       gameData = this->getServerData();
  const Team*		team;
  bool			valid;

  team = gameData->getTeam(args[1]);
  valid = (team != NULL);

  if (valid == false)
    LogManagerSingleton::access()->error->print("Invalid team %s.", args[1]);
  else
    *client << *team;

  return (valid);
}
