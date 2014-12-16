//
// Array.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec 11 09:42:11 2014 
// Last Update Thu Dec 11 10:19:10 2014 
//

template <typename T>
Array<T>::Array() :
  std::vector<T*>()
{
}

template <typename T>
Array<T>::Array(unsigned int size) :
  std::vector<T*>(size)
{
}

template <typename T>
Array<T>::Array(const Array<T>& ref) :
  std::vector<T*>(ref.capacity())
{
  unsigned int	i;

  for (i = 0; i < ref.size(); ++i)
    *this << ref[i];
}

template <typename T>
Array<T>::~Array()
{
  unsigned int	i;

  for (i = 0; i < this->size(); ++i)
    delete (this->at(i));
}


template <typename T>
void
Array<T>::resize(unsigned int number)
{
  this->reserve(number);
}


template <typename T>
bool
Array<T>::isFull() const
{
  return (this->size() == this->capacity());
}


template <typename T>
Array<T>&
Array<T>::operator<<(const T& elem)
{
  this->push_back(new T(elem));
  return *this;
}


template <typename T>
const T&
Array<T>::operator[](unsigned int id) const
{
  return (*this->at(id));
}

template <typename T>
T&
Array<T>::operator[](unsigned int id)
{
  return (*this->at(id));
}
