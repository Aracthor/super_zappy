//
// Team.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 15:54:44 2014 
// Last Update Wed Nov  5 13:29:17 2014 
//

#ifndef TEAM_HH_
# define TEAM_HH_

# include "Class.hh"
# include "Namable.hh"
# include "Player.hh"
# include "containers/Array.hh"

# define MAX_TEAM_CONFIGS_TOTAL	(500)
# define MAX_PLAYERS_BY_TEAM	(42)
# define MAX_CLASSES_BY_TEAM	(10)

class			Team : public Namable
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
  Configs	m_configs;
  Array<Class>	m_classes;
  Array<Player>	m_players;
  bool	        m_discalified;

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
			 unsigned int speedLevel, unsigned int orientationLevel);

public:
   void		destroy();

public:
  inline const Array<Class>&	getClasses() const;
  inline bool			hasReadyConfig() const;
  inline const Configs&		getConfigs() const;
  inline bool			isDiscalified() const;

public:
  inline void			discalify();
};

# include "Team.hpp"

#endif // !TEAM_HH_
