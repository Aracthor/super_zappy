//
// Namable.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:44:13 2014 
// Last Update Thu Dec 11 08:49:34 2014 
//

#ifndef NAMABLE_HH_
# define NAMABLE_HH_

class	Namable
{
private:
  char*	m_name;

protected:
  Namable();
  Namable(const char* name);
  Namable(const Namable& copy);
  virtual ~Namable();

public:
  inline const char*	getName() const;

public:
  void			destroy();

public:
  inline Namable&	operator=(const Namable& copy);
};

# include "Namable.hpp"

#endif // !NAMABLE_HH_
