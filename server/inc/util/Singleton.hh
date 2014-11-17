//
// Singleton.hh for libgl in /home/aracthor/programs/fun/libgl
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Sep 10 14:14:31 2014 
// Last Update Mon Nov 17 13:28:07 2014 
//

#ifndef SINGLETON_HH_
# define SINGLETON_HH_

template <class T>
class		Singleton
{
private:
  static T*	s_singleton;

public:
  template <typename U>
  static void	create(const U& elem);
  static void	create();
  static T*	access();
  static void	destroy();
};

#include "Singleton.hpp"

#endif // !SINGLETON_HH_
