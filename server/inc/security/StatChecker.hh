//
// StatChecker.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 13:27:47 2014 
// Last Update Tue Nov  4 14:48:52 2014 
//

#ifndef STAT_CHECKER_HH_
# define STAT_CHECKER_HH_

# include "SkillChecker.hh"
# include "data/Class.hh"

class		StatChecker
{
private:
  unsigned int	m_characteristicsMin[Class::characteristics_number];
  SkillChecker	m_skillsCheckers[Class::skills_number];

protected:
  StatChecker();
  virtual ~StatChecker();

private:
  const char*	checkSkills(const Class& classToCheck) const;

public:
  const char*	checkClass(const Class& classToCheck,
			   unsigned int geneticHardening, unsigned int skillCapacity) const;
};

#endif // !STAT_CHECKER_HH_
