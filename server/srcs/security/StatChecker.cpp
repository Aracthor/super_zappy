//
// StatChecker.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 13:40:45 2014 
// Last Update Wed Dec 10 13:42:00 2014 
//

#include "security/StatChecker.hh"

#include <cstddef>

StatChecker::StatChecker()
{
  m_characteristicsMin[Class::strength]		= 10;
  m_characteristicsMin[Class::perception]	= 0;
  m_characteristicsMin[Class::dexterity]	= 10;
  m_characteristicsMin[Class::toughness]	= 10;
  m_characteristicsMin[Class::intuition]	= 0;

  m_skillsCheckers[Class::speed]	= SkillChecker(Class::speed, "speed",
						       true, 10);
  m_skillsCheckers[Class::orientation]	= SkillChecker(Class::orientation, "orientation",
						       true, 10);
  m_skillsCheckers[Class::crafting]	= SkillChecker(Class::crafting, "crafting",
						       false, 10);
  m_skillsCheckers[Class::building]	= SkillChecker(Class::building, "building",
						       false, 10);
  m_skillsCheckers[Class::shoot]	= SkillChecker(Class::building, "shoot",
						       false, 10);
}

StatChecker::~StatChecker()
{
}


const char*
StatChecker::checkSkills(const Class& classToCheck) const
{
  unsigned int	skill;
  const char*	error = NULL;

  for (skill = 0; error == NULL && skill < Class::skills_number; ++skill)
    error = m_skillsCheckers[skill].check(classToCheck);

  return (error);
}


const char*
StatChecker::checkClass(const Class& classToCheck,
			unsigned int geneticHardening, unsigned int skillCapacity) const
{
  // TODO
  (void)(geneticHardening);
  (void)(skillCapacity);

  return (this->checkSkills(classToCheck));
}
