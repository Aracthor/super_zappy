//
// LogManager.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:47:07 2014 
// Last Update Fri Dec  5 14:26:59 2014 
//

#ifndef LOG_MANAGER_HH_
# define LOG_MANAGER_HH_

# include "ConsoleLog.hh"
# include "abstractions/SigsegvHandler.hh"
# include "threading/Mutex.hh"
# include "usefull/Singleton.hh"

# include <cstdarg>

# define CONSOLE_BUFFER_SIZE	(0x10000)
# define LOGS_NUMBER		(11)

class		LogManager : public SigsegvHandler
{
public:
  typedef Buffer<CONSOLE_BUFFER_SIZE>	ConsoleBuffer;

private:
  ConsoleBuffer*	m_buffer;
  Mutex			m_lock;
  int			m_fd;
  bool			m_consoleMode;
  Log*			m_logs[LOGS_NUMBER + 1];

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

  inline ConsoleBuffer*		getBuffer();
  inline const Log* const*	getLogList() const;

  inline void		addToFile(const char* message);

  friend class	Singleton<LogManager>;
};

# include "LogManager.hpp"

typedef Singleton<LogManager>	LogManagerSingleton;

#endif // !LOG_MANAGER_HH_
