//
// Created by belki on 04.05.2022.
//

#include "filo.h"

using namespace std;

template<class T>
Filo<T>::Filo()
{
    Filo<T>(100);
}
template<class T>
Filo<T>::Filo(int _size)
{
    this->ar = new T[_size];
    this->size = _size;
}
template<class T>
Filo<T>::~Filo()
{
    delete this->ar;
}

template<class T>
int Filo<T>::push_back(T el)
{
    if (countData == size)
    {
        return 0;
    }
    ar[countData] = el;
    countData++;
    return 1;
}
template<class T>
pair<int,T> Filo<T>::pop_back()
{
    if (countData == 0)
    {
        return make_pair(0, 0);
    }

    countData--;
    return make_pair(1, ar[countData]);
}
