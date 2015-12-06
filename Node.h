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

    Node(int nodeID, float thermalStreamQ = 0, float alpha = 0, float tInfinity = 0) {
        std::cout << "Created Node(" << nodeID <<")->\tbc1: " << boundaryCondition1 << ", bc2: " << boundaryCondition2 << std::endl;
        this->nodeID = nodeID;
        temperature= -666;
        this->boundaryCondition1 = thermalStreamQ;
        this->boundaryCondition2 = tInfinity * alpha;
    }

    void print(){
        std::cout << "Node ID " << nodeID << ", bc1: " << boundaryCondition1 << ", bc2: " << boundaryCondition2
        << ", temp: " << temperature << std::endl;
    }
};


#endif //MESTHERMALSOLVER1_NODE_H
