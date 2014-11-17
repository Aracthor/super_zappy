//
// Singleton.hpp for libgl in /home/aracthor/programs/fun/libgl
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun 16 10:01:02 2014 
// Last Update Mon Nov 17 13:27:48 2014 
//

#include <cstddef>

template <class T>
T*
Singleton<T>::s_singleton = NULL;


template <class T>
template <class U>
void
Singleton<T>::create(const U& elem)
{
  s_singleton = new T(elem);
}

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
