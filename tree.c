#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 15
typedef struct  TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
TreeNode* createNode(int d)
{
    TreeNode* newNode= (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data=d;
    newNode->left=newNode->right= NULL;
    return newNode;
}
void InOrderTraversal(TreeNode* t)
{
    if (t== NULL)
        return;
    InOrderTraversal(t->left);
    printf("%d ",t->data);
    InOrderTraversal(t->right);
}
TreeNode* search(TreeNode* node,int target)
{
    if (node==NULL)
        return NULL;
    else if (node->data==target)
        return node;
    else if (node->data<target)
        return search(node->right,target);
    else if (node->data>target)
        return search(node->left,target);
}
TreeNode* lowestSearch(TreeNode* node)
{
    if (node->left!=NULL)
        return lowestSearch(node->left);
    else
        return node;
}
TreeNode* insertNode(TreeNode* node,int data)
{
    if (node==NULL)//找到正确位置，即叶节点
        return createNode(data);
    if (node->data<data)
        node->right= insertNode(node->right,data);
    else
        node->left= insertNode(node->left,data);
    return node;
}
void deleteNode(TreeNode* node,int data)
{

}
char* get_data(char binaryTreeArray[],int index)//array implementation
{
    if (index>=0&&index<ARRAY_SIZE)
        return &binaryTreeArray[index];
    return NULL;
}
int right_child_index(int index)
{
    return 2*index+2;
}
int left_child_index(int index)
{
    return 2*index+1;
}
int main()
{
    TreeNode* root = createNode(13);
    TreeNode* node7 = createNode(7);
    TreeNode* node15 = createNode(15);
    TreeNode* node3 = createNode(3);
    TreeNode* node8 = createNode(8);
    TreeNode* node14 = createNode(14);
    TreeNode* node19 = createNode(19);
    TreeNode* node18 = createNode(18);

    root->left = node7;
    root->right = node15;

    node7->left = node3;
    node7->right = node8;

    node15->left = node14;
    node15->right = node19;

    node19->left = node18;

    insertNode(root,10);
    InOrderTraversal(root);
    free(root);
    free(node15);
    free(node7);
    free(node14);
    free(node19);
    free(node18);
    free(node3);
    free(node8);
    return 0;
}
