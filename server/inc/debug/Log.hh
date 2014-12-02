//
// Log.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 10:12:16 2014 
// Last Update Thu Nov 20 11:16:36 2014 
//

#ifndef LOG_HH_
# define LOG_HH_

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
  const char*	m_name;
  EColor	m_color;
  bool		m_bold;
  bool		m_active;

public:
  Log(const char* name, EColor color, bool bold, bool active);
  virtual ~Log();

public:
  void		print(const char* message, ...);
  virtual void	print(const char* message, va_list list) = 0;

public:
  inline void	setActive(bool active);

public:
  inline const char*	getName() const;
  inline EColor		getColor() const;
  inline bool		isBold() const;
  inline bool		isActive() const;
};

# include "Log.hpp"

#endif // !LOG_HH_
