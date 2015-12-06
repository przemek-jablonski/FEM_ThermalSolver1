//
// Created by Przemysław Jabłoński on 05/12/15.
//

#ifndef MESTHERMALSOLVER1_FEMGRID_H
#define MESTHERMALSOLVER1_FEMGRID_H


#include "FiniteElement.h"

class FEMGrid {
public:
    FiniteElement *elements;
    int elementsCount;
    std::vector <std::vector<float> > globalHMatrix;
    std::vector <std::vector<float> > globalPVector;

public:
    FEMGrid(FiniteElement *elements, int elementsCount);

    void addElementToGrid(FiniteElement element){
        elements[elementsCount] = element;
        ++elementsCount;
    }

    void printAll() {
        for (int i= 0; i < elementsCount; ++i){
            std::cout<< "Printing FEMGrid() " << i <<":" <<std::endl;
            elements[i].print();
        }
    }

    void printGlobalHMatrix() {
        std::cout << "\nGLOBAL H MATRIX:" << std::endl;
        for (int i = 0; i < globalHMatrix.size(); ++i){
            std::cout << "[ ";
            for (int j = 0 ; j < globalHMatrix[i].size(); ++j) {
                std::cout << globalHMatrix[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        }
    }

    void printGlobalPVector() {
        std::cout << "\nGLOBAL P VECTOR:" << std::endl;
        for (int i = 0; i < globalPVector.size(); ++i){
            std::cout << "[ ";
            for (int j = 0 ; j < globalPVector[i].size(); ++j) {
                std::cout << globalPVector[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        }
    }

    void calculateGlobalHMatrix() {
        for (int e = 0 ; e < elementsCount; ++e) {
            for (int i = 0 ; i < elements[e].localHMatrix.size(); ++i) {
                for (int j = 0 ; j < elements[e].localHMatrix[i].size(); ++j) {
                    globalHMatrix[i+e][j+e] += elements[e].localHMatrix[i][j];
                }
            }
        }
    }

    void calculateGlobalPVector(){
        //initializeGlobalPVector();  <- in constructor, FIX!
        for (int e = 0 ; e < elementsCount; ++e) {
            for (int j = 0 ; j < elements[e].localPVector.size(); ++j) {
                globalPVector[j+e][0] += elements[e].localPVector[j][0];
            }
        }

    }

private:
    void initializeGlobalPVector() {
        //is in constructor - FIX DAT SHIT
    }


};


#endif //MESTHERMALSOLVER1_FEMGRID_H
