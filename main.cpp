#include <iostream>


#include "tasks_rk2.h"


using namespace std;

Filo<int> filo(3);
CheckBrackets<char> cb;

void task1()
{
    auto graph = new Graph();
    int r = graph->buildTreeBFS(3);
    auto r1 = graph->searchBFS(15);
    auto r2 = graph->searchBFS(16);

    auto r3 = graph->searchDFS(15);
    auto r4 = graph->searchDFS(16);

    graph->BFS();
    graph->DFS();
}

void task2()
{
    int array[7] = {1, 4, 6, 7, 11, 36, 41};
    pair<int, int> test = binSearch(array, 7, 41);
    cout << test;
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
    const char* brackets = "{(})[{]}";
    cout << "Your brackets: " << brackets << endl;
    cout << cb.checkBrackets(brackets);

}



int main() {
    task1();
    cout << endl;
    task2();
    cout << endl;
    task3();
    cout << endl;
    task5();

    return 0;
}
