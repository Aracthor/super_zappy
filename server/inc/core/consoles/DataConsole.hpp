//
// DataConsole.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 09:14:18 2014 
// Last Update Thu Nov 20 12:27:33 2014 
//

template <typename T>
DataConsole<T>::DataConsole(const char* name) :
  Console(name)
{
}

template <typename T>
DataConsole<T>::~DataConsole()
{
}


template <typename T>
void
DataConsole<T>::drawElem(const T& elem, unsigned int index) const
{
  if (index + 1 < this->getHeight() - 1)
    {
      this->move(1, index + 1);
      this->drawElemData(elem);
    }
}


template <typename T>
void
DataConsole<T>::update()
{
}
