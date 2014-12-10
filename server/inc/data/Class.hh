//
// Class.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:39:45 2014 
// Last Update Wed Dec 10 12:57:00 2014 
//

#ifndef CLASS_HH_
# define CLASS_HH_

# include "Namable.hh"

# define SKILL_LEVEL_MAX	(4)

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

  enum		ESkillLevel
  {
    apprentice,
    adept,
    expert,
    master,
    skill_level_max
  };

  enum		ESkill
  {
    speed,
    orientation,
    crafting,
    building,
    shoot,
    skills_number
  };

private:
  unsigned int	m_characteristics[characteristics_number];
  unsigned int	m_skills[skills_number];

public:
  Class(const char* name,
	unsigned int s, unsigned int p, unsigned int d, unsigned int t, unsigned int i,
	unsigned int speedLevel, unsigned int orientationLevel,
	unsigned int craftingLevel, unsigned int buildingLevel, unsigned int shootLevel);
  ~Class();

public:
  inline unsigned int	getCharacteristicLevel(ECharacteristic characteristic) const;
  inline unsigned int	getSkillLevel(ESkill skill) const;

  inline unsigned int	getMaxLife() const;
  inline unsigned int	getInventorySize() const;
};

# include "Class.hpp"

#endif // !CLASS_HH_
