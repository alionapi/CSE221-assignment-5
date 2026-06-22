#include "dijkstra.h"

Dijkstra::Dijkstra(Graph* graph) : graph(graph) {}

void Dijkstra::get_fastest_path(const std::string& source, const std::string& destination) {
    int distances[MAX_PLACES];
    std::string predecessors[MAX_PLACES];
    bool visited[MAX_PLACES] = {false};
    Heap priority_queue(MAX_PLACES);
    int source_idx = graph->find_vertex(source);
    int dest_idx = graph->find_vertex(destination);
    if (source_idx == -1 || dest_idx == -1) {
        throw std::runtime_error("Not found");
    }
    for (int i = 0; i < MAX_PLACES; ++i) {
        distances[i] = MAX_INT;
        predecessors[i] = "";
    }
    distances[source_idx] = 0;
    priority_queue.insert(0, source);
    while (!priority_queue.empty()) {
        std::string current_place = priority_queue.get_min_value(); // Fixed access to root
        priority_queue.remove_min();
        int current_idx = graph->find_vertex(current_place);
        if (visited[current_idx]) continue;
        visited[current_idx] = true;
        for (int i = 0; i < graph->get_vertex_count(); ++i) {
            const auto& edge = graph->get_edge(current_idx, i);
            if (edge.weight > 0 && !visited[i]) {
                int new_dist = distances[current_idx] + edge.weight;
                if (new_dist < distances[i]) {
                    distances[i] = new_dist;
                    predecessors[i] = current_place;
                    priority_queue.insert(new_dist, graph->get_vertex(i));
                }
            }
        }
    }
    std::string path = destination;
    std::string current = destination;
    while (current != source) {
        int idx = graph->find_vertex(current);
        if (predecessors[idx] == "") break;
        current = predecessors[idx];
        path = current + " " + path;
    }

    std::cout << path << "\n";
}
void Dijkstra::get_fastest_distance(const std::string& source, const std::string& destination) {
    int distances[MAX_PLACES];
    bool visited[MAX_PLACES] = {false};
    Heap priority_queue(MAX_PLACES);
    int source_idx = graph->find_vertex(source);
    int dest_idx = graph->find_vertex(destination);
    if (source_idx == -1 || dest_idx == -1) {
        throw std::runtime_error("Not found");
    }
    for (int i = 0; i < MAX_PLACES; ++i) {
        distances[i] = MAX_INT;
    }
    distances[source_idx] = 0;
    priority_queue.insert(0, source);
    while (!priority_queue.empty()) {
        std::string current_place = priority_queue.get_min_value();
        priority_queue.remove_min();

        int current_idx = graph->find_vertex(current_place);
        if (visited[current_idx]) continue;
        visited[current_idx] = true;
        for (int i = 0; i < graph->get_vertex_count(); ++i) {
            const auto& edge = graph->get_edge(current_idx, i);
            if (edge.weight > 0 && !visited[i]) {
                int new_dist = distances[current_idx] + edge.weight;
                if (new_dist < distances[i]) {
                    distances[i] = new_dist;
                    priority_queue.insert(new_dist, graph->get_vertex(i));
                }
            }
        }
    }
    std::cout << distances[dest_idx] << "\n";
}