//
// Class.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:43:05 2014 
// Last Update Tue Nov  4 15:12:51 2014 
//

#include "data/Class.hh"

Class::Class(const char* name,
	     unsigned int s, unsigned int p, unsigned int d, unsigned int t, unsigned int i,
	     unsigned int speedLevel, unsigned int orientationLevel) :
  Namable(name)
{
  m_characteristics[strength]	= s;
  m_characteristics[perception]	= p;
  m_characteristics[dexterity]	= d;
  m_characteristics[toughness]	= t;
  m_characteristics[intuition]	= i;

  m_skills[speed]		= speedLevel;
  m_skills[orientation]		= orientationLevel;
}

Class::~Class()
{
}
