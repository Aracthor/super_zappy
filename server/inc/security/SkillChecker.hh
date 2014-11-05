//
// SkillChecker.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 13:38:24 2014 
// Last Update Tue Nov  4 14:36:28 2014 
//

#ifndef SKILL_CHECKER_HH_
# define SKILL_CHECKER_HH_

# include "data/Class.hh"

class		SkillChecker
{
private:
  Class::ESkill	m_skill;
  const char*	m_name;
  unsigned int	m_price;
  bool		m_mandatory;

public:
  SkillChecker();
  SkillChecker(Class::ESkill skill, const char* name, bool mandatory, unsigned int price);
  ~SkillChecker();

private:
  const char*	checkMandatory(const Class& classToCheck) const;

public:
  const char*	check(const Class& classToCheck) const;

public:
  inline unsigned int	getPrice() const;
  inline const char*	getName() const;
};

# include "SkillChecker.hpp"

#endif // !SKILL_CHECKER_HH_
