#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node* add(struct node *tree, int key){
    if(tree == NULL){
        struct node* root = (struct node*)malloc(sizeof(struct node));
        root -> left = NULL;
        root -> right = NULL;
        root -> data = key;
        return root;
    }
    
    if(key > tree -> data){
        tree -> right = add(tree -> right, key);
        return tree;
    }
    tree -> left = add(tree -> left, key);
    return tree;
}

void print_inorder(struct node *tree){
    if(tree == NULL)
        return;
    print_inorder(tree -> left);
    printf("%4d", tree -> data);
    print_inorder(tree -> right);
}

int isThere(struct node *tree, int key){ //if the key does exist in the list returns 1. if does not returns -1. RECURSIVE
    if(tree == NULL)
        return -1;
    if(tree -> data == key)
        return 1;
    if(isThere(tree -> left,key) == 1)
        return 1;
    if(isThere(tree -> right,key) == 1)
        return 1;
    return -1;
}

int isThereNotRecursive(struct node *tree, int key){  // if the key does exist in the list returns 1. if does not returns -1. NOT recursive.
    
    while(tree -> data != key && tree != NULL){
    if(key > tree -> data)
        tree = tree -> right;
    tree = tree -> left;
    }
    if(tree == NULL)
        return -1;
    return 1;
    
}

int funcMax(struct node *tree){   //the function that returns maximum key of the list. NOT recursive.
   while(tree -> right != NULL){
       tree = tree -> right;
   } 
   return tree -> data;
}

int funcMin(struct node *tree){  // the function that returns minimum key of the list. RECURSIVE
    if(tree -> left == NULL)
        return tree -> data;
    funcMin(tree -> left);
}

int isLeaf(struct node* tree, int key){ //the function that returns 1 if the key is leaf node.
    if(tree == NULL)
        return -1;
    if(tree -> data == key){
        if(tree->right==NULL && tree->left==NULL){
            return 1;
        }
        else{
            return -1;
        }
    }
    if(isLeaf(tree -> left,key) == 1)
        return 1;
    if(isLeaf(tree -> right,key) == 1)
        return 1;
    return -1;
}

int isLeafNotRecursive(struct node *tree, int key){  // the function that returns 1 if the key is leaf node. NOT recursive.
    
    while(tree -> left == NULL && tree -> right == NULL){
    if(tree == NULL)
        return -1;
    if(key > tree -> data)
        tree = tree -> right;
    tree = tree -> left;
    }
    return 1;
}


int main()
{
    struct node* tree;
    
    tree = add(tree, 14);
    tree = add(tree, 24);
    tree = add(tree, 4);
    tree = add(tree, 44);
    tree = add(tree, 2);
    tree = add(tree, 54);
    print_inorder(tree);
    
    int check = isThere(tree,15);
    printf("\nIs there: %d",check);

    int max = funcMax(tree);
    printf("\nMax value: %d",max);

    int leaf = isLeaf(tree, 4);
    printf("\nIs leaf: %d", leaf);
    
    int min = funcMin(tree);
    printf("\nMin value: %d",min);

    return 0;
}


