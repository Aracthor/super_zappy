//
// GraphicMessages.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 11:38:46 2014 
// Last Update Wed Oct 22 12:59:37 2014 
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
GraphicMessages::getServer()
{
  if (m_server == NULL)
    m_server = Server::accessServer();
  return (m_server);
}


void
GraphicMessages::sendHooplaData(Client* client, const Hoopla& hoopla,
				unsigned int x, unsigned int y)
{
  char		buffer[0x1000];

  sprintf(buffer, "CAS %d %d %d %d %d %d %d %d",
	  x, y,
	  hoopla.ground, hoopla.height,
	  hoopla.item, hoopla.itemNumber,
	  hoopla.object, hoopla.player_id);
  *client << buffer;
}


bool
GraphicMessages::sendChunkData(Client* client, char* const* args)
{
  const Server*	server = this->getServer();
  const Chunk*	chunk;
  char		buffer[0x1000];
  unsigned int	x;
  unsigned int	y;
  unsigned int	hx;
  unsigned int	hy;
  bool		valid;

  x = atoi(args[1]);
  y = atoi(args[2]);

  valid = IS_GOOD_CHUNK_POS(x, y, server);
  if (valid == false)
    LogManagerSingleton::access()->error.print("Trying to get an invalid chunk : %d/%d.",
					       x, y);
  else
    {
      chunk = &server->getChunk(x, y);
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
  const Server*	server = this->getServer();
  unsigned int	x;
  unsigned int	y;
  bool		valid;

  x = atoi(args[1]);
  y = atoi(args[2]);

  valid = IS_GOOD_HOOPLA_POS(x, y, server);
  if (valid == false)
    LogManagerSingleton::access()->error.print("Trying to get an invalid hoopla : %d/%d.",
					       x, y);
  else
    this->sendHooplaData(client,
			 server->getChunk(x / CHUNK_SIZE, y / CHUNK_SIZE)
			 .getHoopla(x % CHUNK_SIZE, y % CHUNK_SIZE),
			 x, y);

  return (valid);
}
