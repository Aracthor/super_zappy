//
// Production.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:51:24 2014 
// Last Update Tue Dec  9 10:27:58 2014 
//

#ifndef PRODUCTION_HH_
# define PRODUCTION_HH_

# include "ReadableFromZCSV.hh"
# include "map/Hoopla.hh"

class		Production : public ReadableFromZCSV
{
private:
  Hoopla::EItem	m_item;
  unsigned int	m_min;
  unsigned int	m_max;

public:
  Production(const char* fileName);
  ~Production();

public:
  unsigned int	readFromString(const std::string& string, unsigned int pos);

public:
  inline Hoopla::EItem	getItem() const;
  inline unsigned int	getRandomNumber() const;
};

# include "Production.hpp"

#endif // !PRODUCTION_HH_
