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
        *recordturn = tmp;
    }
}