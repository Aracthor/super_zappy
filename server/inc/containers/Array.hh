//
// Array.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 10:40:19 2014 
// Last Update Tue Nov  4 15:07:12 2014 
//

#ifndef ARRAY_HH_
# define ARRAY_HH_

template <typename T>
class		Array
{
private:
  unsigned int	m_maxSize;
  unsigned int	m_size;
  T*		m_data;

public:
  Array();
  ~Array();

public:
  void	resize(unsigned int size);
  void	free();

public:
  void	push(const T& elem);
  bool	securePush(const T& elem);

public:
  inline bool		isFull() const;
  inline unsigned int	getSize() const;
  inline const T*	getData() const;
  inline T*		getData();

public:
  inline void		operator<<(const T& elem);
  inline const T&	operator[](unsigned int id) const;
  inline T&		operator[](unsigned int id);
};

# include "Array.hpp"

#endif // !ARRAY_HH_
