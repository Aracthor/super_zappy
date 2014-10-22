//
// Singleton.hpp for libgl in /home/aracthor/programs/fun/libgl
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun 16 10:01:02 2014 
// Last Update Mon Oct 20 08:46:18 2014 
//

#include <cstddef>

template <class T>
T*
Singleton<T>::s_singleton = NULL;


template <class T>
void
Singleton<T>::create()
{
  s_singleton = new T;
}

template <class T>
T*
Singleton<T>::access()
{
  return (s_singleton);
}

template <class T>
void
Singleton<T>::destroy()
{
  delete (s_singleton);
}
