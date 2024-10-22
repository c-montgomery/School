#ifndef UTIL_H
#define UTIL_H

class Util{
    public:

        Util();
        static void checkCommand(int arg, char *argv[]);
        static void printError(const char *msg);
        static void readLines(std::string fileName);
        std::string fileName;
        std::string line; 

};
#endif //UTIL_H