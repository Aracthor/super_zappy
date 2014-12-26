//
// application.cpp for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
//
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:46:07 2014 Bonnet Vivien
// Last Update Thu Nov 20 13:00:52 2014 
//

#include "ncursesxx/Application.hh"
#include "ncursesxx/NcursesException.hh"

#include <ncurses/curses.h>

namespace nc
{

void
Application::urgencyEnd()
{
  if (curs_set(true) == ERR)
    throw NcursesException("Cannot change cursor visibility");
  if (endwin() == ERR)
    throw NcursesException("Cannot stop Ncurses");
}


Application::Application()
{
  if (initscr() == NULL)
    throw NcursesException("Cannot init ncurses");
  if (noecho() == ERR)
    throw NcursesException("Cannot cancel echo");
  if (keypad(stdscr, true) == ERR)
    throw NcursesException("Cannot enable out-ascii keys");
  if (start_color() == ERR)
    throw NcursesException("Cannot enable colors");
}

Application::~Application()
{
  this->clear();
  this->setCursorVisibility(true);
  if (endwin() == ERR)
    throw NcursesException("Cannot stop Ncurses");
}


int
Application::getWidth() const
{
  int	width;
  int	height;

  this->getWidthAndHeight(width, height);
  return (width);
}

int
Application::getHeight() const
{
  int	width;
  int	height;

  this->getWidthAndHeight(width, height);
  return (height);
}

void
Application::getWidthAndHeight(int& width, int& height) const
{
  getmaxyx(stdscr, height, width);
}


void
Application::setCursorVisibility(bool visibility)
{
  if (curs_set(visibility) == ERR)
    throw NcursesException("Cannot change cursor visibility");
}


void
Application::clear()
{
  if (erase() == ERR)
    throw NcursesException("Cannot clear application");
}

void
Application::move(int x, int y)
{
  if (::move(x, y))
    throw NcursesException("Cannot move in application");
}

void
Application::print(const char* message)
{
  if (printw("%s", message))
    throw NcursesException("Cannot print in application");
}

void
Application::display()
{
  if (refresh() == ERR)
    throw NcursesException("Cannot refresh application");
}


Window::Event
Application::getEvent()
{
  Window::Event	event;

  event = static_cast<Window::Event>(getch());
  if (event == ERR)
    throw NcursesException("Cannot get application event");
  return (event);
}

}
