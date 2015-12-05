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
    Node *node1;
    Node *node2;

    float localLength;
    float localCrossSection;
    float localThermalConductivity;

    float factorC;

    std::vector <std::vector<float> > localHMatrix;
    std::vector <std::vector<float> > localPVector;

    FiniteElement() {

    }

    FiniteElement(Node *node1, Node *node2,
                  float localLength, float localCrossSection, float localThermalConductivity) {
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
        for(int i = 0; i < localHMatrix.size(); ++i){
            for (int j = 0; j < localHMatrix[i].size(); ++j) {
                localHMatrix[i][j] = factorC;
                if(i!=j) localHMatrix[i][j] *= -1;
            }
        }
    }

    void calculatePVector() {

    }

    void calculateAll() {
        calculateCFactor();
        calculateHMatrix();
        calculatePVector();
    }


    void print() {
        std::cout << "\nprinting from FiniteElement:" << std::endl;
        node1->print();
        node2->print();
    }

};


#endif //MESTHERMALSOLVER1_FINITEELEMENT_H
