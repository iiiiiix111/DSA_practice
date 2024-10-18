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
TreeNode* minValNode(TreeNode* node)
{
    TreeNode* current=node;
    while (current&&current->left!=NULL)
        current=current->left;
    return current;
}
TreeNode* deleteNode(TreeNode* node,int data)//free掉目标节点，并更新其余节点的指向
{
    if (node==NULL)
        return node;
    if (node->data>data)//继续寻找正确位置
        node->left= deleteNode(node->left,data);
    else if (node->data<data)//继续寻找正确位置
        node->right= deleteNode(node->right,data);
    else//找到正确位置
    {
        //---只有一个子节点或无子节点的情况
     if (node->left==NULL)//包含了左子节点为空和都为空的情况
     {
         TreeNode* temp=node->right;
         free(node);
         return temp;
     }
     else if (node->right==NULL)//左子节点为空但右子节点不为空的情况
     {
         TreeNode* temp=node->left;
         free(node);
         return temp;
     }

     //----------有两个子节点的情况
     TreeNode* temp= minValNode(node->right);
     node->data=temp->data;
        deleteNode(node->right,temp->data);
        //直接free(temp)  会造成野指针，必须更新temp的父节点指向为NULL
        //即使用deleteNode函数
    }
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
