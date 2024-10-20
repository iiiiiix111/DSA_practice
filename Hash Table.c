#include <stdlib.h>
#define HASH_SET_SIZE 10
typedef struct
{
    char* value;
    struct Node* next;
}Node;

char* HashSet [HASH_SET_SIZE] ={NULL};

int hashIndex(const char* value)
{

}