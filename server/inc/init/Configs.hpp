//
// Configs.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:47:15 2014 
// Last Update Sun Oct 12 08:40:49 2014 
//

const Teams&
Configs::getTeams() const
{
  return (m_teams);
}

unsigned int
Configs::getPort() const
{
  return (m_port);
}

unsigned int
Configs::getSpeed() const
{
  return (m_speed);
}

const Configs::Map&
Configs::getMapConfigs() const
{
  return (m_map);
}
