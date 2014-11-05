//
// Team.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 15:59:35 2014 
// Last Update Wed Nov  5 13:29:30 2014 
//

const Array<Class>&
Team::getClasses() const
{
  return (m_classes);
}

bool
Team::hasReadyConfig() const
{
  return (m_configs.ready);
}

const Team::Configs&
Team::getConfigs() const
{
  return (m_configs);
}

bool
Team::isDiscalified() const
{
  return (m_discalified);
}


void
Team::discalify()
{
  m_discalified = true;
}
