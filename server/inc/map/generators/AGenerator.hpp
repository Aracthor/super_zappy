//
// AGenerator.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 17:41:40 2014 
// Last Update Tue Oct 28 19:47:27 2014 
//

Hoopla&
AGenerator::getHoopla(const Position& position)
{
  return (m_hooplas[position.y * m_width + position.x]);
}

const Hoopla&
AGenerator::getHoopla(const Position& position) const
{
  return (m_hooplas[position.y * m_width + position.x]);
}

bool
AGenerator::isPeak(const Hoopla& hoopla) const
{
  return (hoopla.height > PEAK_HEIGHT && hoopla.ground == Hoopla::ocean);
}
