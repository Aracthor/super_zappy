//
// GameData.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:26:40 2014 
// Last Update Tue Nov  4 10:50:23 2014 
//

const Team*
GameData::getTeams() const
{
  return (m_teams.getData());
}

unsigned int
GameData::getTeamsNumber() const
{
  return (m_teamsNumber);
}

unsigned int
GameData::getSpeed() const
{
  return (m_speed);
}
