#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"
#include <string>

class Heap{
    public:

        Heap();
        void buildHeap();
        void heapitUp(int index);
        void heapitDown(int index);
        int readLines(std::string fileName);
        void decreaseKey(int index, int newKey);
        void extractMin();
        void insert(int index);
        
        void write(const std::string &outputFile);
        void printArray();
        void printHeap();

        std::string fileName;
        std::string line; 
        private:
        ELEMENT **V;
        HEAP *pHeap;
};
#endif