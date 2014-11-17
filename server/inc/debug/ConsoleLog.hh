//
// ConsoleLog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:24:50 2014 
// Last Update Mon Nov 17 16:42:52 2014 
//

#ifndef CONSOLE_LOG_HH_
# define CONSOLE_LOG_HH_

# include "Log.hh"
# include "containers/Buffer.hh"
# include "threading/Mutex.hh"

class				ConsoleLog : public Log
{
public:
  ConsoleLog(EColor color, bool bold, bool active);
  ~ConsoleLog();

private:
  void	addToLogs(const char* message, unsigned int size);

public:
  void	print(const char* message, va_list list);
};

#endif // !CONSOLE_LOG_HH_
