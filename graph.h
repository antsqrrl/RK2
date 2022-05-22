//
// Created by belki on 06.05.2022.
//

#ifndef RK2_GRAPH_H
#define RK2_GRAPH_H

#include <list>

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

#endif //RK2_GRAPH_H
