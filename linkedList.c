// ********** New updated linked list without typedef. (with english variable and function names) *************

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
    
struct node *createNode(int firstElement){
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root -> data = firstElement;
    root -> next = NULL;
    return root;
}
void printFunc(struct node *nodeStart){
    int i = 1;
    while(nodeStart != NULL){
        printf("%d. element: %d\n",i,nodeStart -> data);
        nodeStart = nodeStart -> next;
        i++;
    }
}

/*void addToEnd(int newElement, struct node *nodeStart){ // Different types of addToEnd.
    while(nodeStart -> next != NULL){
        nodeStart = nodeStart -> next;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = newElement;
    newNode -> next = NULL;
    nodeStart -> next = newNode;
  */
/*void addToEnd2(int newElement, struct node *nodeStart){
     while(nodeStart -> next != NULL){
         nodeStart = nodeStart -> next;
     }
     struct node *newNode;
     newNode = createNode(newElement);
     nodeStart -> next = newNode;
}
*/
void addToEnd3(int newElement, struct node **nodeStart){
     struct node *newNode;
     newNode = createNode(newElement);
     if(*nodeStart == NULL){
         newNode -> next = *nodeStart;
         *nodeStart = newNode;
     }
     else{
         struct node *new2 = *nodeStart;
         
     while(new2 -> next != NULL){
         new2 = new2 -> next;
         }
        new2 -> next = newNode;
    }
}        
void addtoTop(int newElement, struct node **nodeStart){
    struct node *newNode;
    newNode = createNode(newElement);
    newNode -> next = *nodeStart;
    *nodeStart = newNode;
}

/*void addtoTop2(int newElement,struct node **nodeStart){ // createNode fonk. kullanmadan. without createNode func.
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = newElement;
    newNode -> next = *nodeStart;
    *nodeStart = newNode;
}
*/

void sequentialInsert(int newElement, struct node **nodeStart){
    struct node *element, *temp, *iter;
    iter = *nodeStart;
    while(iter -> next != NULL && iter -> data <= newElement){
        temp = iter;
        iter = iter -> next;
    }
    element = createNode(newElement);
    if(iter == *nodeStart){
        element -> next = *nodeStart;
        *nodeStart = element; 
    }
    else{
        temp -> next = element;
        element -> next = iter; 
    }
}

void orderList(struct node **nodeStart){
    struct node *a, *b, *c, *d;
    if(*nodeStart == NULL || (*nodeStart) -> next == NULL){
        return; //listede bir veya daha az eleman varsa
    }
    d = (*nodeStart) -> next;
    (*nodeStart) -> next =  NULL;
     while(d != NULL) {
                c = d;
                d = d->next;
                b = *nodeStart;
                while(b != NULL && b -> data < c -> data) {
                        a = b;
                        b = b -> next;
                }
                if(b == *nodeStart) {
                        c -> next = *nodeStart;
                        *nodeStart = c;
                }
                else {
                        a->next = c;
                        c->next = b;
                }
        }
}

int findMinimum(struct node **nodeStart){  // Finds the min. value of list
    struct node *temp = *nodeStart;
    int min = temp -> data;
    temp = temp -> next;
    
    while(temp -> next != NULL){
        if(temp -> data <= min){
            min = temp -> data;
        }
        temp = temp -> next;
    }
    return min;
}

void deleteSecond(struct node **nodeStart){  // Deletes the second element of list.
    struct node *temp = (*nodeStart) -> next;
    (*nodeStart) -> next = temp -> next;
    free(temp);
}

int main()
{   
    struct node *root;
    //root = createNode(5);
    
    addToEnd3(21,&root);
    addToEnd3(41,&root);
    addToEnd3(24,&root);
    addToEnd3(31,&root);
    addtoTop(10,&root);
    addtoTop2(15,&root);
    sequentialInsert(22,&root);
    orderList(&root);
    
    
    
    
    printFunc(root);
    
    
}
