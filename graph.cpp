#include "graph.h"
#include <stdexcept>

Graph::Graph() : vertex_count(0) {
    for (int i = 0; i < MAX_PLACES; ++i) {
        vertices[i] = "";
        for (int j = 0; j < MAX_PLACES; ++j) {
            edges[i][j] = {"", 0};
        }
    }
}
Graph::~Graph() {}
int Graph::find_vertex(const std::string& vertex) const {
    for (int i = 0; i < vertex_count; ++i) {
        if (vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}
void Graph::insert_vertex(const std::string& place) {
    if (find_vertex(place) == -1) {
        if (vertex_count >= MAX_PLACES) {
            throw std::runtime_error("Max places reached");
        }
        vertices[vertex_count++] = place;
    }
}
void Graph::insert_edge(const std::string& v, const std::string& w, int distance) {
    if (v == w || distance <= 0) return;
    insert_vertex(v);
    insert_vertex(w);
    int v_idx = find_vertex(v);
    int w_idx = find_vertex(w);
    edges[v_idx][w_idx] = {w, distance};
    edges[w_idx][v_idx] = {v, distance};
}
void Graph::erase_vertex(const std::string& place) {
    int v_idx = find_vertex(place);
    if (v_idx == -1) return;
    for (int i = 0; i < vertex_count; ++i) {
        edges[v_idx][i] = {"", 0};
        edges[i][v_idx] = {"", 0};
    }
    for (int i = v_idx; i < vertex_count - 1; ++i) {
        vertices[i] = vertices[i + 1];
        for (int j = 0; j < vertex_count; ++j) {
            edges[i][j] = edges[i + 1][j];
            edges[j][i] = edges[j][i + 1];
        }
    }

    vertex_count--;
}
void Graph::erase_edge(const std::string& v, const std::string& w) {
    int v_idx = find_vertex(v);
    int w_idx = find_vertex(w);
    if (v_idx == -1 || w_idx == -1) return;
    edges[v_idx][w_idx] = {"", 0};
    edges[w_idx][v_idx] = {"", 0};
}
bool Graph::is_adjacent_to(const std::string& v, const std::string& w) const {
    int v_idx = find_vertex(v);
    int w_idx = find_vertex(w);
    return v_idx != -1 && w_idx != -1 && edges[v_idx][w_idx].weight > 0;
}
void Graph::print_graph() const {
    for (int i = 0; i < vertex_count; ++i) {
        for (int j = i + 1; j < vertex_count; ++j) {
            if (edges[i][j].weight > 0) {
                std::cout << vertices[j] << " " << vertices[i] << " " << edges[i][j].weight << "\n";
            }
        }
    }
}