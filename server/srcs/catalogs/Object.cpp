//
// Object.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:47:39 2014 
// Last Update Tue Dec  9 10:28:29 2014 
//

#include "catalogs/Object.hh"

Object::Object() :
  ReadableFromZCSV("objects.zcsv"),
  m_production("objects.zcsv")
{
}

Object::~Object()
{
}


unsigned int
Object::readFromString(const std::string& string, unsigned int pos)
{
  pos = this->read(string, pos, &m_production);
  pos = this->read(string, pos, m_destroyTime);
  pos = this->read(string, pos, m_destroyable);
  return (pos);
}
