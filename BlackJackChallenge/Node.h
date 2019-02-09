//
// Created by Dennis O'Connell on 2019-02-08.
//

#ifndef HELLOMAIN_NODE_H
#define HELLOMAIN_NODE_H
class Node {
public:
    Node(int value);
    void AddNode(int value);
    void PrintInOrder(Node* node);

private:
    Node* left;
    Node* right;
    int value;
};
#endif //HELLOMAIN_NODE_H
