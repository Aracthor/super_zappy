//
// Player.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:37:23 2014 
// Last Update Thu Dec 11 12:46:54 2014 
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <SFML/System/Vector2.hpp>

# include "Class.hh"
# include "Equipement.hh"
# include "Hurtable.hh"
# include "Inventory.hh"
# include "Namable.hh"
# include "actions/Action.hh"
# include "core/LinkedToServer.hh"

class		Team;

class		Player : public Namable,
			 public Hurtable,
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
  Equipement*	m_equipement;
  Inventory	m_inventory;
  Action::UData	m_currentObjective;
  bool		m_decremented; // Used by ExecuterThread for decrementing

public:
  Player(); // For containers-confrmity
  Player(const char* name, const Team* team, const Class* refToClass);
  ~Player();

// From Hurtable
public:
  void	die();
  void	hurt(unsigned int damages);
  void	heal(unsigned int healing);

public:
  void	unequip();
  void	setEquipement(Equipement* equipement);
  bool	move();
  void	rotate(int rotation);
  void	send(const char* message);
  void	vsend(const char* message, ...);

public:
  bool	canSee(const sf::Vector2u& point) const;

public:
  inline const Team*		getTeam() const;
  inline const Class*		getClass() const;
  inline const sf::Vector2u&	getPosition() const;
  inline EOrientation		getOrientation() const;
  inline const Equipement*	getEquipement() const;
  inline Hoopla::EItem		getEquipementItem() const;
  inline const Inventory&	getInventory() const;
  inline Inventory&		getInventory();
  inline const Action::UData&	getObjective() const;
  inline bool			isDecremented() const;

  inline unsigned int		getSpeedCoef() const;

  inline void		        setDecremented(bool decremented);
};

# include "Player.hpp"

#endif // !PLAYER_HH_
