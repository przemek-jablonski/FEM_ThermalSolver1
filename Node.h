//
// Created by Przemysław Jabłoński on 05/12/15.
//

#ifndef MESTHERMALSOLVER1_NODE_H
#define MESTHERMALSOLVER1_NODE_H


#include <iostream>

class Node {

public:
    int     nodeID;
    float   temperature;
    float   boundaryCondition1;
    float   boundaryCondition2;

    Node() {

    }

    Node(int nodeID, float boundaryCondition1, float boundaryCondition2) {
        this->nodeID = nodeID;
        temperature= -666;
        this->boundaryCondition1 = boundaryCondition1;
        this->boundaryCondition2 = boundaryCondition2;
    }

    void print(){
        std::cout << "Node ID " << nodeID << ", bc1: " << boundaryCondition1 << ", bc2: " << boundaryCondition2
        << ", temp: " << temperature << std::endl;
    }
};


#endif //MESTHERMALSOLVER1_NODE_H
