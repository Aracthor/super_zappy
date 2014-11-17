//
// Ground.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:11:58 2014 
// Last Update Fri Nov 14 17:29:00 2014 
//

#ifndef GROUND_HH_
# define GROUND_HH_

# include "map/Hoopla.hh"

class		Ground
{
private:
  unsigned int	m_digTime;
  Hoopla::EItem	m_digItem;

public:
  Ground();
  Ground(unsigned int digTime, Hoopla::EItem digItem);
  ~Ground();

public:
  inline unsigned int	getDigTime() const;
  inline Hoopla::EItem	getDigItem() const;
};

# include "Ground.hpp"

#endif // !GROUND_HH_
