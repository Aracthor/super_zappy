//
// Team.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 15:59:55 2014 
// Last Update Wed Dec 10 12:57:47 2014 
//

#include "abstractions/allocs.hh"
#include "core/Server.hh"
#include "data/Team.hh"
#include "security/CheatChecker.hh"

#include <cstddef>
#include <cstring>

Team::Team(const char* name) :
  Namable(name),
  m_client(NULL),
  m_discalified(false)
{
  this->reset();
}

Team::Team(const Team& copy) :
  Namable(copy),
  m_client(NULL),
  m_discalified(false)
{
  this->reset();
}

Team::~Team()
{
  this->destroy();
}


const Class*
Team::getClassFromName(const char* name) const
{
  const Class*	classRef;
  unsigned int	i;

  classRef = NULL;

  for (i = 0; classRef == NULL && i < m_configs.versatility; ++i)
    if (!strcmp(m_classes[i].getName(), name))
      classRef = &m_classes[i];

  return (classRef);
}


const char*
Team::setConfigs(unsigned int population, unsigned int wealth,
		 unsigned int versatility, unsigned int geneticHardening,
		 unsigned int skillsCapacity)
{
  const char*	error = NULL;

  if (population * 10 + wealth + versatility * 10 + geneticHardening + skillsCapacity >
      MAX_TEAM_CONFIGS_TOTAL)
    error = "Invalid config sum";

  if (error == NULL)
    {
      m_configs.ready = true;
      m_configs.population = population;
      m_configs.wealth = wealth;
      m_configs.versatility = versatility;
      m_configs.geneticHardening = geneticHardening;
      m_configs.skillsCapacity = skillsCapacity;

      m_players.resize(m_configs.population);
      m_classes.resize(m_configs.versatility);
    }

  return (error);
}

bool
Team::addPlayer(const char* name, const char* className)
{
  const Class*	classRef;
  bool		valid;

  classRef = this->getClassFromName(className);
  valid = (classRef != NULL);

  if (valid)
    valid = m_players.securePush(Player(name, this, classRef));

  return (valid);
}

const char*
Team::addClass(const char* name,
	       unsigned int s, unsigned int p,
	       unsigned int d, unsigned int t, unsigned int i,
	       unsigned int speedLevel, unsigned int orientationLevel,
	       unsigned int craftingLevel, unsigned int buildingLevel, unsigned int shootLevel)
{
  Class		newClass(name, s, p, d, t, i,
			 speedLevel, orientationLevel, craftingLevel, buildingLevel, shootLevel);
  const char*	error;

  error = CheatCheckerSingleton::access()->checkClass(newClass,
						      m_configs.geneticHardening,
						      m_configs.skillsCapacity);
  if (error == NULL)
    {
      if (m_classes.securePush(newClass) == false)
	error = "Too many classes";
    }

  return (error);
}


void
Team::destroy()
{
  if (m_configs.ready)
    {
      m_players.free();
      m_classes.free();
    }
  Namable::destroy();
}

void
Team::reset()
{
  m_configs.ready = false;
  m_players.free();
  m_classes.free();
  if (m_client != NULL)
    {
      m_client->send(REBOOT_MESSAGE LINE_SEPARATOR_STR);
      this->getServerData()->kickClient(m_client, true);
      m_client = NULL;
    }
}
