//
// Attacker.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 16:26:38 2014 
// Last Update Wed Dec 10 10:41:30 2014 
//

#ifndef ATTACKER_HH_
# define ATTACKER_HH_

# include "IExecutor.hh"
# include "data/Weapon.hh"

class	Attacker : public IExecutor
{
public:
  Attacker();
  ~Attacker();

private:
  void	setTargetToMaxRange(const sf::Vector2u& position, const sf::Vector2u& target,
			    unsigned int range, sf::Vector2u& finalTarget);
  void	addProjectileOnGround(const sf::Vector2u& target, Hoopla::EItem projectile);
  bool	tryToShoot(Player* player, const Weapon* weapon, const sf::Vector2u& target);

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !ATTACKER_HH_
