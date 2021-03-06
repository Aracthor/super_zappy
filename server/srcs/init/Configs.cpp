//
// Configs.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:44:42 2014 
// Last Update Tue Dec 16 10:31:44 2014 
//

#include "exceptions/ConfigsException.hh"
#include "init/Configs.hh"

#include <cstdio>
#include <cstdlib>

Configs::Map::Map() :
  seed(0)
{
}

Configs::Map::Map(unsigned int width, unsigned int height) :
  width(width),
  height(height),
  seed(0)
{
}


Configs::Configs() :
  m_map(DEFAULT_MAP_WIDTH, DEFAULT_MAP_HEIGHT),
  m_logFile(DEFAULT_LOG_FILE),
  m_port(DEFAULT_PORT),
  m_speed(DEFAULT_SPEED),
  m_consoleMode(DEFAULT_CONSOLE_MODE)
{
}

Configs::~Configs()
{
}


void
Configs::changeLogFile(char* arg)
{
  m_logFile = arg;
}

void
Configs::changePort(char* arg)
{
  m_port = atoi(arg);
  if (m_port < PORT_MIN || m_port > PORT_MAX)
    throw ConfigsException("Invalid port.");
}

void
Configs::changeSpeed(char* arg)
{
  m_speed = atoi(arg);
  if (m_speed < SPEED_MIN || m_speed > SPEED_MAX)
    throw ConfigsException("Invalid speed.");
}

void
Configs::changeMapWidth(char* arg)
{
  m_map.width = atoi(arg);
  if (m_map.width < MAP_SIZE_MIN || m_map.width > MAP_SIZE_MAX)
    throw ConfigsException("Invalid map width.");
}

void
Configs::changeMapHeight(char* arg)
{
  m_map.height = atoi(arg);
  if (m_map.height < MAP_SIZE_MIN || m_map.height > MAP_SIZE_MAX)
    throw ConfigsException("Invalid map height.");
}

void
Configs::changeMapSeed(char* arg)
{
  m_map.seed = atol(arg);
}

void
Configs::addTeam(char* team)
{
  m_teams.addTeam(team);
}


void
Configs::emplFlagsTabs(ParamReader* readers, char* flags)
{
  readers[0] = &Configs::changePort;
  readers[1] = &Configs::changeSpeed;
  readers[2] = &Configs::changeMapWidth;
  readers[3] = &Configs::changeMapHeight;
  readers[4] = &Configs::addTeam;
  readers[5] = &Configs::changeLogFile;
  readers[6] = &Configs::changeMapSeed;

  flags[0] = 'p';
  flags[1] = 's';
  flags[2] = 'x';
  flags[3] = 'y';
  flags[4] = 'n';
  flags[5] = 'l';
  flags[6] = 'g';
}

void
Configs::changeReader(char flag)
{
  ParamReader	readers[FLAGS_NUMBER];
  ParamReader	newReader;
  char		flags[FLAGS_NUMBER];
  char		error[0x1000];
  unsigned int	i;

  this->emplFlagsTabs(readers, flags);

  newReader = NULL;
  for (i = 0; newReader == NULL && i < FLAGS_NUMBER; ++i)
    if (flag == flags[i])
      newReader = readers[i];

  if (newReader == NULL)
    {
      if (flag == CONSOLE_FLAG)
	m_consoleMode = true;
      else
	{
	  sprintf(error, "Unknow flag '%c'", flag);
	  throw ConfigsException(error);
	}
    }
  else
    m_paramReader = newReader;
}

void
Configs::readArg(char* arg)
{
  if (arg[0] == '-')
    changeReader(arg[1]);
  else
    (this->*m_paramReader)(arg);
}

void
Configs::readConfigs(int argc, char** argv)
{
  int		i;

  m_paramReader = &Configs::addTeam;
  for (i = 1; i < argc; ++i)
    this->readArg(argv[i]);

  if (m_teams.getNumber() < TEAMS_NUMBER_MIN)
    throw ConfigsException("Minimum teams number is 2.");
}
