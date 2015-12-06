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
    Node *nodes;
    int   nodeCount;
    int   elementID;

    float localLength;
    float localCrossSection;
    float localThermalConductivity;

    float factorC;

    std::vector <std::vector<float> > localHMatrix;
    std::vector <std::vector<float> > localPVector;

    FiniteElement() {

    }

    FiniteElement(int elementID, int nodeCount, Node *nodes,
                  float localLength, float localCrossSection, float localThermalConductivity) {
        std::cout << "Created Element(" << elementID << "). " << std::endl;
        this->elementID = elementID;
        this->nodeCount = nodeCount;
        this->nodes = nodes;
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

        for (int n=elementID ; n < elementID+2; ++n) {
            localPVector[0][0] += nodes[n].boundaryCondition1 * this->localCrossSection;
            localPVector[1][0] += nodes[n].boundaryCondition2 * this->localCrossSection;

            if (nodes[n].nodeID == (GlobalData::numberOfNodes -1) ){
                localPVector[0][0] *= -1;
                localPVector[1][0] *= -1;
            }
        }




    }

    void calculateAll() {
        calculateCFactor();
        calculateHMatrix();
        calculatePVector();
    }


    void print() {
        std::cout << "\nFiniteElement[" << elementID << "]::print():" << std::endl;
        for (int n=0 ; n < GlobalData::numberOfNodes; ++n) {
            nodes[n].print();
        }
    }

    void printLocalMatrixes() {
        std::cout << "\nFiniteElement[" << elementID << "]::printLocalMatrixes():" << std::endl;
        std::cout << "Local H Matrix:" << std::endl;

        for (int i=0; i < localHMatrix.size(); ++i) {
            std::cout << "[ ";
            for (int j=0; j < localHMatrix[i].size(); ++j) {
                std::cout << localHMatrix[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        }

        std::cout << "Local P Vector:" << std::endl;
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
