//
// FileException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Dec  5 13:27:22 2014 
// Last Update Fri Dec  5 13:30:13 2014 
//

#ifndef FILE_EXCEPTION_HH_
# define FILE_EXCEPTION_HH_

# include "ZappyException.hh"

class	FileException : public ZappyException
{
public:
  FileException(const char* file, const char* message);
  ~FileException() throw();
};

#endif // !FILE_EXCEPTION_HH_
