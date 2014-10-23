//
// GroundGenerator.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:36:17 2014 
// Last Update Wed Oct 22 14:36:18 2014 
//

Hoopla::EGround
GroundGenerator::getGroundFromEnvironnement(unsigned int height, unsigned int moisture) const
{
  return (m_grounds[height][moisture]);
}
