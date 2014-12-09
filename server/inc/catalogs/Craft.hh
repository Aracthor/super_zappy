//
// Craft.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 11:01:14 2014 
// Last Update Tue Dec  9 10:24:13 2014 
//

#ifndef CRAFT_HH_
# define CRAFT_HH_

# include "ReadableFromZCSV.hh"
# include "map/Hoopla.hh"

class		Craft : public ReadableFromZCSV
{
private:
  unsigned int	m_time;
  unsigned int	m_level;
  unsigned int	m_requires[Hoopla::items_number];

public:
  Craft();
  ~Craft();

public:
  unsigned int	readFromString(const std::string& string, unsigned int pos);

public:
  inline void	addRequire(Hoopla::EItem item, unsigned int number);

public:
  inline const unsigned int*	getRequires() const;
  inline unsigned int		getTime() const;
  inline unsigned int		getLevel() const;
};

# include "Craft.hpp"

#endif // !CRAFT_HH_
