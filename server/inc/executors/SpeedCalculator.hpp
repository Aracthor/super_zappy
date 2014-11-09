//
// SpeedCalculator.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 05:10:51 2014 
// Last Update Sun Nov  9 05:18:55 2014 
//

unsigned int
SpeedCalculator::getSpeedCoef(unsigned char ground) const
{
  return (m_speedCoefs[ground]);
}
