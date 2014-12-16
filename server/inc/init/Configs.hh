//
// Configs.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:32:05 2014 
// Last Update Tue Dec 16 10:21:28 2014 
//

#ifndef CONFIGS_HH_
# define CONFIGS_HH_

# include "Teams.hh"

# define DEFAULT_LOG_FILE       ("zappy.log")
# define DEFAULT_PORT		(4242)
# define DEFAULT_SPEED		(10000)
# define DEFAULT_CONSOLE_MODE	(false)
# define DEFAULT_MAP_WIDTH	(4)
# define DEFAULT_MAP_HEIGHT	(4)

# define PORT_MIN		(0x401)
# define PORT_MAX		(0xFFFF)
# define SPEED_MIN		(1000)
# define SPEED_MAX		(10000000)
# define MAP_SIZE_MIN		(4)
# define MAP_SIZE_MAX		(256)
# define TEAMS_NUMBER_MIN	(2)

# define FLAGS_NUMBER		(7)
# define CONSOLE_FLAG		('d')

class			Configs
{
public:
  struct		Map
  {
    Map();
    Map(unsigned int width, unsigned int height);

    unsigned int	width;
    unsigned int	height;
    unsigned int	seed;
  };

private:
  typedef void	(Configs::*ParamReader)(char* arg);

private:
  Map		m_map;
  const char*	m_logFile;
  unsigned int	m_port;
  unsigned int	m_speed;
  Teams		m_teams;
  bool		m_consoleMode;
  ParamReader	m_paramReader;

public:
  Configs();
  ~Configs();

private:
  void	changeLogFile(char* port);
  void	changePort(char* port);
  void	changeSpeed(char* speed);
  void	changeMapWidth(char* width);
  void	changeMapHeight(char* height);
  void	changeMapSeed(char* seed);
  void	addTeam(char* team);

private:
  void	emplFlagsTabs(ParamReader* readers, char* flags);
  void	changeReader(char flag);
  void	readArg(char* arg);

public:
  void	readConfigs(int argc, char** argv);

public:
  inline const Teams&	getTeams() const;
  inline const char*	getLogFile() const;
  inline unsigned int	getPort() const;
  inline unsigned int	getSpeed() const;
  inline bool		getConsoleMode() const;
  inline const Map&	getMapConfigs() const;
};

#include "Configs.hpp"

#endif // !CONFIGS_HH_
