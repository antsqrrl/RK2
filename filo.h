//
// Created by belki on 04.05.2022.
//

#ifndef RK2_FILO_H
#define RK2_FILO_H

#include <utility>

using namespace std;

template<class T>
class Filo {
private :
    T* ar;	//массив
    int size;	//размер массива
    int countData;	//число элементов в массиве
public :
    Filo();
    Filo(int _size);

    ~Filo();
    /*
        input		:	элемент который надо добавить
        output		:	1 - элемент добавлен, 0 - элемент не добавлен
        description	:	добавление элемента в конец массива
    */
    int push_back(T el);
    /*
        input		:	элемент который надо извлечь
        output		:	пара значений:
                            1ый аргумент пары -- 1 - элемент успешно извлечён, 0 - элементов в массиве нет
                            2ой аргумент пары -- это извлечённый элемент
        description	:	извлечение элемента из массива
    */
    pair<int,T> pop_back();
};

#endif //RK2_FILO_H
