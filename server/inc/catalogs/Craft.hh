//
// Craft.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 11:01:14 2014 
// Last Update Fri Nov 14 12:03:49 2014 
//

#ifndef CRAFT_HH_
# define CRAFT_HH_

# include "map/Hoopla.hh"

class	Craft
{
private:
  unsigned int	m_requires[Hoopla::items_number];
  unsigned int	m_time;
  unsigned int	m_level;

public:
  Craft();
  Craft(unsigned int time, unsigned int level);
  ~Craft();

public:
  inline void	addRequire(Hoopla::EItem item, unsigned int number);

public:
  inline const unsigned int*	getRequires() const;
  inline unsigned int		getTime() const;
  inline unsigned int		getLevel() const;
};

# include "Craft.hpp"

#endif // !CRAFT_HH_
