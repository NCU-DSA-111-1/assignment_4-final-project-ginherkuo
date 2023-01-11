#include <stdio.h>
#include <stdlib.h>
#include "fp.h"

int play_or_not(int n, int start, card *be_judged, card_point **record_point){
    if(start == false && n != (*record_point)->card_type){
        if(n != 5)
            return(false);
    } // not a new turn, test whether the card number is equal to the previous or five(may be four_of_a_kind or straight_flush)
    card_point *tmp = (card_point*)malloc(sizeof(card_point));
    switch (n){
    case 1:{// one card type
        if((*record_point) == NULL){
            if(be_judged->color != club || be_judged->num != 3){
                free(tmp);
                return(false);
            }
        }
        if(be_judged->num == 1 || be_judged->num ==2)
            tmp->point = be_judged->num * 10 + be_judged->color + 130;
        else
            tmp->point = be_judged->num * 10 + be_judged->color; // calculate the point
        if((*record_point) == NULL){
            tmp->card_type = one_card;
            tmp->next = NULL;
            (*record_point) = tmp;
            printf("%d - one_card : ", be_judged->num);
            return(true);
        }
        else if(tmp->point > (*record_point)->point || start == true){ // point is bigger than the previous or is a new turn
            tmp->card_type = one_card;
            tmp->next = (*record_point);
            (*record_point) = tmp;
            printf("%d - one_card : ", be_judged->num);
            return(true);
        }
        else{
            free(tmp);
            return(false);
        }
        break;
    }
    case 2:{ // pair type
        if((*record_point) == NULL){
            int have_c3 = false;
            card *test_c3;
            test_c3 = be_judged;
            while(test_c3 != NULL){
                if(test_c3->color == club && test_c3->num == 3){
                    have_c3 = true;
                    break;
                }
                test_c3 = test_c3->next;
            }
            if(have_c3 == false){
                free(tmp);
                return(false);
            }
        }
        if(be_judged->num != be_judged->next->num){
            free(tmp);
            return(false); // not a pair
        }
        else{
            if(be_judged->num == 1 || be_judged->num == 2)
                tmp->point = be_judged->next->num * 10 + be_judged->next->color + 130;
            else
                tmp->point = be_judged->next->num * 10 + be_judged->next->color; // calculate the point with the big one
            if((*record_point) == NULL){
                tmp->card_type = pair;
                tmp->next = NULL;
                (*record_point) = tmp;
                printf("%d - pair : ", be_judged->num);
                return(true);
            }
            else if(tmp->point > (*record_point)->point || start == true){ // point is bigger than the previous or is a new turn
                tmp->card_type = pair;
                tmp->next = (*record_point);
                (*record_point) = tmp;
                printf("%d - pair : ", be_judged->num);
                return(true);
            }
            else{
                free(tmp);
                return(false);
            }
        }
        break;
    }
    case 5:{ // straight, four_of_a_kind and straight_flush type
        if((*record_point) == NULL){
            int have_c3 = false;
            card *test_c3;
            test_c3 = be_judged;
            while(test_c3 != NULL){
                if(test_c3->color == club && test_c3->num == 3){
                    have_c3 = true;
                    break;
                }
                test_c3 = test_c3->next;
            }
            if(have_c3 == false){
                free(tmp);
                return(false);
            }
        }
        card *tmp_of_card_1;
        card *tmp_of_card_2;
        tmp_of_card_1 = be_judged;
        tmp_of_card_2 = be_judged->next;
        int same_color = 0;
        int same_num[2] = {0};
        int continue_num = 0;
        for(int i = 0; i < n - 1; i++){
            if(tmp_of_card_1->color == tmp_of_card_2->color)
                same_color += 1;
            if(tmp_of_card_1->num == tmp_of_card_2->num){
                if(tmp_of_card_2->num == be_judged->num)
                    same_num[0] += 1;
                else
                    same_num[1] += 1;
            }
            if( (tmp_of_card_1->num + 1 == tmp_of_card_2->num) || \
                (tmp_of_card_1->num == 1 && tmp_of_card_2->num == 10)){
                continue_num += 1;
            }
            tmp_of_card_1 = tmp_of_card_2;
            tmp_of_card_2 = tmp_of_card_2->next;
        }
        if(continue_num == 4 && same_color != 4){ //straight
            if(be_judged->num == 2 || (be_judged->num == 1 && be_judged->next->num == 10)) // 23456 or A10JQK
                tmp->point = be_judged->num * 10 + be_judged->color + 130;
            else
                tmp->point = tmp_of_card_1->num * 10 + tmp_of_card_1->color;
            if((*record_point) == NULL){
                tmp->card_type = straight;
                tmp->next = NULL;
                (*record_point) = tmp;
                printf("[%d, %d] - straight : ", be_judged->num, tmp_of_card_1->num);
                return(true);
            }
            else if( ((*record_point)->card_type == straight && tmp->point > (*record_point)->point) || start == true){
                tmp->card_type = straight;
                tmp->next = (*record_point);
                (*record_point) = tmp;
                printf("[%d, %d] - straight : ", be_judged->num, tmp_of_card_1->num);
                return(true);
            }
            else{
                free(tmp);
                return(false);
            }
        }
        else if((same_num[0] == 1 && same_num[1] == 2) || (same_num[0] == 2 && same_num[1] == 1)){ //full_house
            int the_same;
            if(same_num[0] == 2)
                the_same = be_judged->num;
            else if(same_num[1] == 2)
                the_same = tmp_of_card_1->num;
            if(the_same == 1 || the_same == 2)
                tmp->point = the_same * 10 + 130;
            else
                tmp->point = the_same * 10;
            if((*record_point) == NULL){
                tmp->card_type = full_house;
                tmp->next = NULL;
                (*record_point) = tmp;
                printf("%d - full_house : ", the_same);
                return(true);
            }
            else if( ((*record_point)->card_type == full_house && tmp->point > (*record_point)->point) || start == true){
                tmp->card_type = full_house;
                tmp->next = (*record_point);
                (*record_point) = tmp;
                printf("%d - full_house : ", the_same);
                return(true);
            }
            else{
                free(tmp);
                return(false);
            }
        }
        else if(same_num[0] == 3 || same_num[1] == 3){ //four_of_a_kind
            int the_same;
            if(same_num[0] == 3)
                the_same = be_judged->num;
            else if(same_num[1] == 3)
                the_same = tmp_of_card_1->num;
            if(the_same == 1 || the_same == 2)
                tmp->point = the_same * 10 + 130;
            else
                tmp->point = the_same * 10;
            if((*record_point) == NULL){
                tmp->card_type = four_of_a_kind;
                tmp->next = NULL;
                (*record_point) = tmp;
                printf("%d - four_of_a_kind : ", the_same);
                return(true);
            }
            if( ((*record_point)->card_type == four_of_a_kind && tmp->point > (*record_point)->point) || \
                (*record_point)->card_type < four_of_a_kind || start == true){
                tmp->card_type = four_of_a_kind;
                tmp->next = (*record_point);
                (*record_point) = tmp;
                printf("%d - four_of_a_kind : ", the_same);
                return(true);
            }
            else{
                free(tmp);
                return(false);
            }
        }
        else if(continue_num == 4 && same_color == 4){ //straight_flush
            if(be_judged->num == 2 || (be_judged->num == 1 && be_judged->next->num == 10)) // 23456 or A10JQK
                tmp->point = be_judged->num * 10 + be_judged->color + 130;
            else
                tmp->point = tmp_of_card_1->num * 10 + tmp_of_card_1->color;
            if((*record_point) == NULL){
                tmp->card_type = straight_flush;
                tmp->next = NULL;
                (*record_point) = tmp;
                if(be_judged->num == 1 && be_judged->next->num == 10)
                    printf("[%d, %d] - ", be_judged->next->num, be_judged->num);
                else
                    printf("[%d, %d] - ", be_judged->num, tmp_of_card_1->num);
                switch(be_judged->color){
                case spade:
                    printf("Spade straight_flush : ");
                    break;
                case heart:
                    printf("Heart straight_flush : ");
                    break;
                case diamand:
                    printf("Diamand straight_flush : ");
                    break;
                case club:
                    printf("Club straight_flush : ");
                    break;
                }
                return(true);
            }
            else if( ((*record_point)->card_type == straight_flush && tmp->point > (*record_point)->point) || \
                (*record_point)->card_type < straight_flush || start == true){
                tmp->card_type = straight_flush;
                tmp->next = (*record_point);
                (*record_point) = tmp;
                if(be_judged->num == 1 && be_judged->next->num == 10)
                    printf("[%d, %d] - ", be_judged->next->num, be_judged->num);
                else
                    printf("[%d, %d] - ", be_judged->num, tmp_of_card_1->num);
                switch(be_judged->color){
                case spade:
                    printf("Spade straight_flush : ");
                    break;
                case heart:
                    printf("Heart straight_flush : ");
                    break;
                case diamand:
                    printf("Diamand straight_flush : ");
                    break;
                case club:
                    printf("Club straight_flush : ");
                    break;
                }
                return(true);
            }
            else{
                free(tmp);
                return(false);
            }
        }
        else{
            free(tmp);
            return(false);
        }
        break;
    }
    default:
        return(false);
    }
}