//
// Created by Przemysław Jabłoński on 05/12/15.
//

#ifndef MESTHERMALSOLVER1_FINITEELEMENT_H
#define MESTHERMALSOLVER1_FINITEELEMENT_H

#include <vector>
#include "Node.h"
#include "GlobalData.h"

class FiniteElement {
public:

    //change this to dyn array of pointers to nodes
    // (according to nodeCount)
    Node *node1;
    Node *node2;
    int   nodeCount;

    float localLength;
    float localCrossSection;
    float localThermalConductivity;

    float factorC;

    std::vector <std::vector<float> > localHMatrix;
    std::vector <std::vector<float> > localPVector;

    FiniteElement() {

    }

    FiniteElement(int nodeCount, Node *node1, Node *node2,
                  float localLength, float localCrossSection, float localThermalConductivity) {
        this->nodeCount = nodeCount;
        this->node1 = node1;
        this->node2 = node2;
        this->localLength = localLength;
        this->localCrossSection = localCrossSection;
        this->localThermalConductivity = localThermalConductivity;
    }

    void calculateCFactor() {
        factorC = (localCrossSection * localThermalConductivity) / localLength;
    }

    void calculateHMatrix() {
        //initialization
        localHMatrix.resize(nodeCount);
        for (int i = 0; i < localHMatrix.size(); ++i)
            localHMatrix[i].resize(nodeCount);

        //value calculation
        for(int i = 0; i < localHMatrix.size(); ++i){
            for (int j = 0; j < localHMatrix[i].size(); ++j) {
                localHMatrix[i][j] = factorC;
                if(i!=j) localHMatrix[i][j] *= -1;
            }
        }
    }

    void calculatePVector() {

        //initialization
        localPVector.resize(2);
        for (int i= 0; i < localPVector.size(); ++i)
            localPVector[i].resize(1);

        localPVector[0][0] = 0;
        localPVector[1][0] = 0;

        //calculation
        //node1:
        localPVector[0][0] += node1->boundaryCondition1 * this->localCrossSection;
        localPVector[1][0] += node1->boundaryCondition2 * this->localCrossSection;

        //node2:
        localPVector[0][0] += node2->boundaryCondition1 * (-1) * this->localCrossSection;
        localPVector[1][0] += node2->boundaryCondition2 * (-1) * this->localCrossSection;


    }

    void calculateAll() {
        calculateCFactor();
        calculateHMatrix();
        calculatePVector();
    }


    void print() {
        std::cout << "\nFiniteElement::print():" << std::endl;
        node1->print();
        node2->print();
    }

    void printLocalMatrixes() {
        std::cout << "\nFiniteElement::printLocalMatrixes():" << std::endl;
        std::cout << "Local H Matrix:" << std::endl;

        for (int i=0; i < localHMatrix.size(); ++i) {
            std::cout << "[ ";
            for (int j=0; j < localHMatrix[i].size(); ++j) {
                std::cout << localHMatrix[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        }

        std::cout << "\nLocal P Vector:" << std::endl;
        for (int i = 0 ; i < localPVector.size(); ++i) {
            std::cout << "[ ";
             for (int j = 0 ; j < localPVector[i].size(); ++j) {
                 std::cout << localPVector[i][j] << " ";
             }
            std::cout << " ]" << std::endl;
        }
    }

};


#endif //MESTHERMALSOLVER1_FINITEELEMENT_H
