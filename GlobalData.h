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
    static int      nodesPerElement;
    static float    totalLength;
    static float    crossSection;
    static float    thermalConductivity;
    static float    alpha;
    static float    tInfinity;
    static float    thermalStreamQ;

    static std::vector<float>  elementsLength;
    static std::vector<float>  elementsCrossSection;
    static std::vector<float>  elementsConductivity;


public:
    GlobalData(std::string inputFilePath);

    void readLine(std::string identifier, float value);

    static void initLists();

    GlobalData(int noElements, int noNodes, float totalLength, float crossSection,
               float thermalConductivity, float alpha, float tempInfinity, float thermalStreamQ);

    void elementsLocalDataInit(std::vector<float> lengths,
                    std::vector<float> sections, std::vector<float> conductivity){

    }

};


#endif //MESTHERMALSOLVER1_GLOBALDATA_H
