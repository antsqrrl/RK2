#include <iostream>

#include "filo.h"
#include "filo.cpp"
#include "check_brackets.h"



using namespace std;

Filo<int> filo(3);
CheckBrackets<char> cb;

ostream& operator<< (ostream& ostr, const pair<int, int> val) {
    return (ostr << "(" << val.first << ", " << val.second << ")\n");
}

void task3()
{


    cout << "push_back 1 -> " << filo.push_back(1) << endl;
    cout << "push_back 2 -> " << filo.push_back(2) << endl;
    cout << "push_back 3 -> " << filo.push_back(3) << endl;
    cout << "push_back 4 -> " << filo.push_back(4) << endl;
    auto a = filo.pop_back();
    cout << "pop_back -> " << a;
    a = filo.pop_back();
    cout << "pop_back -> " << a;
    a = filo.pop_back();
    cout << "pop_back -> " << a;
    a = filo.pop_back();
    cout << "pop_back -> " << a;
}
void task5()
{

    cout << cb.checkBrackets("{{()[()]}}");

}

int main() {
    //task3();
    task5();
    return 0;
}
