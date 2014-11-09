//
// Team.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 15:59:35 2014 
// Last Update Sun Nov  9 04:04:43 2014 
//

Client*
Team::getClient() const
{
  return (m_client);
}

const Array<Class>&
Team::getClasses() const
{
  return (m_classes);
}

const Array<Player>&
Team::getPlayers() const
{
  return (m_players);
}

Array<Player>&
Team::getPlayers()
{
  return (m_players);
}

const Player&
Team::getLastPlayer() const
{
  return (m_players[m_players.getSize() - 1]);
}

const sf::Vector2u&
Team::getSpawnPoint() const
{
  return (m_spawnPoint);
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
Team::setClient(Client* client)
{
  m_client = client;
}

void
Team::discalify()
{
  m_discalified = true;
}

void
Team::setSpawnPoint(const sf::Vector2u& pos)
{
  m_spawnPoint = pos;
}
