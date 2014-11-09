//
// SpeedCalculator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 05:09:45 2014 
// Last Update Sun Nov  9 05:14:16 2014 
//

#include "executors/SpeedCalculator.hh"

SpeedCalculator::SpeedCalculator()
{
  m_speedCoefs[Hoopla::snow]		= 15;
  m_speedCoefs[Hoopla::bare]		= 10;
  m_speedCoefs[Hoopla::tundra]		= 11;
  m_speedCoefs[Hoopla::taiga]		= 14;
  m_speedCoefs[Hoopla::shrubland]	= 12;
  m_speedCoefs[Hoopla::sludge]		= 20;
  m_speedCoefs[Hoopla::temperate_jungle]= 15;
  m_speedCoefs[Hoopla::temperate_forest]= 13;
  m_speedCoefs[Hoopla::tallgrass]	= 11;
  m_speedCoefs[Hoopla::grassland]	= 10;
  m_speedCoefs[Hoopla::plain]		= 10;
  m_speedCoefs[Hoopla::desert]		= 10;
  m_speedCoefs[Hoopla::tropical_jungle]	= 18;
  m_speedCoefs[Hoopla::tropical_forest]	= 15;
  m_speedCoefs[Hoopla::marsh]		= 20;
  m_speedCoefs[Hoopla::beach]		= 10;
  m_speedCoefs[Hoopla::river]		= 30;
  m_speedCoefs[Hoopla::lake]		= 25;
  m_speedCoefs[Hoopla::ice]		= 20;
  m_speedCoefs[Hoopla::ocean]		= 50;
}

SpeedCalculator::~SpeedCalculator()
{
}
