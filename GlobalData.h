//
// Created by Przemysław Jabłoński on 05/12/15.
//

#ifndef MESTHERMALSOLVER1_GLOBALDATA_H
#define MESTHERMALSOLVER1_GLOBALDATA_H


#include <vector>

class GlobalData {
public:
    static int      numberOfElements;
    static int      numberOfNodes;
    static float    totalLength;
    static float    crossSection;
    static float    thermalConductivity;
    static int      localHMatrixInverter[2][2];
 // static int      HMatrixBoundaryCondition
    static float    alpha;
    static float    tInfinity;
    static float    thermalStreamQ;

    std::vector<float>  elementsLengths;
    std::vector<float>  elementsSections;
    std::vector<float>  elementsConductivity;


public:
    GlobalData();

    GlobalData(int noElements, int noNodes, float totalLength, float crossSection,
               float thermalConductivity, float alpha, float tempInfinity, float thermalStreamQ);

    void elementsLocalDataInit(std::vector<float> lengths,
                    std::vector<float> sections, std::vector<float> conductivity){

    }
    void localHMatrixInverterInit() {
        //fix?
        //   if i!=j then -1 if not then +1?

        localHMatrixInverter[0][0] = +1;
        localHMatrixInverter[0][1] = -1;
        localHMatrixInverter[1][0] = -1;
        localHMatrixInverter[1][1] = +1;
    }

};


#endif //MESTHERMALSOLVER1_GLOBALDATA_H
