#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>

#define MAX_PLACES 100

struct Edge {
    std::string destination;
    int weight;
};

class Graph {
public:
    Graph();
    ~Graph();

    void insert_vertex(const std::string& place);
    void insert_edge(const std::string& v, const std::string& w, int distance);
    void erase_vertex(const std::string& place);
    void erase_edge(const std::string& v, const std::string& w);
    bool is_adjacent_to(const std::string& v, const std::string& w) const;
    void print_graph() const;

    // Expose necessary data for Dijkstra
    int get_vertex_count() const { return vertex_count; }
    std::string get_vertex(int index) const { return vertices[index]; }
    int find_vertex(const std::string& vertex) const;
    const Edge& get_edge(int v_idx, int w_idx) const { return edges[v_idx][w_idx]; }

private:
    std::string vertices[MAX_PLACES];
    Edge edges[MAX_PLACES][MAX_PLACES];
    int vertex_count;
};

#endif // GRAPH_H
