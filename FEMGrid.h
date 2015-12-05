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


};


#endif //MESTHERMALSOLVER1_FEMGRID_H
