#ifndef BINARYMAXHEAP_BINARYMAXHEAP_H
#define BINARYMAXHEAP_BINARYMAXHEAP_H


#include <vector>


template <typename TYPE>
class BinaryMaxHeap {

private:

    std::vector< std::pair<int, TYPE> > data;

    int rootIndex() {
        return 0;
    }

    int lastIndex() {
        return data.size - 1;
    }

    int parentIndex( int currentIndex ) {
        return (currentIndex - 1) / 2;
    }

    int leftChildIndex( int currentIndex ) {

        int leftChildIndex = currentIndex * 2 + 1;

        // If there is no left child node, return index of -1
        if ( leftChildIndex > this->lastIndex() ) {
            return -1;
        }

        return leftChildIndex;

    }

    int rightChildIndex( int currentIndex ) {

        int rightChildIndex = currentIndex * 2 + 2;

        // If there is no right child node, return index of -1
        if ( rightChildIndex > this->lastIndex() ) {
            return -1;
        }

        return rightChildIndex;

    }

    int largestChildIndex( int currentIndex ) {

        int leftChildIndex = this->leftChildIndex(currentIndex);
        int rightChildIndex = this->rightChildIndex(currentIndex);

        // If there is no right child node, return index of left child
        // If there is no children nodes, return index of -1
        if ( rightChildIndex == -1 ) {
            return leftChildIndex;
        }

        if ( this->data[leftChildIndex].first > this->data[rightChildIndex].first ) {
            return leftChildIndex;
        }
        else {
            return rightChildIndex;
        }

    }


public:

    /*
Getters and Setters
    */

    TYPE root() {
        return data[rootIndex()].second;
    }

    TYPE last() {
        return data[lastIndex()].second;
    }


    /*
Class Member Functions
    */

    // Insert Operation
    void insert( int priority, TYPE value ) {

        // Add new pair to last space in heap
        this->data.push_back( std::pair<int, TYPE>(priority, value) );

        // Correct heap upward, if currentIndex is root, parentIndex is also root

        int currentIndex = this->lastIndex();
        int parentIndex = this->parentIndex(currentIndex);

        while ( this->data[currentIndex].first > this->data[parentIndex].first ) {

            std::swap(this->data[currentIndex].first, this->data[parentIndex].first);

            currentIndex = parentIndex;
            parentIndex = this->parentIndex(currentIndex);

        }

    }

    // Read Operation
    std::pair<int, TYPE> read() {

        if ( this->data.size == 0 ) {
            return NULL;
        }

        return this->data[this->rootIndex()];

    }

    // Delete Operation
    void remove() {

        if ( this->data.size == 0 ) {
            return;
        }

        // Move value in last space in heap to root
        this->data[this->rootIndex()].first = this->data[this->lastIndex()].first;
        this->data.pop_back();

        // Correct heap downward, while currentIndex is smaller
        // than its largest child and has at least one child

        int currentIndex = this->rootIndex();
        int largestChildIndex = this->largestChildIndex(currentIndex);

        while ( largestChildIndex != -1 && this->data[currentIndex].first < this->data[largestChildIndex].first ) {

            std::swap(this->data[currentIndex].first, this->data[largestChildIndex].first);

            currentIndex = largestChildIndex;
            largestChildIndex = this->largestChildIndex(currentIndex);

        }

        return;

    }


    // Merge Two Heaps
    static BinaryMaxHeap<TYPE> merge( BinaryMaxHeap<TYPE> inputHeap1, BinaryMaxHeap<TYPE> inputHeap2 ) {

        BinaryMaxHeap<TYPE> outputHeap;

        std::pair<int, TYPE> root1 = inputHeap1.read();
        std::pair<int, TYPE> root2 = inputHeap2.read();

        while ( inputHeap1.size != 0 || inputHeap2.size != 0 ) {

            if (inputHeap1.size == 0) {

                while (inputHeap2.size != 0) {

                    outputHeap.insert(root2);
                    inputHeap2.remove();
                    root2 = inputHeap2.read();

                }

                break;

            }

            if (inputHeap2.size == 0) {

                while (inputHeap1.size != 0) {

                    outputHeap.insert(root1);
                    inputHeap1.remove();
                    root1 = inputHeap1.read();

                }

                break;

            }

            if (root1.first >= root2.first) {

                outputHeap.insert(root1);
                inputHeap1.remove();
                root1 = inputHeap1.read();

            } else {

                outputHeap.insert(root2);
                inputHeap2.remove();
                root2 = inputHeap2.read();

            }

        }

        return outputHeap;
        
    }

};

#endif
