//
// LogConsole.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 17:14:29 2014 
// Last Update Mon Nov 17 13:23:17 2014 
//

#ifndef LOG_CONSOLE_HH_
# define LOG_CONSOLE_HH_

# include "Console.hh"
# include "containers/Buffer.hh"
# include "ncursesxx/Color.hh"
# include "threading/Mutex.hh"

# define MAX_CONSOLE_WIDTH	(200)
# define MAX_CONSOLE_HEIGHT	(60)

class		LogConsole : public Console
{
private:
  mutable Buffer<MAX_CONSOLE_WIDTH * MAX_CONSOLE_HEIGHT>	m_buffer;
  nc::Color	m_colors[COLORS_NUMBER];

public:
  LogConsole();
  ~LogConsole();

public:
  void	update();

private:
  void		printLine(const char* buffer, const char* line) const;
  const char*	drawLine(const char* buffer, const char* line) const;

public:
  void	drawData() const;
};

#endif // !LOG_CONSOLE_HH_
