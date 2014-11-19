//
// Team.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 15:54:44 2014 
// Last Update Tue Nov 18 15:18:16 2014 
//

#ifndef TEAM_HH_
# define TEAM_HH_

# include "Class.hh"
# include "Namable.hh"
# include "Player.hh"
# include "containers/Array.hh"
# include "core/LinkedToServer.hh"
# include "network/Client.hh"

# define MAX_TEAM_CONFIGS_TOTAL	(500)
# define MAX_PLAYERS_BY_TEAM	(42)
# define MAX_CLASSES_BY_TEAM	(10)

class			Client;
class			Server;

class			Team : public Namable,
			       private LinkedToServer
{
public:
  struct		Configs
  {
    bool	        ready;
    unsigned int	population;
    unsigned int	wealth;
    unsigned int        versatility;
    unsigned int	geneticHardening;
    unsigned int        skillsCapacity;
  };

private:
  mutable Client*	m_client;
  Configs		m_configs;
  Array<Class>		m_classes;
  Array<Player>		m_players;
  sf::Vector2u		m_spawnPoint;
  bool	        	m_discalified;

public:
  Team(const char* name);
  Team(const Team& copy);
  ~Team();

private:
  const Class*	getClassFromName(const char* name) const;

public:
  const char*	setConfigs(unsigned int population, unsigned int wealth,
			   unsigned int versatility, unsigned int geneticHardening,
			   unsigned int skills_capacity);
  bool		addPlayer(const char* name, const char* className);
  const char*	addClass(const char* name,
			 unsigned int s, unsigned int p,
			 unsigned int d, unsigned int t, unsigned int i,
			 unsigned int speedLevel, unsigned int orientationLevel,
			 unsigned int craftingLevel, unsigned int buildingLevel);

public:
  void		destroy();
  void		reset();

public:
  inline Client*		getClient() const;
  inline const Array<Class>&	getClasses() const;
  inline const Array<Player>&	getPlayers() const;
  inline Array<Player>&		getPlayers();
  inline const Player&		getLastPlayer() const;
  inline const sf::Vector2u&	getSpawnPoint() const;
  inline bool			hasReadyConfig() const;
  inline const Configs&		getConfigs() const;
  inline bool			isDiscalified() const;

public:
  inline void			setClient(Client* client);
  inline void			discalify();
  inline void		        setSpawnPoint(const sf::Vector2u& pos);
};

# include "Team.hpp"

#endif // !TEAM_HH_
