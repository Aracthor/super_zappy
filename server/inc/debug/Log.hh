//
// Log.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 10:12:16 2014 
// Last Update Mon Oct 20 13:38:42 2014 
//

#ifndef ALOG_HH_
# define ALOG_HH_

# include <ostream>

# include <cstdio>

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

private:
  FILE*		m_stream;
  EColor	m_color;
  bool		m_bold;

public:
  Log(FILE* stream, EColor color, bool bold);
  virtual ~Log();

public:
  virtual void	print(const char* message, ...);
};

#endif // !ALOG_HH_
