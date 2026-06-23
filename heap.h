#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <iostream>
#include <stdexcept>

#define MAX_HEAP_SIZE 100

struct HeapNode {
    int key;
    std::string value;
};

class Heap {
public:
    Heap(int capacity);
    ~Heap();

    bool empty() const;
    void insert(int key, const std::string& value);
    void remove_min();
    void replace_key(int index, int new_key);
    void print_heap() const;

    // New method to get the value of the root element
    std::string get_min_value() const;

private:
    HeapNode heap[MAX_HEAP_SIZE];
    int size;

    int parent(int index) const { return (index - 1) / 2; }
    int left_child(int index) const { return 2 * index + 1; }
    int right_child(int index) const { return 2 * index + 2; }
    void heapify_up(int index);
    void heapify_down(int index);
};

#endif // HEAP_H
