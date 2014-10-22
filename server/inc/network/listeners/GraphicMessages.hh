//
// GraphicMessages.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 11:35:13 2014 
// Last Update Wed Oct 22 12:56:40 2014 
//

#ifndef GRAPHIC_MESSAGES_HH_
# define GRAPHIC_MESSAGES_HH_

# include "map/Hoopla.hh"

class	Client;
class	Server;

class	GraphicMessages
{
protected:
  typedef bool	(GraphicMessages::*CommandExecution)(Client* client, char* const* args);

private:
  const Server*	m_server;

protected:
  GraphicMessages();
  virtual ~GraphicMessages();

private:
  const Server*	getServer();

private:
  void	sendHooplaData(Client* client, const Hoopla& hoopla, unsigned int x, unsigned int y);

public:
  bool	sendChunkData(Client* client, char* const* args);
  bool	sendHooplaData(Client* client, char* const* args);
};

#endif // !GRAPHIC_MESSAGES_HH_
