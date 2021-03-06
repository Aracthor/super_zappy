//
// application.hh for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:43:14 2014 Bonnet Vivien
// Last Update Thu Nov 20 13:00:08 2014 
//

#ifndef APPLICATION_HH_
# define APPLICATION_HH_

# include "ncursesxx/Window.hh"

namespace nc
{

class		Application
{
public:
  static void	urgencyEnd();

public:
  Application();
  virtual ~Application();

public:
  int	getWidth() const;
  int	getHeight() const;
  void	getWidthAndHeight(int& width, int& height) const;

public:
  void	setCursorVisibility(bool cursor);

public:
  void	clear();
  void	move(int x, int y);
  void	print(const char* message);
  void	display();

public:
  Window::Event	getEvent();
};

}

#endif // !APPLICATION_HH_
