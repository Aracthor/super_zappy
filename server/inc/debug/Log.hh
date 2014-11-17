//
// Log.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 10:12:16 2014 
// Last Update Mon Nov 17 13:45:32 2014 
//

#ifndef ALOG_HH_
# define ALOG_HH_

# include <ostream>

# include <cstdarg>

# define DEBUG_COLOR		(StandartLog::white)
# define INPUT_COLOR		(StandartLog::blue)
# define OUTPUT_COLOR		(StandartLog::blue)
# define GRAPHIC_INPUT_COLOR	(StandartLog::cyan)
# define GRAPHIC_OUTPUT_COLOR	(StandartLog::cyan)
# define IA_INPUT_COLOR		(StandartLog::magenta)
# define IA_OUTPUT_COLOR	(StandartLog::magenta)
# define INTERN_COLOR		(StandartLog::white)
# define THREADING_COLOR	(StandartLog::green)
# define CONNECTION_COLOR	(StandartLog::yellow)
# define ERROR_COLOR		(StandartLog::red)

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

class		Log
{
public:
  enum		EColor
  {
    black,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white
  };

protected:
  EColor	m_color;
  bool		m_bold;
  bool		m_active;

public:
  Log(EColor color, bool bold, bool active);
  virtual ~Log();

public:
  void		print(const char* message, ...);
  virtual void	print(const char* message, va_list list) = 0;
};

#endif // !ALOG_HH_
