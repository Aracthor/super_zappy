//
// Ground.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:11:58 2014 
// Last Update Tue Dec  9 10:24:25 2014 
//

#ifndef GROUND_HH_
# define GROUND_HH_

# include "ReadableFromZCSV.hh"
# include "map/Hoopla.hh"

class		Ground : public ReadableFromZCSV
{
private:
  unsigned int	m_digTime;
  Hoopla::EItem	m_digItem;

public:
  Ground();
  ~Ground();

public:
  unsigned int	readFromString(const std::string& line, unsigned int pos);

public:
  inline unsigned int	getDigTime() const;
  inline Hoopla::EItem	getDigItem() const;
};

# include "Ground.hpp"

#endif // !GROUND_HH_
