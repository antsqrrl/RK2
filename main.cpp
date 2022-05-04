#include <iostream>

#include "filo.h"
#include "filo.cpp"


using namespace std;
Filo<int> filo(3);

int main() {


    cout << "push_back 1 -> " << filo.push_back(1) << endl;
    cout << "push_back 2 -> " << filo.push_back(2) << endl;
    cout << "push_back 3 -> " << filo.push_back(3) << endl;
    cout << "push_back 4 -> " << filo.push_back(4) << endl;
    auto a = filo.pop_back();
    cout << "pop_back -> " << a.first << " " << a.second << endl;
    a = filo.pop_back();
    cout << "pop_back -> " << a.first << " " << a.second << endl;
    a = filo.pop_back();
    cout << "pop_back -> " << a.first << " " << a.second << endl;
    a = filo.pop_back();
    cout << "pop_back -> " << a.first << " " << a.second << endl;
    return 0;
}
