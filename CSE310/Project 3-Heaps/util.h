#ifndef UTIL_H
#define UTIL_H

#include <string>



class Util{
    public:
        Util(){
        
        };
        
        std::string inputFile;
        std::string outputFile;
        static void checkCommand(int arg, char *argv[]);
        static void printError(const char *msg);
       
        
        void processInstructions();

    
};


#endif //UTIL_H