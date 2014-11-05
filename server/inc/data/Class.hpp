//
// Class.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 13:25:30 2014 
// Last Update Tue Nov  4 13:58:33 2014 
//

unsigned int
Class::getCharacteristicLevel(ECharacteristic characteristic) const
{
  return (m_characteristics[characteristic]);
}

unsigned int
Class::getSkillLevel(ESkill skill) const
{
  return (m_skills[skill]);
}
