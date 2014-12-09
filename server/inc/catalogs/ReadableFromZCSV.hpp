//
// ReadableFromZCSV.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Dec  5 10:35:11 2014 
// Last Update Tue Dec  9 09:40:41 2014 
//

#include "map/NamesRegister.hh"

#include <cstdlib>

template <typename T>
unsigned int
ReadableFromZCSV::read(const std::string& string, unsigned int pos, T& data)
{
  unsigned int	posEnd;

  if (string[pos] == DELIMITER_CHAR)
    ++pos;
  posEnd = string.find(DELIMITER_CHAR, pos);
  if (posEnd == std::string::npos)
    posEnd = string.size();
  if (IS_CHAR(string[pos]))
    data = static_cast<T>(NamesRegisterSingleton::access()->getFromName(string.substr(pos, posEnd - pos)));
  else
    data = static_cast<T>(atoi(&string[pos]));

  return (posEnd);
}
