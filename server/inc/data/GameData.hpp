//
// GameData.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:26:40 2014 
// Last Update Sat Nov  8 23:54:19 2014 
//

const Team*
GameData::getTeams() const
{
  return (m_teams.getData());
}

Team*
GameData::getTeamFromName(const char* name)
{
  return ((Team*)this->getTeam(name));
}

unsigned int
GameData::getTeamsNumber() const
{
  return (m_teamsNumber);
}

bool
GameData::isStarted() const
{
  return (m_started);
}

Player*
GameData::getPlayerFromName(const char* name)
{
  return (const_cast<Player*>(this->getPlayer(name)));
}

void
GameData::startGame()
{
  m_started = true;
}
