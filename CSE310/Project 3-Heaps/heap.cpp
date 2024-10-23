#include "heap.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include "data_structures.h"
#include "util.h"
#include <iomanip>
 
 
 Heap::Heap() :fileName(""), line(""){

 }
 
 void Heap::printArray() {
    Util util;
    std::cout << "Instruction: PrintArray" << std::endl;
    if (V == nullptr) {
        util.printError("Error: array is NULL");
        return;
    }
     
    for (int i = 1; i <= pHeap->capacity; ++i) {
        float num = V[i]->key;
        if (V[i] != nullptr) {
            std::cout << V[i]->index << " " <<std::fixed << std::setprecision(6)<< num << " " << V[i]->pos << std::endl;
        }
    }
}
    int Heap::readLines(std::string fileName) {
        std::ifstream fileStream;
        Util util;
        while (true) {
            fileStream.open(fileName, std::ifstream::in);
            if (fileStream.is_open()) {

                int n;
                fileStream >> n;

                if (n <= 0) {
                    std::cerr << "Error: Invalid number of elements (n = " << n << ")" << std::endl;
                    return 0;  // Fail early if n is invalid
                }
                
                // // Debug: Print n value
                // std::cout << "Number of elements: " << n << std::endl;

                // memory for V
                V = new ELEMENT*[n + 1]; 
                for (int i = 1; i <= n; ++i) {
                    V[i] = new ELEMENT;
                    fileStream >> V[i]->key;

                    // Debug: Print key and index values
                    //std::cout << "V[" << i << "]->key: " << V[i]->key << std::endl;

                    V[i]->index = i;
                    V[i]->pos = 0;

                    // Debug: Check if pointer is valid
                    if (V[i] == nullptr) {
                        std::cerr << "Error: Memory allocation failed for V[" << i << "]" << std::endl;
                        return 0;
                    }
                }
                // Allocate memory for pHeap
                pHeap = new HEAP;
                if (pHeap == nullptr) {
                    std::cerr << "Error: Memory allocation failed for pHeap" << std::endl;
                    return 0;
                }

                pHeap->H = new int[n + 1]; // 1-based index
                pHeap->capacity = n;
                pHeap->size = 0;

                // // Debug: Print heap capacity
                // std::cout << "Heap allocated with capacity: " << pHeap->capacity << std::endl;

                // Reading the rest of the file
                std::string line;
                while (std::getline(fileStream, line)) {
                    // std::cout << "Read line: " << line << std::endl;
                }
                fileStream.close();
                
                return 1; // Successful read
            } else {
                util.printError("File did not open properly");
                std::cout << "Please input the filename again: ";
                std::cin >> fileName;
            }
        }
    }
    void Heap::buildHeap() {
        Util util;
        std::cout << "Instruction: BuildHeap" << std::endl;
        if (V == nullptr || pHeap == nullptr) {
            util.printError("Error: array or heap is NULL");
            return;
        }

        pHeap->size = pHeap->capacity;
        for (int i = 1; i <= pHeap->capacity; ++i) {
            V[i]->pos = i;
            pHeap->H[i] = i;
        }

        // Apply the linear-time BuildHeap algorithm
        for (int i = pHeap->size / 2; i >= 1; --i) {
            heapitDown(i);
        }
        }
    void Heap::printHeap() {
        Util util;
        std::cout << "Instruction: PrintHeap" << std::endl;

        std::cout << "Capacity = " << pHeap->capacity << ", size = " << pHeap->size << std::endl;
        if (pHeap == nullptr) {
            util.printError("Error: heap is NULL");
            return;
        }

        for (int i = 1; i <= pHeap->size; ++i) {
            float num = V[i]->key;
            int index = pHeap->H[i];
            std::cout << "H[" << i << "] = " << pHeap->H[i]  << std::endl;
            //std::cout << index << " " << std::fixed << std::setprecision(6) << num << V[index]->pos << std::endl;
        }
    }

    void Heap::heapitUp(int pos) {
        while (pos > 1 && V[pHeap->H[pos]]->key < V[pHeap->H[pos / 2]]->key) {
            std::swap(pHeap->H[pos], pHeap->H[pos / 2]);
            V[pHeap->H[pos]]->pos = pos;
            V[pHeap->H[pos / 2]]->pos = pos / 2;
            pos = pos / 2;
        }
    }

    void Heap::heapitDown(int pos) {
        int smallest = pos;
        int left = 2 * pos;
        int right = 2 * pos + 1;

        if (left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key) {
            smallest = left;
        }
        if (right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key) {
            smallest = right;
        }
        if (smallest != pos) {
            std::swap(pHeap->H[pos], pHeap->H[smallest]);
            V[pHeap->H[pos]]->pos = pos;
            V[pHeap->H[smallest]]->pos = smallest;
            heapitDown(smallest);
        }
    }

    void Heap::insert(int index) {
        Util util;
        std::cout << "Instruction: Insert " << index << std::endl;
        if (index < 1 || index > pHeap->capacity) {
            util.printError("Error: index out of bound");
            return;
        }
        if (V[index]->pos != 0) {
            util.printError("Error: V[index] already in the heap");
            return;
        }

        pHeap->size++;
        pHeap->H[pHeap->size] = index;
        V[index]->pos = pHeap->size;
        heapitUp(pHeap->size);

        std::cout << "Element V[" << index << "] inserted into the heap" << std::endl;
    }

    void Heap::extractMin() {
        std::cout << "Instruction: ExtractMin" << std::endl;

        if (pHeap == NULL) {
            std::cerr << "Error: heap is NULL" << std::endl;
            return;
        }

        if (pHeap->size == 0) {
            std::cerr << "Error: heap is empty" << std::endl;
            return;
        }

        int minElement = pHeap->H[1];
        V[minElement]->pos = 0; // Mark as removed

        pHeap->H[1] = pHeap->H[pHeap->size];
        pHeap->size--;
        heapitDown(1);
    }

    void Heap::write(const std::string &outputFile) {
    //std::cout << "Outputfile: " << outputFile << std::endl;
    Util util;
    std::cout << "Instruction: Write" << std::endl;
    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        util.printError("Error: could not open output file");
        return;
    }

    if (V == nullptr) {
        util.printError("Error: V is NULL");
        return;
    }

    for (int i = 1; i <= pHeap->capacity; ++i) {
        float num = V[i]->key;
        if (V[i] != nullptr) {
            outFile << i << " " << std::fixed << std::setprecision(6) << num << " " << V[i]->pos << std::endl;
        }
    }

    outFile.close();
    }

    void Heap::decreaseKey(int index, int newKey) {
        Util util;
        float num = newKey;
        std::cout << "Instruction: DecreaseKey " << index << " " << std::fixed << std::setprecision(6) << num<< std::endl;

        if (index < 1 || index >= pHeap->capacity || newKey >= V[index]->key) {
            util.printError("Error: invalid call to DecreaseKey");
            return;
        }

        if (V[index]->pos == 0) {
            util.printError("Error: V[index] not in the heap");
            return;
        }

        V[index]->key = newKey;
        heapitUp(V[index]->pos);
    }
 