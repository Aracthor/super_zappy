//
// Console.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 17:18:26 2014 
// Last Update Mon Nov 17 08:14:50 2014 
//

#ifndef CONSOLE_HH_
# define CONSOLE_HH_

# include "ncursesxx/Window.hh"

class		Console : public nc::Window
{
private:
  nc::Color	m_borderColor;

public:
  Console(const std::string& name);
  virtual ~Console();

public:
  virtual void	update() = 0;

public:
  virtual void	drawData() const = 0;

  void		draw() const;
};

#endif // !CONSOLE_HH_
