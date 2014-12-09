//
// ReadableFromZCSV.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Dec  5 10:19:59 2014 
// Last Update Tue Dec  9 10:19:32 2014 
//

#ifndef READABLE_FROM_ZCSV_HH_
# define READABLE_FROM_ZCSV_HH_

# include <string>

# define DELIMITER_CHAR		(',')
# define DEFINITION_CHAR	(':')

# define IS_CHAR(c)	(c >= 'a' && c <= 'z')

class	ReadableFromZCSV
{
private:
  const char*	m_fileName;

public:
  ReadableFromZCSV(const char* fileName);
  virtual ~ReadableFromZCSV();

protected:
  unsigned int		read(const std::string& string, unsigned int pos, ReadableFromZCSV* data);

  template <typename T>
  unsigned int		read(const std::string& string, unsigned int pos, T& data);

public:
  virtual unsigned int	readFromString(const std::string& string, unsigned int pos) = 0;
};

# include "ReadableFromZCSV.hpp"

#endif // !READABLE_FROM_ZCSV_HH_
