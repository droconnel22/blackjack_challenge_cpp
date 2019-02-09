//
// Created by Dennis O'Connell on 2019-02-08.
//

#include <iostream>

#include "../Node.h"


Node::Node(int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

void Node::AddNode(int value) {
    if(this->value == value){
        return;
    }

    if(this->value < value){
        if(this->left == nullptr){
            this->left = new Node(value);
        }
        else
        {
            this->left->AddNode(value);
        }
    }
    else
    {
        if(this->right == nullptr) {
            this->right = new Node(value);
        }
        else
        {
            this->right->AddNode(value);
        }
    }

}

void Node::PrintInOrder(Node* node) {
    if(node == nullptr){
        return;
    }

    this->PrintInOrder(node->left);
    std::cout << node->value << std::endl;
    this->PrintInOrder(node->right);
}

