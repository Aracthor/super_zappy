//
// DisplacerMethod.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:06:29 2014 
// Last Update Sun Nov  9 07:12:38 2014 
//

#ifndef DISPLACER_METHOD_HH_
# define DISPLACER_METHOD_HH_

# include "containers/Pool.hh"
# include "core/LinkedToServer.hh"
# include "data/Player.hh"
# include "executors/Movements.hh"
# include "executors/SpeedCalculator.hh"

# define DISPLACEMENT_MAX_LONGER	(100)

class			DisplacerMethod : protected LinkedToServer
{
protected:
  SpeedCalculator	m_speedCalculator;
  Movements		m_movements;
  Pool<sf::Vector2u>	m_positions;
  sf::Vector2u		m_rotations[4];

public:
  DisplacerMethod();
  virtual ~DisplacerMethod();

private:
  int		turn(Player* player, int orientation, int nextOrientation);
  int		calcNextOrientation(const sf::Vector2u& pos1, const sf::Vector2u& pos2) const;
  bool		isLast(unsigned int index) const;

public:
  void		confirmMovement(Player* player);
  virtual bool	search(const sf::Vector2u& origin, const sf::Vector2u& dest) = 0;
};

#endif // !DISPLACER_METHOD_HH_
