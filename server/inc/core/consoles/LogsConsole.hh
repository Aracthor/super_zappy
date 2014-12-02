//
// LogsConsole.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov 20 11:00:26 2014 
// Last Update Thu Nov 20 11:19:15 2014 
//

#ifndef LOGS_CONSOLE_HH_
# define LOGS_CONSOLE_HH_

# include "ColorFactory.hh"
# include "DataConsole.hh"
# include "debug/Log.hh"

# define LOGS_COLORS_NUMBER	(7)

class		LogsConsole : public DataConsole<Log>
{
private:
  ColorFactory	m_colorFactory;

public:
  LogsConsole();
  ~LogsConsole();

protected:
  void	drawElemData(const Log& log) const;

public:
  void	drawData() const;
};

#endif // !LOGS_CONSOLE_HH_
