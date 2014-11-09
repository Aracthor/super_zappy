//
// Displacer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:00:20 2014 
// Last Update Sun Nov  9 09:08:53 2014 
//

#include "executors/Displacer.hh"
#include "executors/displacers/AdeptDisplacer.hh"
#include "executors/displacers/ApprenticeDisplacer.hh"
#include "executors/displacers/ExpertDisplacer.hh"
#include "executors/displacers/MasterDisplacer.hh"

Displacer::Displacer()
{
  m_methods[Class::apprentice]	= new ApprenticeDisplacer;
  m_methods[Class::adept]	= new AdeptDisplacer;
  m_methods[Class::expert]	= new ExpertDisplacer;
  m_methods[Class::master]	= new MasterDisplacer;
}

Displacer::~Displacer()
{
  unsigned int	i;

  for (i = 0; i < SKILL_LEVEL_MAX; ++i)
    delete (m_methods[i]);
}


void
Displacer::execute(Player* player, const Action::UData& data)
{
  sf::Vector2u	destination;
  unsigned int	orientationLevel;

  destination = sf::Vector2u(data.position.x, data.position.y);

  orientationLevel = player->getClass()->getSkillLevel(Class::orientation);

  if (m_methods[orientationLevel - 1]->search(player->getPosition(), destination) == true)
    m_methods[orientationLevel - 1]->confirmMovement(player);
  else
    player->send("END false");
}
