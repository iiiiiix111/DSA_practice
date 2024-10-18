#include<stdio.h>
#include <stdlib.h>
typedef struct AVLTreeNode
{
    char data;
    struct AVLTreeNode* left,*right;
    int height;
} AVLTreeNode;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int getHeight(AVLTreeNode* node)
{
    if (!node)
        return 0;
    return node->height;
}
AVLTreeNode* createNode(char data)
{
    AVLTreeNode* node= (AVLTreeNode*) malloc(sizeof(AVLTreeNode));
    node->data=data;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}
AVLTreeNode* rightRotate(AVLTreeNode* y)
{


}
