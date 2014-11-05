//
// Terraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 08:21:23 2014 
// Last Update Mon Nov  3 15:46:46 2014 
//

#include "abstractions/allocs.hh"
#include "debug/LogManager.hh"
#include "map/generators/Terraformer.hh"

Terraformer::Terraformer(const Configs::Map& configs) :
  ATerraformer(configs)
{
}

Terraformer::~Terraformer()
{
}


void
Terraformer::createMap()
{
  float*	moistures;

  MALLOC(moistures, m_hooplasNumber, float);

  LogManagerSingleton::access()->intern.print("Map generation started.");
  {
    LogManagerSingleton::access()->intern.print("Height calc...");
    this->calcHeights(m_hooplas, m_configs.width, m_configs.height);
    this->setDefaultGrounds(m_hooplas, m_hooplasNumber);
    LogManagerSingleton::access()->intern.print("River insertions...");
    this->insertWater(m_hooplas);
    LogManagerSingleton::access()->intern.print("Low lake emplition...");
    this->emplLowLakes();
    LogManagerSingleton::access()->intern.print("Moistures calc...");
    this->calcMoistures(m_hooplas, moistures);
    LogManagerSingleton::access()->intern.print("Grounds definition...");
    this->setGrounds(m_hooplas, moistures, m_hooplasNumber);
    LogManagerSingleton::access()->intern.print("Objects creation...");
    this->setObjects(m_hooplas, m_hooplasNumber);
  }
  LogManagerSingleton::access()->intern.print("Map generation ended.");

  free(moistures);
}
