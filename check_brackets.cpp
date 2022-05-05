//
// Created by belki on 05.05.2022.
//

#include "check_brackets.h"
#include "filo.cpp"

using namespace std;

template<>
char CheckBrackets<char>::findPair(char c)
{
    if (c == '}')
    {
        return '{';
    }
    if (c == ')')
    {
        return '(';
    }
    if (c == ']')
    {
        return '[';
    }
    return 0;
}
template<>
bool CheckBrackets<char>::isOpenBracket(char c)
{
    return (c == '{' || c == '(' || c == '[');
}

template<>
int CheckBrackets<char>::checkBrackets(const char* strBrackets)
{
    auto length = strlen(strBrackets);
    if (length % 2 != 0)
    {
        return -1;
    }

    for (int i = 0; i < length; i++)
    {
        if (isOpenBracket(strBrackets[i]))
        {
            push_back(strBrackets[i]);
        }
        else
        {
            auto p = pop_back();
            if (p.first == 0 || p.second != findPair(strBrackets[i]))
            {
                return -1;
            }
        }
    }
    return 1;
}