#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include "heap.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>

// Do not change the class name
class Dijkstra {
public:
    Dijkstra(Graph* graph);

    void get_fastest_path(const std::string& source, const std::string& destination);
    void get_fastest_distance(const std::string& source, const std::string& destination);

private:
    Graph* graph;

    // Define a large value to substitute INT_MAX
    static const int MAX_INT = 1000000;
};

#endif // DIJKSTRA_H
