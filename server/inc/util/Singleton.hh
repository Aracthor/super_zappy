//
// Singleton.hh for libgl in /home/aracthor/programs/fun/libgl
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Sep 10 14:14:31 2014 
// Last Update Mon Oct 20 08:46:30 2014 
//

#ifndef SINGLETON_HH_
# define SINGLETON_HH_

template <class T>
class		Singleton
{
private:
  static T*	s_singleton;

public:
  static void	create();
  static T*	access();
  static void	destroy();
};

#include "Singleton.hpp"

#endif // !SINGLETON_HH_
