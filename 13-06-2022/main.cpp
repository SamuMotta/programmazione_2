#include "vertex.h"

#include <iostream>

using namespace std;

int main() {

    Grafo<int> g;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addEdge(1,2);
    g.addEdge(3,2);
}