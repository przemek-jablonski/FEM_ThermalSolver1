//
// Created by Przemysław Jabłoński on 05/12/15.
//

#include "FEMGrid.h"

FEMGrid::FEMGrid(FiniteElement *elements, int elementsCount) {

    this->elements = elements;
    this->elementsCount = elementsCount;
    //instantiating Global H Matrix (2d)
    globalHMatrix.resize(GlobalData::numberOfNodes);
    for (int i = 0 ; i < globalHMatrix.size(); ++i)
        globalHMatrix[i].resize(GlobalData::numberOfNodes);

    //instantiating Global P Vector (2d, 1 column)
    globalPVector.resize(GlobalData::numberOfNodes);
    for (int i = 0 ; i < globalPVector.size(); ++i)
        globalPVector[i].resize(1);

    //pre-fill matrix with 0s
    for (int i = 0; i < globalHMatrix.size(); ++i)
        for (int j = 0 ; j < globalHMatrix[i].size(); ++j)
            globalHMatrix[i][j] = 0;

    //pre-fill vector with 0s
    for (int i = 0; i < globalPVector.size(); ++i)
        for (int j = 0 ; j < globalPVector[i].size(); ++j)
            globalPVector[i][j] = 0;

}