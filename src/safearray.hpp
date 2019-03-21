////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Safearray class methods definition
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// This file contains templates of the method of the class Safearray.
/// This file is not going to be used w/o its main counterpart, safearray.h.
/// Since the file is used only through safearray.h, which has its own "include 
/// watcher", we add no addition "watcher" here.
///
////////////////////////////////////////////////////////////////////////////////

// #ifndef    // No need to have a watcher here!


// we have to indicate that methods of the class Safearray are also inside the namespace xi
namespace xi
{


template<typename T>
SafeArray<T>::SafeArray(size_t cap)
{

    _storage = new T[cap];
    _capacity = cap;
    // TODO: здесь необходимо добавить реализацию метода
}

template<typename T>
SafeArray<T>::~SafeArray()
{
    delete[] _storage;
}

template<typename T>
T &SafeArray<T>::operator[](size_t k)
{
    if (k < _capacity)
    {
        return _storage[k];
    } else
    {
        throw std::out_of_range("Out of range");
    }
}

template<typename T>
const T &SafeArray<T>::operator[](size_t k) const
{
    if (k < _capacity)
    {
        return _storage[k];
    } else
    {
        throw std::out_of_range("Out of range");
    }

}

template<typename T>
size_t SafeArray<T>::getCapacity() const
{
    return _capacity;

}

template<typename T>
void SafeArray<T>::checkBounds(size_t index) const
{
    if (index >= _capacity)
    {
        throw std::out_of_range("Out of range");
    }
}

template<typename T>
SafeArray<T>::SafeArray(const SafeArray &copy)
{
    _capacity = copy._capacity;
    _storage = new T[_capacity];

    std::copy_n(copy._storage, _capacity, _storage);

}

template<typename T>
SafeArray <T> &SafeArray<T>::operator=(const SafeArray &smt)
{
    if (this != &smt)
    {
        T *new_arr = new T[smt._capacity];
        std::copy(smt._storage, smt._storage + smt._capacity, new_arr);

        delete[] _storage;

        _storage = new_arr;
        _capacity = smt._capacity;
    }
    return *this;
}

// TODO: реализуйте остальные методы по образцу выше

} // namespace xi
