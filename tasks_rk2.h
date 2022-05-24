//
// Created by belki on 06.05.2022.
//

#ifndef RK2_TASKS_RK2_H
#define RK2_TASKS_RK2_H

#include <list>
#include <cstring>

using namespace std;

struct Node {
    Node();
    Node(int nameNode);
    ~Node();

    Node* parent;
    list<Node*> listChilds;
    int name;
    //static int countNodes;
    int countNodes;
};

class Graph {
private :
    Node* head;
    Node* makeNode(Node* parent);
    int lastNodeName;

    list<int> buildNodePath(Node* node);
    Node* findNode(Node* node, int nodeName);
    void printNode(ofstream &fout, Node* node);
    //здесь можно писать любые функции, которые могут понадобиться
public :
    Graph();
    Graph(int countNodes);
    ~Graph();
    /*
        output		:	-1 - если функция не реализована
                    :	положительное число -- число узлов
        author		:
        date		:
    */
    int buildTreeBFS(int countNodes);
    /*
        output		:	-1 - если функция не реализована
                    :	положительное число -- число узлов
        author		:
        date		:
    */
    int buildTreeDFS(int countNodes);

    void BFS();
    void DFS();
    /*
        description	:	функция поиска узла по его имени
        input 		:	nameNode -- имя узла
        output		:	{bool -- узел найде, list<int> -- список имён узлов до необходимого}
        description	:	приставка DFS -- поиск в глубину, BSF -- поиск в ширину
        author		:
        date		:
    */
    std::pair<bool, list<int>> searchDFS(int nameNode);
    std::pair<bool, list<int>> searchBFS(int nameNode);
};

template<class T>
class Filo {
private :
    T* ar;	//массив
    int size;	//размер массива
    int countData;	//число элементов в массиве
public :
    Filo(): Filo(100){};
    Filo(int _size)
    {
        this->ar = new T[_size];
        this->size = _size;
        countData = 0;
    };

    ~Filo()
    {
        if (this->ar != nullptr)
        {
            delete this->ar;
        }
    };
    /*
        input		:	элемент который надо добавить
        output		:	1 - элемент добавлен, 0 - элемент не добавлен
        description	:	добавление элемента в конец массива
    */
    int push_back(T el)
    {
        if (countData == size)
        {
            return 0;
        }
        ar[countData] = el;
        countData++;
        return 1;
    };
    /*
        input		:	элемент который надо извлечь
        output		:	пара значений:
                            1ый аргумент пары -- 1 - элемент успешно извлечён, 0 - элементов в массиве нет
                            2ой аргумент пары -- это извлечённый элемент
        description	:	извлечение элемента из массива
    */
    pair<int,T> pop_back()
    {
        if (countData == 0)
        {
            return make_pair(0, 0);
        }

        countData--;
        return make_pair(1, ar[countData]);
    };
};

template<class T>
class CheckBrackets : public Filo<char> {
private:
    char findPair(char c)
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
    };
    bool isOpenBracket(char c)
    {
        return (c == '{' || c == '(' || c == '[');
    };
public :
    CheckBrackets() : Filo<char>(){};
    ~CheckBrackets() {};

    /*
        input		:	строка со скобками
        output		:	0 - всё хорошо, -1 - скобок не хватает
        description	:	проверка скобок,
    */
    int checkBrackets(const char* strBrackets)
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
    };
};

ostream& operator<< (ostream& ostr, const pair<int, int> val);

pair<int/*index el*/, int /*count call*/> binSearchRecurs(int* ar, int left, int right, int el, int recurs_depth);
pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);

#endif //RK2_TASKS_RK2_H
