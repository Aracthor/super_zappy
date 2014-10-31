//
// AGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 17:16:51 2014 
// Last Update Tue Oct 28 19:48:01 2014 
//

#ifndef AGENERATOR_HH_
# define AGENERATOR_HH_

# include "map/Hoopla.hh"
# include "map/Vector.hh"

# define PEAK_HEIGHT		(80)

class		AGenerator
{
protected:
  typedef Vector<int>	Position;

public:
  AGenerator();
  AGenerator(unsigned int width, unsigned int height);
  virtual ~AGenerator();

protected:
  Hoopla*	m_hooplas;
  unsigned int	m_width;
  unsigned int	m_height;
  unsigned int	m_hooplasNumber;

protected:
  inline Hoopla&	getHoopla(const Position& position);
  inline const Hoopla&	getHoopla(const Position& position) const;
  inline bool		isPeak(const Hoopla& hoopla) const;
};

# include "AGenerator.hpp"

#endif // !AGENERATOR_HH_
