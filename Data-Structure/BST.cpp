/*
Binary Search Tree -
1. Every parent has at most 2 childs.
2. Parent's left child value is lower than parent's value.
3. Parent's right child value is greater than parent's value.
4. No value is more than one time in Binary Tree
5. Each level has at most 2^level nodes . (level = 0,1,2...)
6. C++ library Set is an example of Binary tree
*/
#include <stdio.h>
using namespace std;
struct node
{
    node * left , *right ;
    int number;
    bool endmark;
    node()
    {
        left = NULL ; right = NULL;
        endmark=false;
    }
};
void Insert(int number,node *root)
{
    if(root->endmark==false)
    {
        root->number=number;
        root->endmark=true;
        return;
    }
    if(root->number>number)
    {
        if(root->left==NULL) root->left=new node();
        Insert(number,root->left);
    }
    if(root->number<number)
    {
        if(root->right==NULL) root->right=new node();
        Insert(number,root->right);
    }
}
void preorder_traversal(node *root)
{
    printf("%d\n",root->number);
    if(root->left!=NULL) preorder_traversal(root->left);
    if(root->right!=NULL) preorder_traversal(root->right);
}
void inorder_traversal(node *root)
{
    if(root->left!=NULL) inorder_traversal(root->left);
    printf("%d\n",root->number);
    if(root->right!=NULL) inorder_traversal(root->right);
}
void postorder_traversal(node *root)
{
    if(root->left!=NULL) postorder_traversal(root->left);
    if(root->right!=NULL) postorder_traversal(root->right);
    printf("%d\n",root->number);
}
void Delete(node *root)
{
    if(root->left!=NULL) Delete(root->left);
    if(root->right!=NULL) Delete(root->right);
    delete(root);
}
int main()
{
    int N;
    scanf("%d",&N); // How many numbers
    node *head = new node();
    //Insert numbers
    while(N--)
    {
        int number;
        scanf("%d",&number);
        Insert(number,head);
    }
    printf("Preorder Traversal : \n");
    preorder_traversal(head);
    printf("Inorder Traversal : \n");
    inorder_traversal(head); // Ascending sorted way to show inserted numbers
    printf("Postorder Traversal : \n");
    postorder_traversal(head);

    Delete(head); // Delete the tree for avoiding Memory Limit problem

    return 0;
}
