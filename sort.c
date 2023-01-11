#include <stdio.h>
#include "fp.h"

card *radix_sort(card *be_sorted){
    card *card_color[4] = {NULL};
    card *card_num[13] = {NULL};
    card *sorted = {NULL};

    while(be_sorted != NULL){
        card *tmp = be_sorted;
        be_sorted = be_sorted->next;
        if(card_color[tmp->color - 1] == NULL){
            tmp->next = NULL;
            tmp->pre = NULL;
            card_color[tmp->color - 1] = tmp;
        }
        else{
            tmp->next = card_color[tmp->color - 1];
            tmp->pre = NULL;
            card_color[tmp->color - 1] = tmp;
        }
    } // first sort with card color

    for(int i = 0; i < 4; i++){
        while(card_color[i] != NULL){
            card *tmp = card_color[i];
            card_color[i] = card_color[i]->next;
            if(card_num[tmp->num - 1] == NULL){
                tmp->next = NULL;
                tmp->pre = NULL;
                card_num[tmp->num - 1] = tmp;
            }
            else{
                tmp->next = card_num[tmp->num - 1];
                tmp->pre = NULL;
                card_num[tmp->num - 1] = tmp;
            }
        }
    } // second sort with card number

    for(int i = 12; i >= 0; i--){
        while(card_num[i] != NULL){
            card *tmp = card_num[i];
            card_num[i] = card_num[i]->next;
            if(sorted == NULL){
                tmp->next = NULL;
                tmp->pre = NULL;
                sorted = tmp;
            }
            else{
                tmp->next = sorted;
                tmp->pre = NULL;
                sorted->pre = tmp;
                sorted = tmp;
            }
        }
    } // take out and link

    return(sorted);
}