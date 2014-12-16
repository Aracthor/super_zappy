//
// DataConsole.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 09:11:23 2014 
// Last Update Thu Dec 11 09:27:20 2014 
//

#ifndef DATA_CONSOLE_HH_
# define DATA_CONSOLE_HH_

# include "Console.hh"
# include "core/LinkedToServer.hh"

# define DATA_CONSOLES_NUMBER	(4)

template <typename T>
class		DataConsole : public Console,
			      protected LinkedToServer
{
public:
  DataConsole(const char* name);
  virtual ~DataConsole();

protected:
  virtual void	drawElemData(const T& elem) const = 0;
  void		drawElem(const T& elem, unsigned int index) const;

public:
  void	update();
};

# include "DataConsole.hpp"

#endif // !DATA_CONSOLE_HH_
