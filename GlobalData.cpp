//
// Created by Przemysław Jabłoński on 05/12/15.
//

#include "GlobalData.h"

int      GlobalData::numberOfElements;
int      GlobalData::numberOfNodes;
float    GlobalData::totalLength;
float    GlobalData::crossSection;
float    GlobalData::thermalConductivity;
//int      GlobalData::HMatrixArrayInverter[2][2];
float    GlobalData::alpha;
float    GlobalData::tInfinity;
float    GlobalData::thermalStreamQ;


GlobalData::GlobalData() {
    //...
}


GlobalData::GlobalData(int noElements, int noNodes, float totalLength, float crossSection,
                       float thermalConductivity, float alpha, float tempInfinity, float thermalStreamQ)
{
    this->numberOfElements = noElements;
    this->numberOfNodes = noNodes;
    this->totalLength = totalLength;
    this->crossSection = crossSection;
    this->thermalConductivity = thermalConductivity;
    this->alpha = alpha;
    this->tInfinity = tempInfinity;
    this->thermalStreamQ = thermalStreamQ;
    //HMatrixArrayInverterInit();
}