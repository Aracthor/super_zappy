//
// FileException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Dec  5 13:29:12 2014 
// Last Update Fri Dec  5 13:31:54 2014 
//

#include "exceptions/FileException.hh"

FileException::FileException(const char* file, const char* message) :
  ZappyException(std::string("Problem with file '") + file + "' : " + message)
{
}

FileException::~FileException() throw()
{
}
