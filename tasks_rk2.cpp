//
// Created by belki on 06.05.2022.
//

#include <vector>
#include <fstream>
#include <cstring>
#include "tasks_rk2.h"

Node::Node()
{
    this->name = 0;
    this->countNodes = 0;
    this->parent = nullptr;
}
Node::Node(int nameNode): Node()
{
    name = nameNode;
}
Node::~Node()
{

}

Graph::Graph()
{
    lastNodeName = 0;
}
Graph::Graph(int countNodes)
{

}


Node* Graph::makeNode(Node *parent)
{
    auto node = new Node(lastNodeName++);
    node->parent = parent;
    return node;
}
int Graph::buildTreeBFS(int countNodes)
{
    this->head = makeNode(nullptr);
    std::vector<Node*> nodes;
    nodes.push_back(head);
    while (true)
    {
        std::vector<Node*> createdNodes;
        for (auto node : nodes)
        {
            for (int i = 0; i < countNodes; i++)
            {
                auto nNode = makeNode(node);
                node->listChilds.push_back(nNode);
                createdNodes.push_back(nNode);
            }
        }
        countNodes--;
        nodes = createdNodes;
        if (countNodes == 0)
        {
            return lastNodeName;
        }
    }
}

Node *Graph::findNode(Node* node, int nodeName)
{
    if (node->listChilds.size() > 0)
    {
        for (auto n: node->listChilds) {
            if (n->name == nodeName) {
                return n;
            }
            auto cn = findNode(n, nodeName);
            if (cn != nullptr) {
                return cn;
            }
        }
    }
    return nullptr;
}
std::pair<bool, list<int>> Graph::searchDFS(int nameNode)
{
    list<int> result;
    if ((nameNode > lastNodeName-1) || (nameNode < 0))
    {
        return make_pair(false, result);
    }
    if (head->name == nameNode)
    {
        return make_pair(true, buildNodePath(head));
    }
    auto node = findNode(head, nameNode);
    if (node != nullptr)
    {
        return make_pair(true, buildNodePath(node));
    }
    return make_pair(false, result);
}
std::pair<bool, list<int>> Graph::searchBFS(int nameNode)
{
    list<int> result;
    if ((nameNode > lastNodeName-1) || (nameNode < 0))
    {
        return make_pair(false, result);
    }
    std::vector<Node*> nodes;
    nodes.push_back(head);
    while (true)
    {
        std::vector<Node*> nodesToProcess;
        for (auto node : nodes)
        {
            if(node->name == nameNode)
            {
                return make_pair(true, buildNodePath(node));
            }
            for (auto cn : node->listChilds)
            {
                if(cn->name == nameNode)
                {
                    return make_pair(true, buildNodePath(cn));
                }
                if (cn->listChilds.size() > 0)
                {
                    for (auto cnc : cn->listChilds)
                    {
                        nodesToProcess.push_back(cnc);
                    }
                }
            }
        }
        nodes = nodesToProcess;
        if (nodes.size() == 0)
        {
            return make_pair(false, result);
        }
    }
}

list<int> Graph::buildNodePath(Node *node)
{
    list<int> path;
    auto curNode = node;
    while (curNode != nullptr)
    {
        path.push_back(curNode->name);
        curNode = curNode->parent;
    }
    path.reverse();
    return path;
}

void Graph::BFS() {
    ofstream fout;
    fout.open("bfs_res.txt", fstream::out);

    std::vector<Node *> nodes;
    nodes.push_back(head);
    while (true) {
        std::vector<Node *> nodesToProcess;
        for (auto node: nodes) {
            if (node->listChilds.size() > 0) {
                fout << node->name;
                fout << "{";
                int i = 1;
                for (auto cn: node->listChilds)
                {
                    fout << cn->name;
                    if (i < node->listChilds.size())
                    {
                        fout << ",";
                    }
                    nodesToProcess.push_back(cn);
                    i++;
                }
                fout << "}\n";
            }
        }
        nodes = nodesToProcess;
        if (nodesToProcess.size() == 0)
        {
            fout.close();
            return;
        }
    }
}

void Graph::printNode(ofstream &fout, Node *node)
{
    fout << node->name;
    if (node->listChilds.size() > 0)
    {
        fout << "{";
        int i = 1;
        for (auto cn : node->listChilds)
        {
            printNode(fout, cn);
            if (i < node->listChilds.size())
            {
                fout << ",";
            }
            i++;
        }

        fout << "}";
    }
}
void Graph::DFS()
{
    ofstream fout;
    fout.open("dfs_res.txt", fstream::out);

    printNode(fout, head);

    fout.close();
}

////////////////////


ostream& operator<< (ostream& ostr, const pair<int, int> val) { // task 4
    return (ostr << "(" << val.first << ", " << val.second << ")\n");
}