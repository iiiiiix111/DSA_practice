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
int hashIndex(const char* value)
{
    return (*value)%HASH_SET_SIZE;
}
void hashAdd(const  char* value,Node** HashSet)
{
    int i= hashIndex(value);
    Node* current=HashSet[i];
    Node* p= (Node*) malloc(sizeof(Node));
    p->value=(char*) malloc(sizeof(char));
    strcpy(p->value,value);
    p->next=NULL;
    if (HashSet[i]==NULL)
    {
        HashSet[i]=p;
    }
    else
    {
        while (current->next!=NULL)
            current=current->next;
        current->next=p;
    }

}
bool hashFind(const char* value,Node** HashSet) {
    int i = hashIndex(value);
    Node *p = HashSet[i];
    while (p != NULL) {
        if (*p->value == *value)
            return true;
        p = p->next;
    }
    return false;
}
void freeHashSet(Node** HashSet)
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
    Node* HashSet [10];
    memset(HashSet,0,sizeof(HashSet));
    char s[]={'a','i','e','o','u'};
    size_t size=sizeof(s)/sizeof(char);
    for (int i=0;i<size;i++)
    {
        hashAdd(&s[i],HashSet);
    }
    int amount=0;
    int flag=0;
    for (int i=left;i<=right;i++)
    {
            if (hashFind(&words[i][0],HashSet))
                flag++;
            if (hashFind(&words[i][strlen(words[i])-1],HashSet))
                flag++;
            if (flag==2)
                amount++;
            flag=0;
    }
    freeHashSet(HashSet);
    return amount;
}
void show(char** HashSet)
{

    for (int i=0;i<HASH_SET_SIZE;i++)
    {
        Node* current=HashSet[i];
        while (current!=NULL)
        {
            printf("%c ",*(current->value));
            current=current->next;
        }
    }

}
int main()
{
    char* words[] = {"hey","aeo","mu","ooo","artro"};
    /*char word[]={'a','b','c'};
    printf("%llu",sizeof(words)/sizeof(words[0]));*/
    int left = 0,right = sizeof(words)/sizeof(words[0])-1;
    //vowelStrings(words,0,left,right);
    //show();
    printf("%d", vowelStrings(words,0,left,right));
}

