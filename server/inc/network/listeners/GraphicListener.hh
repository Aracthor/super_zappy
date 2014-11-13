//
// GraphicListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:20:41 2014 
// Last Update Wed Nov 12 10:25:24 2014 
//

#ifndef GRAPHIC_LISTENER_HH_
# define GRAPHIC_LISTENER_HH_

# include "CommandListener.hh"
# include "data/Team.hh"
# include "map/Hoopla.hh"

class			GraphicListener : public CommandListener
{
public:
  GraphicListener();
  ~GraphicListener();

private:
  bool	sendChunkData(Client* client, char* const* args) const;
  bool	sendHooplaData(Client* client, char* const* args) const;
  bool	sendPlayerData(Client* client, char* const* args) const;
  bool	sendTeamData(Client* client, char* const* args) const;
};

#endif // !GRAPHIC_LISTENER_HH_
