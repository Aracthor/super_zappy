//
// PerlinMap.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 13:28:15 2014 
// Last Update Sat Oct 25 21:39:51 2014 
//

#ifndef PERLIN_MAP_HH_
# define PERLIN_MAP_HH_

# include "HeightMap.hh"

# define PERLIN_STEP		(20)
# define PERLIN_OCTAVES		(3)
# define PERLIN_PERSISTANCE	(0.9f)
# define PERLIN_AMPLITUDE	(40)

class	PerlinMap : public HeightMap
{
private:
  float*	m_numbers;
  unsigned int	m_step;
  unsigned int	m_octavesNumber;
  unsigned int	m_maxLonger;
  unsigned int	m_maxLarger;

public:
  PerlinMap(unsigned int longer, unsigned int larger,
	    unsigned int step, unsigned int octavesNumber);
  ~PerlinMap();

private:
  void	randomiseNumbers();

private:
  float	getNumber(unsigned int x, unsigned int y) const;
  float	interpolationCos(float a, float b, float x) const;
  float	interpolationCos2D(float a, float b, float c, float d, float x, float y) const;
  float	getNoise(unsigned int x, unsigned int y) const;

protected:
  int	calcHeight(unsigned int x, unsigned int y);
};

#endif // !PERLIN_MAP_HH_
