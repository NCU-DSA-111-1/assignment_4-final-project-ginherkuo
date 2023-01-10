#include <stdio.h>
#include "fp.h"

void printcard(int who, card *handcard){
    card *tmp = handcard;
    if(who != 0)
        printf("Player %d's card: \n", who);
    int counter = 1;
    while(tmp != NULL){
        printf("(%d) ", counter);
        switch(tmp->color){
            case spade:
                printf("Spade ");
                break;
            case heart:
                printf("Heart ");
                break;
            case diamand:
                printf("Diamand ");
                break;
            case club:
                printf("Club ");
                break;
        }
        printf("%d ", tmp->num);
        tmp = tmp->next;
        counter += 1;
    }
    printf("\n");
}