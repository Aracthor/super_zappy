//
// Ground.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:11:57 2014 
// Last Update Tue Dec  9 10:24:32 2014 
//

#include "catalogs/Ground.hh"

Ground::Ground() :
  ReadableFromZCSV("grounds.zcsv")
{
}

Ground::~Ground()
{
}


unsigned int
Ground::readFromString(const std::string& string, unsigned int pos)
{
  pos = this->read(string, pos, m_digTime);
  pos = this->read(string, pos, m_digItem);
  return (pos);
}
