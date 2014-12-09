//
// Production.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:53:18 2014 
// Last Update Tue Dec  9 10:28:12 2014 
//

#include "catalogs/Production.hh"

Production::Production(const char* fileName) :
  ReadableFromZCSV(fileName)
{
}

Production::~Production()
{
}


unsigned int
Production::readFromString(const std::string& string, unsigned int pos)
{
  pos = this->read(string, pos, m_item);
  pos = this->read(string, pos, m_min);
  pos = this->read(string, pos, m_max);

  return (pos);
}
