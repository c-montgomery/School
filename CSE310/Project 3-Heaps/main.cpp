//boilerplate main class
#include <iostream>
#include "util.h"
#include <cstring>

using namespace std;

int main(int arg, char *argv[]){
    Util util;
    util.checkCommand(arg, argv);
    string fileName = argv[1];
    util.readLines(fileName);

    return 0;
}



//typedef struct of index key and pos
typedef struct{
    int index;
    double key;
    int pos;
}ELEMENT;

typedef struct TAG_HEAP{
    int capacity;
    int size;
    int *H;
    }HEAP;

ELEMENT **V;
HEAP *pHeap;