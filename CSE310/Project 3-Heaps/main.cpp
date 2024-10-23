//boilerplate main class
#include <iostream>
#include "util.h"
#include <cstring>
#include "heap.h"

using namespace std;

int main(int arg, char *argv[]){
    Util util;
    Heap heap;
    util.checkCommand(arg, argv);
    std::string fileName = argv[1];
    // while (true) {
    //     // Only call readLines again if the previous one failed
        
    // }
    heap.readLines(fileName);
    // Proceed to accept user input
    util.processInstructions();

    return 0;
}


