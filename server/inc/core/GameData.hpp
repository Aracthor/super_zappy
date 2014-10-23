//
// GameData.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:26:40 2014 
// Last Update Wed Oct 22 13:27:11 2014 
//

const Teams&
GameData::getTeams() const
{
  return (m_teams);
}

unsigned int
GameData::getSpeed() const
{
  return (m_speed);
}
