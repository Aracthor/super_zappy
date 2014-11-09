//
// Player.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:37:23 2014 
// Last Update Sun Nov  9 08:20:39 2014 
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <SFML/System/Vector2.hpp>

# include "Class.hh"
# include "Namable.hh"
# include "core/LinkedToServer.hh"
# include "map/Hoopla.hh"

class		Team;

class		Player : public Namable,
			 private LinkedToServer
{
public:
  enum		EOrientation
    {
      right,
      down,
      left,
      up
    };

private:
  const Team*	m_team;
  const Class*	m_class;
  sf::Vector2u	m_position;
  EOrientation	m_orientation;
  Hoopla::EItem	m_equipement;
  bool		m_decremented; // Used by ExecuterThread for decrementing

public:
  Player(const char* name, const Team* team, const Class* refToClass);
  ~Player();

public:
  bool	move();
  void	rotate(int rotation);
  void	send(const char* message);
  void	vsend(const char* message, ...);

public:
  inline const Team*		getTeam() const;
  inline const Class*		getClass() const;
  inline const sf::Vector2u&	getPosition() const;
  inline EOrientation		getOrientation() const;
  inline Hoopla::EItem		getEquipement() const;
  inline bool			isDecremented() const;

  inline unsigned int		getSpeedCoef() const;

  inline void		        setDecremented(bool decremented);
};

# include "Player.hpp"

#endif // !PLAYER_HH_
