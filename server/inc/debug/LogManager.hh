//
// LogManager.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:47:07 2014 
// Last Update Tue Nov 18 10:48:30 2014 
//

#ifndef LOG_MANAGER_HH_
# define LOG_MANAGER_HH_

# include "ConsoleLog.hh"
# include "threading/Mutex.hh"
# include "util/Singleton.hh"

# include <cstdarg>
# include <cstdio>

# define CONSOLE_BUFFER_SIZE	(0x10000)
# define LOGS_NUMBER		(11)

class		LogManager
{
public:
  typedef Buffer<CONSOLE_BUFFER_SIZE>	ConsoleBuffer;

private:
  ConsoleBuffer*	m_buffer;
  Mutex			m_lock;
  FILE*			m_stream;
  bool			m_consoleMode;

  const char*		m_names[LOGS_NUMBER];
  Log**			m_logs[LOGS_NUMBER];

private:
  LogManager(const char* file);
  ~LogManager();

public:
  Log*	debug;
  Log*	input;
  Log*	output;
  Log*	graphicInput;
  Log*	graphicOutput;
  Log*	iaInput;
  Log*	iaOutput;
  Log*	intern;
  Log*  events;
  Log*	connection;
  Log*	error;

private:
  void	initStandartLogs();
  void	initConsoleLogs();
  void	initTabs();
  void	deleteLogs();

public:
  void	setConsoleMode();

public:
  Log*	getLogFromName(const char* name);

public:
  inline void		lock();
  inline void		unlock();

  inline ConsoleBuffer*	getBuffer();

  inline void		addToFile(const char* message);

  friend class	Singleton<LogManager>;
};

# include "LogManager.hpp"

typedef Singleton<LogManager>	LogManagerSingleton;

#endif // !LOG_MANAGER_HH_
