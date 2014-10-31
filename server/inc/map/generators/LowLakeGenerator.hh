//
// LowLakeGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 17:42:04 2014 
// Last Update Tue Oct 28 15:15:48 2014 
//

#ifndef LOW_LAKE_GENERATOR_HH_
# define LOW_LAKE_GENERATOR_HH_

# include "AGenerator.hh"
# include "containers/DisposableQueue.hh"

class	LowLakeGenerator : public virtual AGenerator
{
private:
  bool*	m_oceanHooplas;

public:
  LowLakeGenerator(unsigned int width, unsigned int height);
  virtual ~LowLakeGenerator();

private:
  void	testLake(const Position& position);
  void	makeOcean(const Position& position, DisposableQueue<Position>& positionsToTry);
  void	makeOceans();

public:
  void	emplLowLakes();
};

#endif // !LOW_LAKE_GENERATOR_HH_
