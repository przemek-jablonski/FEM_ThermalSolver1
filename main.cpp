#include <iostream>
#include <vector>
#include "GlobalData.h"
#include "Node.h"
#include "FiniteElement.h"
#include "FEMGrid.h"

using namespace std;

int main() {
    //temporary variables:

    int                 elementsCount = 2;
    int                 nodesCount = (elementsCount +1);
    float               globalLength = 5;
    float               globalK = 50;
    float               globalS = 2;
    float               boundaryConditionStart = 0;     // dla x=0
    float               boundaryConditionEnd  = 0;      // dla x=L
    float               alpha = 10;
    float               q = - 300;
    float               tInfinity = 400;


    std::vector<float>  elementsLength(elementsCount);
    std::vector<float>  elementsCrossSection(elementsCount);
    std::vector<float>  elementsConductivity(elementsCount);
    elementsLength[0] = 2.5f;
    elementsLength[1] = 2.5f;
    elementsCrossSection[0] = 2;
    elementsCrossSection[1] = 2;
    elementsConductivity[0] = 50;
    elementsConductivity[1] = 50;

    GlobalData(elementsCount, nodesCount, globalLength, globalS, globalK, alpha, tInfinity, q);


    std::vector<Node>   nodes(GlobalData::numberOfNodes);
    FiniteElement      *elements = new FiniteElement[GlobalData::numberOfElements];

    nodes[0] = Node(0,0,0);
    nodes[1] = Node(1,0,0);
    nodes[2] = Node(2,0,0);

    elements[0] = FiniteElement(&nodes[0], &nodes[1], elementsLength[0],
                                elementsCrossSection[0], elementsConductivity[0]);
    elements[1] = FiniteElement(&nodes[1], &nodes[2], elementsLength[1],
                                elementsCrossSection[1], elementsConductivity[1]);



   // FEMGrid femGrid;
   // femGrid.addElementToGrid(FiniteElement(&nodes[0], &nodes[1], elementsLength[0],
   //                                        elementsCrossSection[0], elementsConductivity[0]));
//    femGrid.addElementToGrid(elements[1]);
//    femGrid.printAll();

    

    std::cout << "testing femgrid" << std::endl;

    FEMGrid femGrid(elements, GlobalData::numberOfElements);
    femGrid.printAll();

/*
    for (int i=0; i < GlobalData::numberOfNodes; ++i)
        nodes[i] = Node(i, 0, 0);

    for (int i = 0; i < GlobalData::numberOfElements; ++i)
        elements[i] = FiniteElement();
*/
    return 0;
}