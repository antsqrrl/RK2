#include <iostream>


#include "tasks_rk2.h"


using namespace std;

Filo<int> filo(3);
CheckBrackets<char> cb;



pair<int/*index el*/, int /*count call*/> binSearchRecurs(int* ar, int left, int right, int el, int recurs_depth)
{
    if (right - left <= 1)
    {
        if (ar[left] == el)
        {
            return  make_pair(left, recurs_depth+1);
        }
        if (ar[right] == el)
        {
            return  make_pair(right, recurs_depth+1);
        }
    }
    int middle = (left+right)/2;
    if (ar[middle] == el)
    {
        return make_pair(middle, recurs_depth);
    }
    if (ar[middle] > el)
    {
        auto r = binSearchRecurs(ar, left, middle, el, recurs_depth+1);
        if (r.first != -1)
        {
            return r;
        }
    }
    if (ar[middle] < el)
    {
        auto r = binSearchRecurs(ar, middle, right, el, recurs_depth+1);
        if (r.first != -1)
        {
            return r;
        }
    }
    return make_pair(-1, recurs_depth);
}
pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el)
{
    return binSearchRecurs(ar, 0, sizeAr-1, el, 1);
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

int array[7] = {1, 4, 6, 7, 11, 36, 41};

int main() {
    task3();
    task5();
    cout << endl;
    pair<int, int> test = binSearch(array, 7, 41);
    cout << test;

    auto graph = new Graph();
    int r = graph->buildTreeBFS(3);
    auto r1 = graph->searchBFS(15);
    auto r2 = graph->searchBFS(16);

    auto r3 = graph->searchDFS(15);
    auto r4 = graph->searchDFS(16);

    graph->BFS();
    graph->DFS();

    return 0;
}
