//
// Window.cpp for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 11:18:12 2014 Bonnet Vivien
// Last Update Thu Nov 20 13:45:35 2014 
//

#include "ncursesxx/NcursesException.hh"
#include "ncursesxx/Window.hh"

namespace nc
{

Window::Window()
{
  m_win = newwin(1, 1, 0, 0);
  if (m_win == NULL)
    throw NcursesException("Cannot create window");

  m_x = 0;
  m_y = 0;
  m_width = 1;
  m_height = 1;

  this->setDefaultBorderStyle();
}

Window::Window(const std::string& name)
{
  m_win = newwin(1, 1, 0, 0);
  if (m_win == NULL)
    throw NcursesException("Cannot create window");

  m_x = 0;
  m_y = 0;
  m_width = 1;
  m_height = 1;
  m_name = name;

  this->setDefaultBorderStyle();
}

Window::~Window()
{
  if (delwin(m_win) == ERR)
    throw NcursesException("Cannot destroy window");
}


void
Window::setDefaultBorderStyle()
{
  unsigned int	i;

  for (i = 0; i < 8; ++i)
    m_borderStyle[i] = DEFAULT_BORDER_STYLE[i];
}


void
Window::activeAttr(Window::Attr attr) const
{
  if (wattron(m_win, attr) == ERR)
    throw NcursesException("Cannot active an attr in a window");
}

void
Window::disactiveAttr(Window::Attr attr) const
{
  if (wattroff(m_win, attr) == ERR)
    throw NcursesException("Cannot disactive an attr in a window");
}

void
Window::setColor(const Color& color) const
{
  this->activeAttr(color.getAttr());
}

void
Window::unsetColor(const Color& color) const
{
  this->disactiveAttr(color.getAttr());
}

void
Window::setBackground(const Color& color)
{
  wbkgdset(m_win, color.getAttr());
}


void
Window::move(int x, int y) const
{
  if (wmove(m_win, y, x))
    throw NcursesException("Cannot move in window");
}

void
Window::print(const std::string& message, ...) const
{
  va_list	list;

  va_start(list, message);
  {
    vw_printw(m_win, message.c_str(), list);
  }
  va_end(list);
}

void
Window::print(const char* message, ...) const
{
  va_list	list;

  va_start(list, message);
  {
    vw_printw(m_win, message, list);
  }
  va_end(list);
}


void
Window::enableKeyPad()
{
  if (keypad(m_win, true) == ERR)
    throw NcursesException("Cannot enable out-ascii keys");
}

void
Window::resize(int width, int height)
{
  m_width = width;
  m_height = height;
  if (wresize(m_win, height, width) == ERR)
    throw NcursesException("Cannot resize window");
}

void
Window::displace(int x, int y)
{
  m_x = x;
  m_y = y;
  if (mvwin(m_win, y, x) == ERR)
    throw NcursesException("Cannot move window");
}

void
Window::setBorderStyle(const borderStyle& style)
{
  unsigned int	i;

  for (i = 0; i < 8; ++i)
    m_borderStyle[i] = style[i];
}

void
Window::setName(const std::string& name)
{
  m_name = name;
}


void
Window::clear() const
{
  if (werase(m_win) == ERR)
    throw NcursesException("Cannot clear window");
}

void
Window::drawBorder() const
{
  int	x;

  if (wborder(m_win,
	      m_borderStyle[0], m_borderStyle[1], m_borderStyle[2], m_borderStyle[3],
	      m_borderStyle[4], m_borderStyle[5], m_borderStyle[6], m_borderStyle[7]) == ERR)
    throw NcursesException("Cannot draw window border");

  if (m_name.empty() == false)
    {
      x = m_width / 2 - m_name.size() / 2;
      if (x < 0)
	x = 0;
      this->move(x, 0);
      this->print(m_name);
    }
}

void
Window::display() const
{
  if (wrefresh(m_win) == ERR)
    throw NcursesException("Cannot clear window");
}


Window::Event
Window::getEvent()
{
  Window::Event	event;

  event = (Window::Event)wgetch(m_win);
  if (event == ERR)
    throw NcursesException("Cannot get window event");
  return (event);
}

}
