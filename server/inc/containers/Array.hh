//
// Array.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec 11 09:42:17 2014 
// Last Update Thu Dec 11 10:18:30 2014 
//

#ifndef ARRAY_HH_
# define ARRAY_HH_

# include <vector>

template <class T>
class	Array : public std::vector<T*>
{
public:
  Array();
  Array(unsigned int size);
  Array(const Array<T>& ref);
  ~Array();

public:
  inline void		resize(unsigned int number);

public:
  inline bool		isFull() const;

public:
  inline Array<T>&	operator<<(const T& elem);

public:
  inline const T&	operator[](unsigned int id) const;
  inline T&		operator[](unsigned int id);
};

# include "Array.hpp"

#endif // !ARRAY_HH_
