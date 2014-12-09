//
// NamesRegister.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Dec  5 14:52:24 2014 
// Last Update Fri Dec  5 15:37:28 2014 
//

int
NamesRegister::getFromName(const std::string& name) const
{
  return (this->getFromName(name.c_str()));
}


const char*
NamesRegister::operator[](Hoopla::EGround ground) const
{
  return (m_grounds[static_cast<unsigned int>(ground)]);
}

const char*
NamesRegister::operator[](Hoopla::EItem item) const
{
  return (m_items[static_cast<unsigned int>(item)]);
}

const char*
NamesRegister::operator[](Hoopla::EObject object) const
{
  return (m_objects[static_cast<unsigned int>(object)]);
}
