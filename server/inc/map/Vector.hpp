//
// Vector.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 12:03:54 2014 
// Last Update Mon Oct 27 13:20:04 2014 
//

template <typename T>
Vector<T>::Vector()
{
  this->x = 0;
  this->y = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& copy)
{
  this->x = copy.x;
  this->y = copy.y;
}

template <typename T>
Vector<T>::Vector(T x, T y)
{
  this->x = x;
  this->y = y;
}


template <typename T>
Vector<T>
Vector<T>::operator+(const Vector<T>& v) const
{
  return (Vector<T>(this->x + v.x, this->y + v.y));
}
