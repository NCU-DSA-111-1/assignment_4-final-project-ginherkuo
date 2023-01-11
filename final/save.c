#include <stdio.h>
#include <stdlib.h>
#include "fp.h"

void record_func(record_turn **recordturn, int turn, int start, int n, card *played){
    record_turn *tmp = (record_turn*)malloc(sizeof(record_turn));

    tmp->turn = turn;
    tmp->start = start;
    tmp->n = n;
    if(n == 0)
        tmp->played_card = NULL;
    else
        tmp->played_card = played;
    tmp->pre = NULL;
    if(*recordturn == NULL){
        tmp->next = NULL;
        *recordturn = tmp;
    }
    else{
        tmp->next = *recordturn;
        (*recordturn)->pre = tmp;
        *recordturn = tmp;
    }
}

void save_to_file(card *record_handcard[], record_turn *recordturn){
    int done = false;
    card *tmp_handcard;
    card *tmp_played_card;
    record_turn *tmp_turn = recordturn;
    FILE *fptr;
    
    fptr = fopen("big_two.txt", "w");

    for(int i = 0; i < 4; i++){
        tmp_handcard = record_handcard[i];
        while(tmp_handcard != NULL){
            fprintf(fptr,"%d %d ", tmp_handcard->color, tmp_handcard->num);
            tmp_handcard = tmp_handcard->next;
        }
        fprintf(fptr,"\n");
    }//fprint initial handcard of all players

    while(tmp_turn->next != NULL)
        tmp_turn = tmp_turn->next;
    //find the first turn

    while(tmp_turn != NULL){
        fprintf(fptr,"%d %d %d ", tmp_turn->turn, tmp_turn->start, tmp_turn->n);
        if(tmp_turn->played_card != NULL){
            tmp_handcard = tmp_turn->played_card;
            while(tmp_handcard != NULL){
                fprintf(fptr,"%d %d ", tmp_handcard->color, tmp_handcard->num);
                tmp_handcard = tmp_handcard->next;
            }
        }
        fprintf(fptr,"\n");
        tmp_turn = tmp_turn->pre;
        printf("a\n");
    }

    fclose(fptr);
    printf("The process has already save in the file named big_two.txt.\n");
}