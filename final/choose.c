#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fp.h"
#include <string.h>

int choose( int cardmuch,int start, card **handcard, card_point **recordpoint, record_turn **recordturn, int turn){
    int Standard;
    int cardnumber;
    card *tmp = *handcard;//copy handcard
    card *tmp2 = NULL;//要出的牌
    int arr[cardmuch];
    
    for(int i = 0; i < cardmuch; i++){
        printf("您總共要出%d張牌，請選擇想出的牌(代號): ",cardmuch);
        scanf("%d",&cardnumber);
        printf("\n");
        arr[i]= cardnumber;
    }
    for(int j = 0; j < cardmuch; j++){
        tmp = *handcard;
        for(int k = 1; k < arr[j]; k++){
            tmp = tmp->next;          
        }
        if(tmp->pre == NULL && tmp->next == NULL){
            *handcard = NULL;
        }
        else if(tmp->pre == NULL){
            tmp->next->pre = NULL;
            *handcard = tmp->next;
        }
        else if(tmp->next == NULL){
            tmp->pre->next = NULL;
        }
        else{
            tmp->pre->next = tmp->next;
            tmp->next->pre = tmp->pre;
        }
        if(tmp2 == NULL){
            tmp2 = tmp;
            tmp2->pre = NULL;
            tmp2->next = NULL;
        }
        else{
            tmp2->pre = tmp;
            tmp->next = tmp2;
            tmp2 = tmp;
        }
        for(int l = j + 1; l < cardmuch; l++){
            if(arr[l] > arr[j]) 
                arr[l] = arr[l] - 1;
        }    
    }
    tmp2 = radix_sort(tmp2);
    Standard = play_or_not(cardmuch, start, tmp2, recordpoint);
    if(Standard == true){
        printcard(0, tmp2);
        record_func(recordturn, turn, start, cardmuch, tmp2);
    }
    else{
        tmp = *handcard;
        while(tmp!=NULL){
            if(tmp->next == NULL)
                break;
            else{tmp = tmp->next;}    
        }  
        tmp->next = tmp2;
        tmp2->pre=tmp;
        *handcard = radix_sort(*handcard);
    }
    return(Standard);  
}