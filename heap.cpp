#include "heap.h"

Heap::Heap(int capacity) : size(0) {
    if (capacity > MAX_HEAP_SIZE) {
        throw std::runtime_error("Heap capacity exceeds maximum allowed size");
    }
}
Heap::~Heap() {}
bool Heap::empty() const {
    return size == 0;
}
void Heap::insert(int key, const std::string& value) {
    if (size >= MAX_HEAP_SIZE) {
        throw std::runtime_error("Heap is full");
    }
    heap[size] = {key, value};
    heapify_up(size);
    ++size;
}
void Heap::remove_min() {
    if (empty()) {
        throw std::runtime_error("Heap is empty");
    }
    heap[0] = heap[--size];
    heapify_down(0);
}
std::string Heap::get_min_value() const {
    if (empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0].value;
}
void Heap::replace_key(int index, int new_key) {
    if (index < 1 || index > size) {
        throw std::out_of_range("Invalid index");
    }
    int heap_index = index - 1;
    heap[heap_index].key = new_key;
    heapify_up(heap_index);
    heapify_down(heap_index);
}
void Heap::print_heap() const {
    int level = 1;
    for (int i = 0; i < size; ++i) {
        if (i == level - 1) {
            std::cout << "\n";
            level *= 2;
        }
        std::cout << heap[i].key << " ";
    }
    std::cout << "\n";
}
void Heap::heapify_up(int index) {
    while (index > 0 && heap[parent(index)].key > heap[index].key) {
        std::swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}
void Heap::heapify_down(int index) {
    int smallest = index;
    int left = left_child(index);
    int right = right_child(index);
    if (left < size && heap[left].key < heap[smallest].key) {
        smallest = left;
    }
    if (right < size && heap[right].key < heap[smallest].key) {
        smallest = right;
    }
    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapify_down(smallest);
    }
}