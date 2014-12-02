//
// Log.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:51:32 2014 
// Last Update Thu Nov 20 11:16:55 2014 
//

void
Log::setActive(bool active)
{
  m_active = active;
}


const char*
Log::getName() const
{
  return (m_name);
}

Log::EColor
Log::getColor() const
{
  return (m_color);
}

bool
Log::isBold() const
{
  return (m_bold);
}

bool
Log::isActive() const
{
  return (m_active);
}
