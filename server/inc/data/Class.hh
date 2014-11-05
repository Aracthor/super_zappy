//
// Class.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:39:45 2014 
// Last Update Tue Nov  4 14:03:07 2014 
//

#ifndef CLASS_HH_
# define CLASS_HH_

# include "Namable.hh"

# define CHARACTERISTICS_NUMBER	(5)
# define SKILLS_NUMBER		(2)

class		Class : public Namable
{
public:
  enum		ECharacteristic
  {
    strength,
    perception,
    dexterity,
    toughness,
    intuition,
    characteristics_number
  };

  enum		ESkill
  {
    speed,
    orientation,
    skills_number
  };

private:
  unsigned int	m_characteristics[characteristics_number];
  unsigned int	m_skills[skills_number];

public:
  Class(const char* name,
	unsigned int s, unsigned int p, unsigned int d, unsigned int t, unsigned int i,
	unsigned int speedLevel, unsigned int orientationLevel);
  ~Class();

public:
  inline unsigned int	getCharacteristicLevel(ECharacteristic characteristic) const;
  inline unsigned int	getSkillLevel(ESkill skill) const;
};

# include "Class.hpp"

#endif // !CLASS_HH_
