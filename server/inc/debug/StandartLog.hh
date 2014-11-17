//
// StandartLog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 15:59:19 2014 
// Last Update Mon Nov 17 12:38:10 2014 
//

#ifndef STANDART_LOG_HH_
# define STANDART_LOG_HH_

# include "Log.hh"

# include <cstdio>

class		StandartLog : public Log
{
private:
  FILE*		m_stream;

public:
  StandartLog(FILE* stream, EColor color, bool bold, bool active);
  ~StandartLog();

public:
  void	print(const char* message, va_list list);
};


#endif // !STANDART_LOG_HH_
