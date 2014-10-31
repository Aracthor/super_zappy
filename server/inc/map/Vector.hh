//
// Vector.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 11:03:05 2014 
// Last Update Mon Oct 27 13:19:46 2014 
//

#ifndef VECTOR_HH_
# define VECTOR_HH_

template <typename T>
struct		Vector
{
public:
  T		x;
  T		y;

public:
  Vector();
  Vector(const Vector<T>& copy);
  Vector(T x, T y);

public:
  inline Vector<T>	operator+(const Vector<T>& v) const;
};

# include "Vector.hpp"

#endif // !VECTOR_HH_
