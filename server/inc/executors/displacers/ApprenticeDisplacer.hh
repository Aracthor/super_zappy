//
// ApprenticeDisplacer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:14:33 2014 
// Last Update Sun Nov  9 06:09:28 2014 
//

#ifndef APPRENTICE_DISPLACER_HH_
# define APPRENTICE_DISPLACER_HH_

# include "DisplacerMethod.hh"

class	ApprenticeDisplacer : public DisplacerMethod
{
public:
  ApprenticeDisplacer();
  ~ApprenticeDisplacer();

private:
  bool	tryHorizontalMovement(const sf::Vector2u& pos, const sf::Vector2u& dest);
  bool	tryVerticalMovement(const sf::Vector2u& pos, const sf::Vector2u& dest);
  bool	tryNextPoint(const sf::Vector2u& pos, const sf::Vector2u& dest);
  bool	tryToJoin(const sf::Vector2u& pos, const sf::Vector2u& dest, bool first);

public:
  bool	search(const sf::Vector2u& origin, const sf::Vector2u& dest);
};

#endif // !APPRENTICE_DISPLACER_HH_
