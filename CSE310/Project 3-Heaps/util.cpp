#include "util.h"
#include <iostream>
#include <cstring>

Util::Util() : fileName(""), line("") {
    

}
    void Util::printError(const char *msg) {
        std::cerr << msg << std::endl;
    }

    void Util::checkCommand(int arg, char *argv[]) {
        if (arg < 2 || arg > 3) {
            std::cout << "Usage: ./PJ3 <I-File> <O-File> " << std::endl  << " <I-File>> is the input file " << std::endl
                    << " <O-File> is the output file" << std::endl;
            
        }
        for (int i = 0; i < arg; i++) {
            std::cout << argv[i] << std::endl;
            if (strcmp(argv[i], "Stop") == 0) {
                std::cout << "instruction: Stop" << std::endl;
            } else if (strcmp(argv[i], "Read") == 0) {
                std::cout << "instruction: Read" << std::endl;
            }
        }
        
    }
    void Util::readLines(std::string fileName) {
        for (size_t i = 0; i < 512; i++)
        {
            
        }
        
    }
    

