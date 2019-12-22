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
        printf("%d. eleman: %d\n",i,nodeStart -> data);
        nodeStart = nodeStart -> next;
        i++;
    }
}

/*void addToEnd(int newElement, struct node *nodeStart){
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
void siraliEkle(int newElement, struct node **nodeStart){
    struct node *eklenen, *tutucu,*gezici;
    gezici = *nodeStart;
    while(gezici -> next != NULL && gezici -> data <= newElement){
        tutucu = gezici;
        gezici = gezici -> next;
    }
    eklenen = createNode(newElement);
    if(gezici == *nodeStart){
        eklenen -> next = *nodeStart;
        *nodeStart = eklenen; 
    }
    else{
        tutucu -> next = eklenen;
        eklenen -> next = gezici; 
    }
}
/*void addtoTop2(int newElement,struct node **nodeStart){ // createNode fonk. kullanmadan. without createNode func.
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = newElement;
    newNode -> next = *nodeStart;
    *nodeStart = newNode;
}
*/
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
/*
void siralilisteyeEkle(struct node **listebasi, int icerik){ // Hocanın istediği gibi. 2017 vize sorusu.
    struct node *eklenen, *gezici, *tutucu;
    gezici = *listebasi;
    while(gezici -> next != NULL && gezici -> data <= icerik){
        tutucu = gezici;
        gezici = gezici -> next;
    }
    eklenen = (struct node*)malloc(sizeof(struct node));
    eklenen -> data = icerik;
    eklenen -> next = NULL;
    if(gezici == *listebasi){
        eklenen -> next = *listebasi;
        *listebasi = eklenen;
    }
    else{
        eklenen -> next = gezici;
        tutucu -> next = eklenen;
    }
}
*/
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
    siraliEkle(22,&root);
    orderList(&root);
    
    
    
    
    printFunc(root);
    
    
}
