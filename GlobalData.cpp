//
// Created by Przemysław Jabłoński on 05/12/15.
//

#include <string>
#include <fstream>
#include <iostream>
#include "GlobalData.h"

int      GlobalData::numberOfElements;
int      GlobalData::numberOfNodes;
int      GlobalData::nodesPerElement;
float    GlobalData::totalLength;
float    GlobalData::crossSection;
float    GlobalData::thermalConductivity;
//int      GlobalData::HMatrixArrayInverter[2][2];
float    GlobalData::alpha;
float    GlobalData::tInfinity;
float    GlobalData::thermalStreamQ;
std::vector<float>  GlobalData::elementsLength;
std::vector<float>  GlobalData::elementsCrossSection;
std::vector<float>  GlobalData::elementsConductivity;


GlobalData::GlobalData(std::string inputFilePath) {
    std::cout << "constructing global data" << std::endl;
    std::ifstream input(inputFilePath);

    if(!input.is_open()) {
        std::cout << "cannot open file." << std::endl;
    } else std::cout << "file opened." << std::endl;

    std::string line;
    double value;

    while(input >> line >> value) {
        readLine(line, value);
    }

}

void GlobalData::readLine(std::string identifier, float value) {

    std::cout << "reading line of input (" << identifier << " / " << value << ")." << std::endl;
    if (identifier=="numberOfElements") {
        numberOfElements = value;
        initLists();

    }
    if (identifier=="numberOfNodes") numberOfNodes = value;
    if (identifier=="nodesPerElement") nodesPerElement = value;
    if (identifier=="globalLength") totalLength = value;
    if (identifier=="globalK") thermalConductivity = value;
    if (identifier=="globalS") crossSection = value;
    if (identifier=="elementsLength[0]") elementsLength[0] = value;
    if (identifier=="elementsLength[1]") elementsLength[1] = value;
    if (identifier=="elementsLength[2]") elementsLength[2] = value;
    if (identifier=="elementsLength[3]") elementsLength[3] = value;
    if (identifier=="elementsLength[4]") elementsLength[4] = value;
    if (identifier=="elementsCrossSection[0]") elementsCrossSection[0] = value;
    if (identifier=="elementsCrossSection[1]") elementsCrossSection[1] = value;
    if (identifier=="elementsCrossSection[2]") elementsCrossSection[2] = value;
    if (identifier=="elementsCrossSection[3]") elementsCrossSection[3] = value;
    if (identifier=="elementsCrossSection[4]") elementsCrossSection[4] = value;
    if (identifier=="elementsConductivity[0]") elementsConductivity[0] = value;
    if (identifier=="elementsConductivity[1]") elementsConductivity[1] = value;
    if (identifier=="elementsConductivity[2]") elementsConductivity[2] = value;
    if (identifier=="elementsConductivity[3]") elementsConductivity[3] = value;
    if (identifier=="elementsConductivity[4]") elementsConductivity[4] = value;
    if (identifier=="alpha") alpha = value;
    if (identifier=="q") thermalStreamQ = value;
    if (identifier=="tInfinity") tInfinity = value;


}

void GlobalData::initLists(){
    GlobalData::elementsLength.resize(GlobalData::numberOfElements);
    GlobalData::elementsCrossSection.resize(GlobalData::numberOfElements);
    GlobalData::elementsConductivity.resize(GlobalData::numberOfElements);
}


