//
// LogManager.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:47:07 2014 
// Last Update Mon Oct 20 13:49:34 2014 
//

#ifndef LOG_MANAGER_HH_
# define LOG_MANAGER_HH_

# include "Log.hh"
# include "util/Singleton.hh"

# define INPUT_COLOR		(Log::cyan)
# define OUTPUT_COLOR		(Log::cyan)
# define INTERN_COLOR		(Log::white)
# define THREADING_COLOR	(Log::green)
# define CONNECTION_COLOR	(Log::yellow)
# define ERROR_COLOR		(Log::red)

# define INPUT_BOLD		(true)
# define OUTPUT_BOLD		(false)
# define INTERN_BOLD		(true)
# define THREADING_BOLD		(true)
# define CONNECTION_BOLD	(true)
# define ERROR_BOLD		(true)

class		LogManager
{
private:
  LogManager();
  ~LogManager();

public:
  Log		input;
  Log		output;
  Log		intern;
  Log		threading;
  Log		connection;
  Log		error;

  friend class	Singleton<LogManager>;
};

typedef Singleton<LogManager>	LogManagerSingleton;

#endif // !LOG_MANAGER_HH_
