#include <stdio.h>      //The program that makes deck and shuffles it.
#include <time.h>
#include <stdlib.h>
typedef struct {
    char *suits;
    char *faces;
}CARD;
void makedeck(CARD *deck, char *cc[], char *nn[]);
void shuffle(CARD *deck);

int main() {
    srand(time(NULL));
    CARD deck[52];

    char *c[] = {"Diamond", "Heart", "Spades", "Club"};
    char *n[] = {"Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    makedeck(deck, c, n);
    for (int i = 0; i < 52; ++i) {
        printf("%s%s \n", deck[i]);
    }
    printf("-------------shuffled-------------\n");
    shuffle(deck);
    for (int i = 0; i < 52; ++i) {
        printf("%s%s \n", deck[i]);
    }
}
void makedeck(CARD *deck, char *cc[], char *nn[]){
    int s=0;
    for (int i = 0; i <4 ; ++i) {
        for (int j = 0; j <13 ; ++j) {
            deck[s].suits=cc[i];
            deck[s].faces=nn[j];
            s++;
        }
    }

}
void shuffle(CARD *deck){
    int line;
    int i=0;
    CARD temp;
    for (int j = 0; j <52 ; ++j) {
        line=rand()%52;
        temp=deck[line];
        deck[line]=deck[i];
        deck[i]=temp;
    }

}
