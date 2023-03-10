#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fp.h"

int initial(card *handcard[], card *record_handcard[]){
    int first_player;
    int counter[4] = {0}; // count for the player's cards
    srand(time(NULL));
    for(int i = 13; i >= 1; i--){
        for(int j = spade; j >= club; j--){
            card *tmp = (card*)malloc(sizeof(card));
            card *tmp2 = (card*)malloc(sizeof(card));
            tmp->color = j;
            tmp->num = i;
            tmp->pre = NULL;
            tmp2->color = j;
            tmp2->num = i;
            tmp2->pre = NULL;
            int whose = rand() % 4;
            if(counter[whose] != 13){ // the player's card is less than 13
                if(handcard[whose] != NULL){
                    tmp->next = handcard[whose];
                    handcard[whose]->pre = tmp;
                    handcard[whose] = tmp;
                    tmp2->next = record_handcard[whose];
                    record_handcard[whose]->pre = tmp2;
                    record_handcard[whose] = tmp2;
                    if(i == 3 && j == club)
                        first_player = whose;
                }
                else{
                    tmp->next = NULL;
                    handcard[whose] = tmp;
                    tmp2->next = NULL;
                    record_handcard[whose] = tmp;
                }
                counter[whose] += 1;
            } 
            else{ // the player's card is greater than 13
                for(int c = 0; c < 4; c++){
                    if(counter[c] != 13){ // find whose card is less than 13, then give him the card
                        tmp->next = handcard[c];
                        handcard[c]->pre = tmp;
                        handcard[c] = tmp;
                        tmp2->next = record_handcard[c];
                        record_handcard[c]->pre = tmp2;
                        record_handcard[c] = tmp2;
                        counter[c] += 1;
                        if(i == 3 && j == club)
                            first_player = c;
                        break;
                    }
                }

            }
        }
    }
    return(first_player);
}