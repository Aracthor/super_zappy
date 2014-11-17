//
// Window.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 10:03:51 2014 
// Last Update Mon Nov 17 10:03:53 2014 
//

WINDOW*
Window::getWindow()
{
  return (m_win);
}

int
Window::getWidth() const
{
  return (m_width);
}

int
Window::getHeight() const
{
  return (m_height);
}
