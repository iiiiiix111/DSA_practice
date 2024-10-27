#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#define HASH_SET_SIZE 10
typedef struct Node
{
    char* value;
    struct Node* next;
}Node;

Node* HashSet [HASH_SET_SIZE] ={NULL};

int hashIndex(const char* value)
{
    return (*value)%HASH_SET_SIZE;
}
void hashAdd(const  char* value)
{
    int i= hashIndex(value);
    Node* current=HashSet[i];
    Node* p= (Node*) malloc(sizeof(Node));
    p->value=(char*) malloc(sizeof(char));
    strcpy(p->value,value);
    if (current==NULL)
    {
        current=p;
        p->next=NULL;
    }
    else
    {
        while (current->next!=NULL)
            current=current->next;
        current->next=p;
        p->next=NULL;
    }

}
bool hashFind(const char* value) {
    int i = hashIndex(value);
    Node *p = HashSet[i];
    while (p != NULL) {
        if (p->value == value)
            return true;
        p = p->next;
    }
    return false;
}
void freeHashSet()
{
    for (int i=0;i<HASH_SET_SIZE;i++)
    {
        Node* current= HashSet[i];
        while (current!=NULL)
        {
            Node* temp =current;
            current=current->next;
            free(temp->value);
            free(temp);
        }
    }
}
int vowelStrings(char** words, int wordsSize, int left, int right) {
    char s[]={'a','i','e','o','u'};
    size_t size=sizeof(s)/sizeof(char);
    for (int i=0;i<size;i++)
    {
        hashAdd(&s[i]);
    }
    int amount=0;
    int flag=0;
    for (int i=left;i<=right;i++)
    {
            if (hashFind(&words[i][0]))
                flag++;
            if (hashFind(&words[i][strlen(words[i])-1]))
                flag++;
            if (flag==2)
                amount++;
            flag=0;
    }
    return amount;
}
int main()
{
    char* words[] = {"are","amy","u"};
     int left = 0, right = 2;
     printf("%d", vowelStrings(words,0,left,right));
     freeHashSet();
}

