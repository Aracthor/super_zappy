//
// Class.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:43:05 2014 
// Last Update Thu Nov 13 16:29:56 2014 
//

#include "data/Class.hh"

Class::Class(const char* name,
	     unsigned int s, unsigned int p, unsigned int d, unsigned int t, unsigned int i,
	     unsigned int speedLevel, unsigned int orientationLevel,
	     unsigned int craftingLevel, unsigned int buildingLevel) :
  Namable(name)
{
  m_characteristics[strength]	= s;
  m_characteristics[perception]	= p;
  m_characteristics[dexterity]	= d;
  m_characteristics[toughness]	= t;
  m_characteristics[intuition]	= i;

  m_skills[speed]		= speedLevel;
  m_skills[orientation]		= orientationLevel;
  m_skills[crafting]		= craftingLevel;
  m_skills[building]		= buildingLevel;
}

Class::~Class()
{
}
