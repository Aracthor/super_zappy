//
// NamesRegister.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Dec  5 14:22:34 2014 
// Last Update Tue Dec  9 09:40:34 2014 
//

#include "map/NamesRegister.hh"

#include <cstring>

NamesRegister::NamesRegister()
{
  this->initGrounds();
  this->initItems();
  this->initObjects();
}

NamesRegister::~NamesRegister()
{
}


void
NamesRegister::initGrounds()
{
  m_grounds[Hoopla::snow]		= "snow";
  m_grounds[Hoopla::bare]		= "bare";
  m_grounds[Hoopla::tundra]		= "tundra";
  m_grounds[Hoopla::taiga]		= "taiga";
  m_grounds[Hoopla::shrubland]		= "shrubland";
  m_grounds[Hoopla::sludge]		= "sludge";
  m_grounds[Hoopla::temperate_jungle]	= "temperate_jungle";
  m_grounds[Hoopla::temperate_forest]	= "temperate_forest";
  m_grounds[Hoopla::tallgrass]		= "tallgrass";
  m_grounds[Hoopla::grassland]		= "grassland";
  m_grounds[Hoopla::plain]		= "plain";
  m_grounds[Hoopla::desert]		= "desert";
  m_grounds[Hoopla::tropical_jungle]	= "tropical_jungle";
  m_grounds[Hoopla::tropical_forest]	= "tropical_forest";
  m_grounds[Hoopla::marsh]		= "marsh";
  m_grounds[Hoopla::beach]		= "beach";
  m_grounds[Hoopla::river]		= "river";
  m_grounds[Hoopla::lake]		= "lake";
  m_grounds[Hoopla::ice]		= "ice";
  m_grounds[Hoopla::ocean]		= "ocean";
}

void
NamesRegister::initItems()
{
  m_items[Hoopla::none]			= "none";
  m_items[Hoopla::snow_ball]		= "snow_ball";
  m_items[Hoopla::pebble]		= "pebble";
  m_items[Hoopla::frost_plant]		= "frost_plant";
  m_items[Hoopla::mud]			= "mud";
  m_items[Hoopla::temperate_plant]	= "temperate_plant";
  m_items[Hoopla::grass]		= "grass";
  m_items[Hoopla::sand]			= "sand";
  m_items[Hoopla::tropical_plant]	= "tropical_plant";
  m_items[Hoopla::fresh_water]		= "fresh_water";
  m_items[Hoopla::ice_block]		= "ice_block";
  m_items[Hoopla::water]		= "water";
  m_items[Hoopla::stick]		= "stick";
  m_items[Hoopla::log]			= "log";
  m_items[Hoopla::wooden_javelin]	= "wooden_javelin";
}

void
NamesRegister::initObjects()
{
  m_objects[Hoopla::nothing]	= "nothing";
  m_objects[Hoopla::bush]	= "bush";
  m_objects[Hoopla::shrub]	= "shrub";
  m_objects[Hoopla::oak]	= "oak";
  m_objects[Hoopla::ash]	= "ash";
  m_objects[Hoopla::saplin]	= "saplin";
  m_objects[Hoopla::maple]	= "maple";
}


int
NamesRegister::search(const char* const* names, const char* name, int names_number) const
{
  int	number;

  number = 0;
  while (number < names_number && strcmp(names[number], name))
    ++number;

  if (number >= names_number)
    number = -1;
  return (number);
}


int
NamesRegister::getFromName(const char* name) const
{
  int	number;
  
  if ((number = this->search(m_grounds, name, static_cast<int>(Hoopla::grounds_number))) == -1 &&
      (number = this->search(m_items, name, static_cast<int>(Hoopla::items_number))) == -1 &&
      (number = this->search(m_objects, name, static_cast<int>(Hoopla::objects_number))) == -1)
    number = -1;
  return (number);
}
