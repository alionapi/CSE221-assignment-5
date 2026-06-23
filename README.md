# CSE221-assignment-5
CSE221: Data Structures | Fall 2024 | Shortest Way to a Cat

A C++ implementation of graph-based shortest path search using Dijkstra's algorithm. The project models the UNIST campus as a weighted undirected graph and finds the shortest path from a starting location to a cat's location using a custom graph representation and a heap-based priority queue.

## Features

* Graph representation using adjacency lists
* Binary heap implementation
* Priority queue operations
* Dijkstra's shortest path algorithm
* Weighted undirected graph support
* Efficient shortest path computation

## Repository Structure

```text
.
├── Makefile                  # Build configuration
├── PA5 description_v1.0.pdf  # Assignment specification
├── README.md                 # This file
├── main.cpp                  # Test driver
├── graph.cpp
├── graph.h                   # Graph implementation
├── heap.cpp
├── heap.h                    # Heap-based priority queue
├── dijkstra.cpp
└── dijkstra.h                # Dijkstra's algorithm
```

## Components

### Graph

Implements an adjacency list representation of a weighted undirected graph.

Features:

* Vertex storage
* Edge insertion
* Neighbor traversal
* Distance information management

### Heap

Implements a vector-based binary heap used as a priority queue.

Supported operations:

* Insertion
* Removal of minimum element
* Heapify operations
* Priority maintenance

### Dijkstra

Implements Dijkstra's shortest path algorithm using:

* The graph from `graph.cpp`
* The heap-based priority queue from `heap.cpp`

Features:

* Shortest distance computation
* Path exploration
* Efficient vertex selection

## Algorithm

1. Initialize distances from the source vertex.
2. Insert the source into the priority queue.
3. Repeatedly extract the vertex with the smallest distance.
4. Relax adjacent edges.
5. Update distances and insert improved vertices into the heap.
6. Continue until all reachable vertices have been processed.

## Building

Compile the project with:

```bash
make
```

This generates:

```text
main
```

## Main Source Files

### graph.cpp

Implements:

* Adjacency list graph representation
* Vertex and edge operations

### heap.cpp

Implements:

* Binary heap operations
* Priority queue functionality

### dijkstra.cpp

Implements:

* Dijkstra's shortest path algorithm
* Distance updates and path computation

## Course Information

**Course:** CSE221 Data Structures
**Semester:** Fall 2024

