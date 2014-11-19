//
// Window.hh for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 11:15:10 2014 Bonnet Vivien
// Last Update Wed Nov 19 10:23:50 2014 
//

#ifndef WINDOW_HH_
# define WINDOW_HH_

# include <string>

# include "Color.hh"

# include <ncurses/curses.h>

# define DEFAULT_BORDER_STYLE	("||--####")

# define IS_PRINTABLE(c)	(c >= 0x20 && c < 0x7F)

namespace nc
{

class		Window
{
public:
  typedef char	borderStyle[8];
  typedef int	Attr;

public:
  enum		Event
  {
    Tab		= 0x09,
    Enter	= 0x0A,
    Escape	= 0x1B,
    Plus	= 0x2B,
    Less	= 0x2D,
    Resize	= KEY_RESIZE,
    Up		= KEY_UP,
    Down	= KEY_DOWN,
    Right	= KEY_RIGHT,
    Left	= KEY_LEFT,
    CRight	= 0x22F,
    CLeft	= 0x220,
    Del		= 0x107
  };

private:
  WINDOW*	m_win;
  borderStyle	m_borderStyle;
  int		m_x;
  int		m_y;

protected:
  std::string	m_name;
  int		m_width;
  int		m_height;

public:
  Window();
  Window(const std::string& name);
  virtual ~Window();

private:
  void	setDefaultBorderStyle();

public:
  inline WINDOW*	getWindow();
  inline int		getWidth() const;
  inline int		getHeight() const;

public:
  void	activeAttr(Attr attr) const;
  void	disactiveAttr(Attr attr) const;
  void	setColor(const Color& color) const;
  void	unsetColor(const Color& color) const;
  void	setBackground(const Color& color);

public:
  void	move(int x, int y) const;
  void	print(const std::string& str, ...) const;
  void	print(const char* str, ...) const;

public:
  void		enableKeyPad();
  virtual void	resize(int width, int height);
  virtual void	displace(int x, int y);
  void		setBorderStyle(const borderStyle& style);
  void		setName(const std::string& name);

public:
  void	clear() const;
  void	drawBorder() const;
  void	display() const;

public:
  Event	getEvent();
};

# include "Window.hpp"

}

#endif // !WINDOW_HH_
