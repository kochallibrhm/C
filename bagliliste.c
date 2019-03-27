#include <stdio.h>    
#include <string.h>  
#include <stdlib.h>
#include <locale.h>

/*The program that makes linked list it have some functions thats adds an element to the end of the list and creates new lists and the element that adds an element to the middle of the list and deletes the element. */

struct n{
        int data;
        struct n  *next;
};
typedef struct n* node;

void elemaneklesona(node root,int i);
void bastir(node root);
node yeniListe(int ilkeleman);
node siralielemanEkle(node root,int yeniEleman);
node ekleortaya(node root, int yeniEleman);
void elemanSil(node root, int data);

    int main() {
        setlocale(LC_ALL, "Turkish");
       /* node root;
        root = (node)malloc(sizeof(node));
        root -> data = 20;
        root -> next = NULL; */

        node root = yeniListe(20);
        elemaneklesona(root,30);
        bastir(root);

        elemaneklesona(root,40);
        bastir(root);

        root = siralielemanEkle(root,25);
        bastir(root);

        root = ekleortaya(root, 34);
        bastir(root);

        elemanSil(root,24);
        bastir(root);


        return 0;
}
void elemaneklesona(node root,int i){
        while(root -> next != NULL){
            root = root -> next;
    }
        root -> next =(node)malloc(sizeof(node));
        root = root -> next;
        root -> data = i;
        root -> next = NULL;

}
void bastir(node root){
        int i=1;
        while (root != NULL){
            printf("%d. eleman: %d\n",i,root -> data);
            root = root -> next;
            i++;
        }
        printf("\n");
}
node yeniListe(int ilkeleman){
        node root = (node)malloc(sizeof(node));
        root -> next = NULL;
        root -> data = ilkeleman;

    return root;
}
node siralielemanEkle(node root,int yeniEleman){
        if (root == NULL){ //boş olma ihtimalini kontrol ediyor.
            root = (node)malloc(sizeof(node));
            root -> data = yeniEleman;
            root -> next = NULL;
            return root;
        }
        if(root -> data > yeniEleman){ //ilk elemandan küçük durumu root değişiyor.
            node temp = (node)malloc(sizeof(node));
            temp -> data = yeniEleman;
            temp -> next = root;
            return temp;
        }
        node iter = root; //ortaya bir yere ya da sona eleman ekleme durumu.
        while (iter->next != NULL && iter->next->data < yeniEleman ){
            iter = iter->next;
        }
        node temp = (node)malloc(sizeof(node));
        temp->next = iter->next;
        iter->next = temp;
        temp->data = yeniEleman;
    return root;
}
node ekleortaya(node root, int yeniEleman){
        node iter = root; //ortaya bir yere ya da sona eleman ekleme durumu.
        while (iter->next != NULL && iter->next->data < yeniEleman ){
            iter = iter->next;
    }
        node temp = (node)malloc(sizeof(node));
        temp->next = iter->next;
        iter->next = temp;
        temp->data = yeniEleman;
        return root;
}

void elemanSil(node root, int data){
        node iter = root;
        node temp;
        if(root -> data == data){
            temp = root;
            root = root ->next;
            free(temp);
    }
        while (iter ->next != NULL && iter->next->data != data ){
            iter = iter->next;
        }
        if(iter->next == NULL){
            printf("Eleman bulunamadi...\n");
        }
        temp = iter->next;
        iter->next = iter->next->next;
        free(temp);

}



