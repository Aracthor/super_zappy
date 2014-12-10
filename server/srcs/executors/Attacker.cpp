//
// Attacker.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 16:26:42 2014 
// Last Update Wed Dec 10 13:47:15 2014 
//

#include "abstractions/strings.hh"
#include "executors/Attacker.hh"

Attacker::Attacker()
{
}

Attacker::~Attacker()
{
}


void
Attacker::setTargetToMaxRange(const sf::Vector2u& position, const sf::Vector2u& target,
			      unsigned int range, sf::Vector2u& finalTarget)
{
  float	coef;

  coef = static_cast<float>(range) / static_cast<float>(DISTANCE(position, target));
  finalTarget.x = position.x + static_cast<float>((target.x - position.x) * coef);
  finalTarget.y = position.y + static_cast<float>((target.y - position.y) * coef);
}

void
Attacker::addProjectileOnGround(const sf::Vector2u& target, Hoopla::EItem projectile)
{
  Hoopla&	hoopla = this->getServerData()->getHoopla(target);

  // TOCONSIDER put the projectile on another hoopla close than target if this one is full.
  if (IS_EMPTY(hoopla) &&
      (hoopla.item == Hoopla::none || hoopla.item == projectile))
    {
      hoopla.item = projectile;
      ++hoopla.itemNumber;
      this->getServerData()->sayToGraphicClients(hoopla);
    }
}

static int
isOnHoopla(const Player& player, const sf::Vector2u& target)
{
  return (player.getPosition() == target);
}

bool
Attacker::tryToShoot(Player* player, const Weapon* weapon, const sf::Vector2u& target)
{
  sf::Vector2u	finalTarget;
  Player*	playerTargeted;
  Hoopla::EItem	projectile;
  unsigned int	maxRange;

  maxRange = player->getClass()->getSkillLevel(Class::shoot) * weapon->getRange();
  if (DISTANCE(player->getPosition(), target) > maxRange)
    this->setTargetToMaxRange(player->getPosition(), target, maxRange, finalTarget);
  else
    finalTarget = target;

  projectile = weapon->getProjectile();
  // TODO say to graphical clients a projectile is throwed

  playerTargeted = this->getServerData()->findPlayer(&isOnHoopla, finalTarget);
  if (playerTargeted == NULL)
    this->addProjectileOnGround(finalTarget, projectile);
  else
    playerTargeted->hurt(weapon->getDamages());

  weapon->onUse(player);

  return (playerTargeted != NULL);
}

void
Attacker::execute(Player* player, const Action::UData& data)
{
  bool	hit;

  hit = false;
  if (player->getEquipement() != NULL && player->getEquipement()->isWeapon() &&
      player->getClass()->getSkillLevel(Class::shoot) > 0)
    hit = this->tryToShoot(player, static_cast<const Weapon*>(player->getEquipement()),
			   sf::Vector2u(data.position.x, data.position.y));

  player->vsend("END %s", BOOLEAN_TO_STRING(hit));
}
