//
// DestroyerTimeCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov 13 17:01:21 2014 
// Last Update Thu Dec  4 10:46:33 2014 
//

#ifndef DESTROYER_TIME_CALCULATOR_HH_
# define DESTROYER_TIME_CALCULATOR_HH_

# include "ITimeCalculator.hh"
# include "catalogs/ObjectCatalog.hh"
# include "executors/Movements.hh"

class		DestroyerTimeCalculator : public ITimeCalculator
{
private:
  ObjectCatalog	m_catalog;
  Movements	m_movements;

public:
  DestroyerTimeCalculator();
  ~DestroyerTimeCalculator();

private:
  void	turnFaceToCoord(Player* player, const sf::Vector2u& pos);
  bool	getHoopla(Player* player, Hoopla** hoopla, const sf::Vector2u& pos);

public:
  unsigned int	calcTime(Player* player, const Action::UData& data);
};

#endif // !DESTROYER_TIME_CALCULATOR_HH_
