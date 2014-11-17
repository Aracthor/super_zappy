//
// GroundCatalog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:08:13 2014 
// Last Update Fri Nov 14 17:24:00 2014 
//

#include "catalogs/GroundCatalog.hh"

GroundCatalog::GroundCatalog()
{
  this->insert(Ground(10, Hoopla::snowBall),		Hoopla::snow);
  this->insert(Ground(60, Hoopla::pebble),		Hoopla::bare);
  this->insert(Ground(80, Hoopla::pebble),		Hoopla::tundra);
  this->insert(Ground(25, Hoopla::frost_plant),		Hoopla::taiga);
  this->insert(Ground(30, Hoopla::frost_plant),		Hoopla::shrubland);
  this->insert(Ground( 5, Hoopla::mud),			Hoopla::sludge);
  this->insert(Ground(15, Hoopla::temperate_plant),	Hoopla::temperate_jungle);
  this->insert(Ground(20, Hoopla::temperate_plant),	Hoopla::temperate_forest);
  this->insert(Ground(10, Hoopla::grass),		Hoopla::tallgrass);
  this->insert(Ground(15, Hoopla::grass),		Hoopla::grassland);
  this->insert(Ground(25, Hoopla::grass),		Hoopla::plain);
  this->insert(Ground( 5, Hoopla::sand),		Hoopla::desert);
  this->insert(Ground(15, Hoopla::tropical_plant),	Hoopla::tropical_jungle);
  this->insert(Ground(20, Hoopla::tropical_plant),	Hoopla::tropical_forest);
  this->insert(Ground(15, Hoopla::mud),			Hoopla::marsh);
  this->insert(Ground( 5, Hoopla::sand),		Hoopla::beach);
  this->insert(Ground( 5, Hoopla::fresh_water),		Hoopla::river);
  this->insert(Ground( 5, Hoopla::fresh_water),		Hoopla::lake);
  this->insert(Ground(50, Hoopla::ice_block),		Hoopla::ice);
  this->insert(Ground( 5, Hoopla::water),		Hoopla::ocean);
}

GroundCatalog::~GroundCatalog()
{
}
