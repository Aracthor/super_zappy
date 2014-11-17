//
// Configs.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:47:15 2014 
// Last Update Mon Nov 17 13:15:59 2014 
//

const Teams&
Configs::getTeams() const
{
  return (m_teams);
}

const char*
Configs::getLogFile() const
{
  return (m_logFile);
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

bool
Configs::getConsoleMode() const
{
  return (m_consoleMode);
}

const Configs::Map&
Configs::getMapConfigs() const
{
  return (m_map);
}
