#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* createNode(int data)
{
    node* newn = (node*)malloc(sizeof(node));
    newn->data = data;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}

node* insert(node* root,int data)
{
    node* newn = createNode(data);
    if(root == NULL)
        root == newn;
    else
    {
        if(root->data>data)
            root->left = insert(root->left,data);
        else
            root->right = insert(root->right,data);
    }
    return newn;
}

int height(node* root)
{
    if(root == NULL)
        return 0;
    int lheight,rheight;
    lheight = height(root->left);
    rheight = height(root->right);

    return 1+max(lheight,rheight);
}

void preorder(node* root)
{
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

void inorder(node* root)
{
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

int diameter(node* root)
{
    if(root == NULL)
        return 0;

    int ldiameter = diameter(root->left);
    int rdiameter  = diameter(root->right);

    int lheight = height(root->left);
    int rheight  = height(root->right);

    return max((lheight + rheight + 1),max(ldiameter,rdiameter));
}

void balance_factor(node* root)
{
    if(root != NULL)
    {
        balance_factor(root->left);
        printf("BF of node: %d is %d",root->data,height(root->left)-height(root->right));
        balance_factor(root->right);
    }
}

void main()
{
   
    int i,n,data;
    node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Height of BST is: %d \n",height(root));
    printf("Diameter of BST is: %d \n",diameter(root));
    balance_factor(root);
}