//
// Created by belki on 05.05.2022.
//

#ifndef RK2_CHECK_BRACKETS_H
#define RK2_CHECK_BRACKETS_H

#include "string.h"

#include "filo.h"

template<class T>
class CheckBrackets : public Filo<char> {
private:
    char findPair(char c);
    bool isOpenBracket(char c);
public :
    CheckBrackets() : Filo<char>(){};
    ~CheckBrackets() {};

    /*
        input		:	строка со скобками
        output		:	0 - всё хорошо, -1 - скобок не хватает
        description	:	проверка скобок,
    */
    int checkBrackets(const char* strBrackets);
};

#endif //RK2_CHECK_BRACKETS_H
