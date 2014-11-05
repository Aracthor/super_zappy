//
// SkillChecker.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 13:49:22 2014 
// Last Update Tue Nov  4 14:37:12 2014 
//

#include "security/SkillChecker.hh"

#include <cstddef>

SkillChecker::SkillChecker()
{
}

SkillChecker::SkillChecker(Class::ESkill skill, const char* name,
			   bool mandatory, unsigned int price) :
  m_skill(skill),
  m_name(name),
  m_price(price),
  m_mandatory(mandatory)
{
}

SkillChecker::~SkillChecker()
{
}


const char*
SkillChecker::checkMandatory(const Class& classToCheck) const
{
  const char*	error = NULL;

  if (m_mandatory == true && classToCheck.getSkillLevel(m_skill) == 0)
    error = "Missing mandatory skill";

  return (error);
}


const char*
SkillChecker::check(const Class& classToCheck) const
{
  return (this->checkMandatory(classToCheck));
}
