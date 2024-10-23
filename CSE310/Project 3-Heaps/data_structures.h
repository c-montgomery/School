#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
typedef struct TAG_ELEMENT {
    int index;
    int key;
    int pos;
}ELEMENT;

typedef struct TAG_HEAP {
    int *H;
    int capacity;
    int size;
}HEAP;

#endif