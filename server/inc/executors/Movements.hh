//
// Movements.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 05:31:31 2014 
// Last Update Sun Nov  9 08:37:47 2014 
//

#ifndef MOVEMENTS_HH_
# define MOVEMENTS_HH_

# include <SFML/System/Vector2.hpp>

class		Movements
{
protected:
  sf::Vector2u	m_movements[4];
  sf::Vector2i	m_imovements[4];

public:
  Movements();
  virtual ~Movements();

public:
  inline const sf::Vector2u&	getMovement(unsigned int id) const;
  inline const sf::Vector2i&	getIMovement(unsigned int id) const;
};

# include "Movements.hpp"

#endif // !MOVEMENTS_HH_
