//
// ReadableFromZCSV.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Dec  5 10:29:54 2014 
// Last Update Tue Dec  9 10:22:25 2014 
//

#include "catalogs/ReadableFromZCSV.hh"
#include "exceptions/FileException.hh"

ReadableFromZCSV::ReadableFromZCSV(const char* fileName) :
  m_fileName(fileName)
{
}

ReadableFromZCSV::~ReadableFromZCSV()
{
}


unsigned int
ReadableFromZCSV::read(const std::string& string, unsigned int pos, ReadableFromZCSV* data)
{
  pos = data->readFromString(string, pos);
  if (static_cast<int>(pos) < 0)
    throw FileException(m_fileName, "Failed to read an element.");
  return (pos);
}
