#include "util.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include "data_structures.h"
#include "heap.h"


Util util;
void Util::printError(const char *msg) {
    std::cerr << msg << std::endl;
    
}

void Util::checkCommand(int arg, char *argv[]) {
    if (arg < 2 || arg > 3) {
        std::cout << "Usage: ./PJ3 <I-File> <O-File> " << std::endl  << " <I-File>> is the input file " << std::endl
                << " <O-File> is the output file" << std::endl;
        
    }
    
    util.inputFile = argv[1];
    util.outputFile = argv[2];
    for (int i = 0; i < arg; i++) {
        //std::cout << argv[i] << std::endl;
        
    }
    
}


void Util::processInstructions() {
    Heap heap;
    std::string line;
    while (true) {
        //std::cout << "Enter instruction: ";
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string instruction;
        iss >> instruction;

        if (instruction == "Read") {
            std::cout << "Instruction: Read" << std::endl;
            heap.readLines(util.inputFile);
            
        } else if (instruction == "Stop") {
            std::cout << "Instruction: Stop" << std::endl;
            break;
        } else if (instruction == "PrintArray") {
            heap.printArray();
        } else if (instruction == "BuildHeap") {
            heap.buildHeap();
        } else if (instruction == "PrintHeap") {
            heap.printHeap();
        } else if (instruction == "Insert") {
            int index;
            iss >> index;
            heap.insert(index);
        } else if (instruction == "ExtractMin") {
            heap.extractMin();
        } else if (instruction == "DecreaseKey") {
            int index;
            int newKey;
            iss >> index >> newKey;
            heap.decreaseKey(index, newKey);
        } else if (instruction == "Write") {
            heap.write(util.outputFile);
        } else {
            printError("Warning: Invalid Instruction");
        }
    }
}
