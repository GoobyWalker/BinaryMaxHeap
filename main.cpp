#include <iostream>

#include "BinaryMaxHeap.h"


int main() {

    BinaryMaxHeap<int> heap1;
    BinaryMaxHeap<std::string> heap2;
    BinaryMaxHeap<int> heap3;

    heap1.insert(3, 4);
    heap2.insert(8, "four");
    heap3.insert(5, 90);
    heap1.insert(2, 9);

    BinaryMaxHeap<int> heap4 = BinaryMaxHeap::merge(heap1, heap2);

    return 0;

}
