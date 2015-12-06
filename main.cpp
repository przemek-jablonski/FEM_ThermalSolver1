#include <iostream>
#include <vector>
#include "GlobalData.h"
#include "Node.h"
#include "FiniteElement.h"
#include "FEMGrid.h"

using namespace std;

int main() {

    //Model data:
    int                 elementsCount = 4;
    int                 nodesCount = (elementsCount +1);
    float               globalLength = 5;
    float               globalK = 50;
    float               globalS = 2;
    float               boundaryConditionStart = 0;     // dla x=0
    float               boundaryConditionEnd  = 0;      // dla x=L
    float               alpha = 10;
    float               q = - 300;
    float               tInfinity = 400;

    //Declaration of lists containing specific data for every element:
    std::vector<float>  elementsLength(elementsCount);
    std::vector<float>  elementsCrossSection(elementsCount);
    std::vector<float>  elementsConductivity(elementsCount);

    //Feeding containers with data:
    elementsLength[0] = 2.5f;
    elementsLength[1] = 2.5f;
    elementsLength[2] = elementsLength[3] = 2.5f;
    elementsCrossSection[0] = 2;
    elementsCrossSection[1] = 2;
    elementsCrossSection[2] = elementsCrossSection[3] = 2;
    elementsConductivity[0] = 50;
    elementsConductivity[1] = 50;
    elementsConductivity[2] = elementsConductivity[3] = 50;

    //Feeding GlobalData static class with global data:
    GlobalData(elementsCount, nodesCount, globalLength, globalS, globalK, alpha, tInfinity, q);

    //Lists of nodes and elements:
    Node               *nodes = new Node[GlobalData::numberOfNodes];
    FiniteElement      *elements = new FiniteElement[GlobalData::numberOfElements];

    //Generating Finite Elements Grid:
    FEMGrid femGrid(elements, GlobalData::numberOfElements);



    //NODES creation (count-agnostic):
    nodes[0] = Node(0,q/2);
    nodes[1] = Node(1);
    nodes[2] = Node(2);
    nodes[3] = Node(3);
    nodes[4] = Node(4, 0, alpha, tInfinity);

    //ELEMENTS creation (count-agnostic):
    elements[0] = FiniteElement(0, 2, nodes, elementsLength[0],
                                elementsCrossSection[0], elementsConductivity[0]);
    elements[1] = FiniteElement(1, 2, nodes, elementsLength[1],
                                elementsCrossSection[1], elementsConductivity[1]);
    elements[2] = FiniteElement(2, 2, nodes, elementsLength[2],
                                elementsCrossSection[2], elementsConductivity[2]);
    elements[3] = FiniteElement(3, 2, nodes, elementsLength[3],
                                elementsCrossSection[3], elementsConductivity[3]);



    //Calculating local data for every element.
    //Printing results (Local P-Vector and H-Matrix) for debug reasons:
    for (int i = 0; i < GlobalData::numberOfElements; ++i) {
        femGrid.elements[i].calculateAll();
        femGrid.elements[i].printLocalMatrixes();
    }

    //Calculating global data for all of the elements on the grid:
    femGrid.calculateGlobalHMatrix();
    femGrid.calculateGlobalPVector();

    //Printing global results of calculations to screen (debug):
    femGrid.printGlobalHMatrix();
    femGrid.printGlobalPVector();




    //Deallocating containers:
    delete[] nodes;
    delete[] elements;

    return 0;
}