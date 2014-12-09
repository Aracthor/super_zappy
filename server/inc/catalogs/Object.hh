//
// Object.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:42:40 2014 
// Last Update Tue Dec  9 10:27:54 2014 
//

#ifndef OBJECT_HH_
# define OBJECT_HH_

# include "Production.hh"
# include "ReadableFromZCSV.hh"
# include "map/Hoopla.hh"

class		Object : public ReadableFromZCSV
{
private:
  Production	m_production;
  unsigned int	m_destroyTime;
  bool		m_destroyable;

public:
  Object();
  ~Object();

public:
  unsigned int	readFromString(const std::string& string, unsigned int pos);

public:
  inline const Production&	getProduction() const;
  inline unsigned int		getDestroyTime() const;
  inline bool			isDestroyable() const;
};

# include "Object.hpp"

#endif // !OBJECT_HH_
