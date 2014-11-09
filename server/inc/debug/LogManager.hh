//
// LogManager.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:47:07 2014 
// Last Update Sun Nov  9 02:37:21 2014 
//

#ifndef LOG_MANAGER_HH_
# define LOG_MANAGER_HH_

# include "Log.hh"
# include "util/Singleton.hh"

# define DEBUG_COLOR		(Log::white)
# define INPUT_COLOR		(Log::blue)
# define OUTPUT_COLOR		(Log::blue)
# define GRAPHIC_INPUT_COLOR	(Log::cyan)
# define GRAPHIC_OUTPUT_COLOR	(Log::cyan)
# define IA_INPUT_COLOR		(Log::magenta)
# define IA_OUTPUT_COLOR	(Log::magenta)
# define INTERN_COLOR		(Log::white)
# define THREADING_COLOR	(Log::green)
# define CONNECTION_COLOR	(Log::yellow)
# define ERROR_COLOR		(Log::red)

# define DEBUG_BOLD		(false)
# define INPUT_BOLD		(true)
# define OUTPUT_BOLD		(false)
# define GRAPHIC_INPUT_BOLD	(true)
# define GRAPHIC_OUTPUT_BOLD	(false)
# define IA_INPUT_BOLD		(true)
# define IA_OUTPUT_BOLD		(false)
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
  Log		debug;
  Log		input;
  Log		output;
  Log		graphicInput;
  Log		graphicOutput;
  Log		iaInput;
  Log		iaOutput;
  Log		intern;
  Log		threading;
  Log		connection;
  Log		error;

  friend class	Singleton<LogManager>;
};

typedef Singleton<LogManager>	LogManagerSingleton;

#endif // !LOG_MANAGER_HH_
