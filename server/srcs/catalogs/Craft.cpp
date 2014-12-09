//
// Craft.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 11:01:17 2014 
// Last Update Tue Dec  9 10:24:06 2014 
//

#include "catalogs/Craft.hh"

#include <cstring>

Craft::Craft() :
  ReadableFromZCSV("crafts.zcsv")
{
  memset(m_requires, 0, sizeof(m_requires));
}

Craft::~Craft()
{
}


unsigned int
Craft::readFromString(const std::string& string, unsigned int pos)
{
  Hoopla::EItem	item;
  unsigned int	number;

  pos = this->read(string, pos, m_time);
  pos = this->read(string, pos, m_level);

  while (pos < string.size())
    {
      pos = this->read(string, pos, item);
      pos = this->read(string, pos, number);
      this->addRequire(item, number);
    }

  return (pos);
}
