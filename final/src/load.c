#include <stdio.h>
#include <stdlib.h>
#include "fp.h"


int load(card *handcard[],record_turn **recordturn){
    int back = 0;
    FILE *fp_r = fopen("big_two.txt", "r");
            /*if (fp_w == NULL)
            return -1;*/
        for(int i = 0; i < 4; i++){
                    
                    for(int j = 0; j < 13; j++){
                        card *tmp = (card*)malloc(sizeof(card));
                    tmp->color = 0;
                    tmp->num = 0;
                    tmp->pre = NULL;
                        fscanf(fp_r, "%d %d ", &tmp->color,&tmp->num);
                        if(handcard[i] != NULL){
                            tmp->next = handcard[i];
                            handcard[i]->pre = tmp;
                            handcard[i] = tmp;
                        }
                        else{
                            tmp->next = NULL;
                            handcard[i] = tmp;
                        }
                        
                    }
                    handcard[i] = radix_sort(handcard[i]);
                    fscanf(fp_r,"\n");
        }
           
        while(!feof(fp_r)) {
            record_turn *tmp3 = (record_turn*)malloc(sizeof(record_turn));      
            tmp3->played_card = NULL;
            
            
            fscanf(fp_r, "%d %d %d ", &tmp3->turn,&tmp3->start,&tmp3->n);
           
            if(tmp3->n == 0)
                tmp3->played_card = NULL;
            else{
                for(int i=0 ; i<tmp3->n ; i++){
                    card *tmp2 = (card*)malloc(sizeof(card));
            tmp2->color = 0;
                    tmp2->num = 0;
                    tmp2->pre = NULL;
                    fscanf(fp_r, "%d %d ", &tmp2->color,&tmp2->num);
                  
                    if(tmp3->played_card == NULL){
                        
                        tmp3->played_card = tmp2;
                        tmp2->next = NULL;
                        tmp3->played_card->pre = NULL;
                        tmp3->played_card->next = NULL;
                    


                    }
                    else{
                        tmp3->played_card->pre = tmp2;
                        tmp2->next =tmp3->played_card;
                        tmp3->played_card = tmp2;
                       
                    

                        
                    }
                    
                }
             
            }
            tmp3->pre = NULL;
            tmp3->played_card = radix_sort(tmp3->played_card);
            fscanf(fp_r,"\n");
            if(*recordturn == NULL){
                tmp3->next = NULL;
                *recordturn = tmp3;
            }
            else{
                tmp3->next = *recordturn;
                (*recordturn)->pre = tmp3;
                *recordturn = tmp3;
            }

            back = back + 1;
        }
            
            printf("讀檔成功。\n");
            fclose(fp_r);
            
            return(back);
}