//
// GroundGenerator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:29:09 2014 
// Last Update Sun Oct 26 01:31:39 2014 
//

#include "map/generators/GroundGenerator.hh"

GroundGenerator::GroundGenerator()
{
  this->readGroundsConfigs();
}

GroundGenerator::~GroundGenerator()
{
}


int
GroundGenerator::getHeightLevel(int height) const
{
  return (height / 10);
}

int
GroundGenerator::getMoistureLevel(int moisture) const
{
  moisture /= 10;
  if (moisture > MAX_MOISTURE)
    moisture = MAX_MOISTURE;
  else if (moisture < MIN_MOISTURE)
    moisture = MIN_MOISTURE;

  return (moisture);
}

Hoopla::EGround
GroundGenerator::getGround(int heightLevel, int moistureLevel) const
{
  Hoopla::EGround	ground;

  if (heightLevel < MIN_HEIGHT)
    ground = LOW_GROUND;
  else if (heightLevel > MAX_HEIGHT)
    ground = HIGH_GROUND;
  else
    ground = m_grounds[heightLevel][moistureLevel];

  return (ground);
}


void
GroundGenerator::setGrounds(Hoopla* hooplas, unsigned int number) const
{
  unsigned int	i;
  int		heightLevel;
  int		moistureLevel;

  for (i = 0; i < number; ++i)
    {
      heightLevel = this->getHeightLevel(hooplas[i].height);
      moistureLevel = this->getMoistureLevel(hooplas[i].moisture);
      hooplas[i].ground = this->getGround(heightLevel, moistureLevel);
    }
}


void
GroundGenerator::readGroundsConfigs()
{
  m_grounds[0][0] = Hoopla::beach;
  m_grounds[0][1] = Hoopla::beach;
  m_grounds[0][2] = Hoopla::beach;
  m_grounds[0][3] = Hoopla::beach;
  m_grounds[0][4] = Hoopla::beach;
  m_grounds[0][5] = Hoopla::beach;
  m_grounds[0][6] = Hoopla::beach;
  m_grounds[0][7] = Hoopla::beach;
  m_grounds[0][8] = Hoopla::beach;
  m_grounds[0][9] = Hoopla::beach;

  m_grounds[1][0] = Hoopla::desert;
  m_grounds[1][1] = Hoopla::plain;
  m_grounds[1][2] = Hoopla::plain;
  m_grounds[1][3] = Hoopla::grassland;
  m_grounds[1][4] = Hoopla::grassland;
  m_grounds[1][5] = Hoopla::grassland;
  m_grounds[1][6] = Hoopla::tallgrass;
  m_grounds[1][7] = Hoopla::tallgrass;
  m_grounds[1][8] = Hoopla::marsh;
  m_grounds[1][9] = Hoopla::marsh;

  m_grounds[2][0] = Hoopla::desert;
  m_grounds[2][1] = Hoopla::plain;
  m_grounds[2][2] = Hoopla::grassland;
  m_grounds[2][3] = Hoopla::grassland;
  m_grounds[2][4] = Hoopla::tallgrass;
  m_grounds[2][5] = Hoopla::tropical_forest;
  m_grounds[2][6] = Hoopla::tropical_forest;
  m_grounds[2][7] = Hoopla::tropical_jungle;
  m_grounds[2][8] = Hoopla::tropical_jungle;
  m_grounds[2][9] = Hoopla::marsh;

  m_grounds[3][0] = Hoopla::desert;
  m_grounds[3][1] = Hoopla::plain;
  m_grounds[3][2] = Hoopla::plain;
  m_grounds[3][3] = Hoopla::grassland;
  m_grounds[3][4] = Hoopla::grassland;
  m_grounds[3][5] = Hoopla::tallgrass;
  m_grounds[3][6] = Hoopla::tropical_forest;
  m_grounds[3][7] = Hoopla::tropical_forest;
  m_grounds[3][8] = Hoopla::tropical_jungle;
  m_grounds[3][9] = Hoopla::tropical_jungle;

  m_grounds[4][0] = Hoopla::desert;
  m_grounds[4][1] = Hoopla::plain;
  m_grounds[4][2] = Hoopla::grassland;
  m_grounds[4][3] = Hoopla::grassland;
  m_grounds[4][4] = Hoopla::tallgrass;
  m_grounds[4][5] = Hoopla::temperate_forest;
  m_grounds[4][6] = Hoopla::temperate_forest;
  m_grounds[4][7] = Hoopla::temperate_forest;
  m_grounds[4][8] = Hoopla::tropical_forest;
  m_grounds[4][9] = Hoopla::tropical_forest;

  m_grounds[5][0] = Hoopla::desert;
  m_grounds[5][1] = Hoopla::plain;
  m_grounds[5][2] = Hoopla::grassland;
  m_grounds[5][3] = Hoopla::grassland;
  m_grounds[5][4] = Hoopla::tallgrass;
  m_grounds[5][5] = Hoopla::tallgrass;
  m_grounds[5][6] = Hoopla::temperate_forest;
  m_grounds[5][7] = Hoopla::temperate_forest;
  m_grounds[5][8] = Hoopla::tropical_forest;
  m_grounds[5][9] = Hoopla::tropical_forest;

  m_grounds[6][0] = Hoopla::rocky_desert;
  m_grounds[6][1] = Hoopla::tundra;
  m_grounds[6][2] = Hoopla::tundra;
  m_grounds[6][3] = Hoopla::shrubland;
  m_grounds[6][4] = Hoopla::shrubland;
  m_grounds[6][5] = Hoopla::taiga;
  m_grounds[6][6] = Hoopla::taiga;
  m_grounds[6][7] = Hoopla::taiga;
  m_grounds[6][8] = Hoopla::taiga;
  m_grounds[6][9] = Hoopla::taiga;

  m_grounds[7][0] = Hoopla::rocky_desert;
  m_grounds[7][1] = Hoopla::rocky_desert;
  m_grounds[7][2] = Hoopla::tundra;
  m_grounds[7][3] = Hoopla::tundra;
  m_grounds[7][4] = Hoopla::shrubland;
  m_grounds[7][5] = Hoopla::shrubland;
  m_grounds[7][6] = Hoopla::taiga;
  m_grounds[7][7] = Hoopla::taiga;
  m_grounds[7][8] = Hoopla::taiga;
  m_grounds[7][9] = Hoopla::taiga;

  m_grounds[8][0] = Hoopla::bare;
  m_grounds[8][1] = Hoopla::bare;
  m_grounds[8][2] = Hoopla::tundra;
  m_grounds[8][3] = Hoopla::tundra;
  m_grounds[8][4] = Hoopla::tundra;
  m_grounds[8][5] = Hoopla::snow;
  m_grounds[8][6] = Hoopla::snow;
  m_grounds[8][7] = Hoopla::snow;
  m_grounds[8][8] = Hoopla::snow;
  m_grounds[8][9] = Hoopla::snow;

  m_grounds[9][0] = Hoopla::bare;
  m_grounds[9][1] = Hoopla::bare;
  m_grounds[9][2] = Hoopla::snow;
  m_grounds[9][3] = Hoopla::snow;
  m_grounds[9][4] = Hoopla::snow;
  m_grounds[9][5] = Hoopla::snow;
  m_grounds[9][6] = Hoopla::snow;
  m_grounds[9][7] = Hoopla::snow;
  m_grounds[9][8] = Hoopla::snow;
  m_grounds[9][9] = Hoopla::snow;
}
