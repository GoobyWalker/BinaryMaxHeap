#include <iostream>

#include "BinaryMaxHeap.h"


int main() {

    BinaryMaxHeap<int> heap1;
    BinaryMaxHeap<std::string> heap2;

    heap1.insert(3, 4);
    heap2.insert(3, "four");

    return 0;

}
