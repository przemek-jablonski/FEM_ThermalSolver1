#include <iostream>
#include <vector>
#include "GlobalData.h"
#include "Node.h"
#include "FiniteElement.h"
#include "FEMGrid.h"

using namespace std;

int main() {

    GlobalData("/Users/Ciemek/dev/projects/MesThermalSolver1/FileInput.txt");
  //  std::cout << "after globaldata" << std::endl;
    //Lists of nodes and elements:
    Node               *nodes = new Node[GlobalData::numberOfNodes];
    FiniteElement      *elements = new FiniteElement[GlobalData::numberOfElements];

    //Generating Finite Elements Grid:
    FEMGrid femGrid(elements, GlobalData::numberOfElements);



    //MANUAL: Node Map for 5node-4element model:

    nodes[0] = Node(0,GlobalData::thermalStreamQ);
    nodes[1] = Node(1);
    nodes[2] = Node(2);
    nodes[3] = Node(3);
    nodes[4] = Node(4, 0, GlobalData::alpha, GlobalData::tInfinity);


    //MANUAL: Node Map for 3node-2element model:
    /*
    nodes[0] = Node(0,GlobalData::thermalStreamQ);
    nodes[1] = Node(1);
    nodes[2] = Node(2, 0, GlobalData::alpha, GlobalData::tInfinity);
    */


    //ELEMENTS creation (count-agnostic):
    /*
    elements[0] = FiniteElement(0, GlobalData::nodesPerElement, nodes, GlobalData::elementsLength[0],
                                GlobalData::elementsCrossSection[0], GlobalData::elementsConductivity[0]);
    elements[1] = FiniteElement(1, GlobalData::nodesPerElement, nodes, GlobalData::elementsLength[1],
                                GlobalData::elementsCrossSection[1], GlobalData::elementsConductivity[1]);
    elements[2] = FiniteElement(2, GlobalData::nodesPerElement, nodes, GlobalData::elementsLength[2],
                                GlobalData::elementsCrossSection[2], GlobalData::elementsConductivity[2]);
    elements[3] = FiniteElement(3, GlobalData::nodesPerElement, nodes, GlobalData::elementsLength[3],
                                GlobalData::elementsCrossSection[3], GlobalData::elementsConductivity[3]);
*/

    for (int i=0; i < GlobalData::numberOfElements; ++i) {
        elements[i] = FiniteElement(i, GlobalData::nodesPerElement, nodes, GlobalData::elementsLength[i],
                                    GlobalData::elementsCrossSection[i], GlobalData::elementsConductivity[i]);
    }


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

    femGrid.calculateAllTemperatures();
    femGrid.printTemperatures();


    //Deallocating containers:
    delete[] nodes;
    delete[] elements;

    return 0;
}