//
// Class.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 13:25:30 2014 
// Last Update Wed Nov 12 16:50:07 2014 
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


unsigned int
Class::getInventorySize() const
{
  return ((m_characteristics[strength] + m_characteristics[toughness]) / 10);
}
