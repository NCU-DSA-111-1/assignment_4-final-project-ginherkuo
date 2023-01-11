#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fp.h"
//////////////////
#include <stdbool.h>


//
/////////////
int main(){
    int decision;//新局還是舊局
    bool functionOverSign = 1;//遊戲是否結束，0結束

    while (functionOverSign) {
        printf("請輸入引數，1為開新局，2為復盤。\n");
        scanf("%d",&decision);
        int cardmuch;
        int cardnumber;
        int turn;
        int start;
        card *handcard[4] = {NULL};
        card *record_handcard[4] = {NULL};
        card_point *recordpoint = NULL;
        record_turn *recordturn = NULL;
        bool gameOverSign = 1;//遊戲是否結束，0結束
        bool isStandard = 1;//是否符合規則，初始值1，符合
        char savepoint;
        if(decision == 1){
            gameOverSign = 1;
            isStandard = 1;
          
            int firstone = initial(handcard, record_handcard); // have the club 3
            int pass[4] = {false};
            

            //開始下棋
            turn = firstone+1;
            int counter = 0;
            start = 1;
                while (gameOverSign) {
                    //isStandard = 1;
                    printf("------------------------------------\n");
                    /////////////////////decide how many people pass
                    int check = 0;
                    int realturn = 0;
                    for(int i = 0; i < 4 ; i++){
                        if(pass[i] == 1)check =check + 1 ;
                        if(pass[i] == 0)realturn = i;
                    }
                    if(check == 3){
                        turn  = realturn+1;
                        start = 1;
                        counter = 0;
                        for(int i = 0; i < 4 ; i++)
                        pass[i] = 0 ;
                    }
                    //////////////////////
                    //we have four people = four cases
                    switch (turn) {
                        case 1:
                            ///////////////////////////////
                            if(pass[0] == 1)
                                break;
                            ///////////////////////////////
                            printf("輪到Player_1的回合。\n");
                            printcard(1, handcard[0]);
                            if(recordpoint != NULL){
                                printf("請問是否存檔?y/n :");
                                scanf(" %c",&savepoint);
                                getchar();
                                if(savepoint == 'y'){
                                    printf("您選擇存檔。");
                                    save_to_file(record_handcard, recordturn);
                                }
                                else
                                    printf("您選擇否。");

                                printf("請問此局是否繼續?y/n :");
                                scanf(" %c",&savepoint);
                                getchar();
                                if(savepoint == 'n'){
                                    printf("您選擇中離。");
                                    gameOverSign = 0;
                                    break;
                                }
                            }
                            printf("請選擇想出的牌數，若要pass請輸入零: ");
                            scanf("%d",&cardmuch);
                            if(cardmuch == 0){
                                isStandard = true;
                                printf("Player_1選擇pass。\n");
                                printf("------------------------------------\n"); 
                                pass[0]=1;
                                record_func(&recordturn, turn, start, cardmuch, NULL);
                                break;
                            }
                            else if(cardmuch == 1 || cardmuch == 2 || cardmuch == 5 ){
                                isStandard = choose(cardmuch, start,&handcard[0], &recordpoint, &recordturn, turn);
                            }
                            else {
                                isStandard = false;
                                printf("不符合，請從來\n");
                                printf("------------------------------------\n"); 
                                break;
                            }
                            /////////////////////////////decide its behavior to true or false
                            if(isStandard == true){
                                if(counter == 0){
                                    start = 0;
                                    counter = counter + 1; 
                                }
                            }
                            else{
                                printf("不符合，請從來\n");
                            } 
                            //////////////////////  
                            printf("------------------------------------\n"); 
                            break;
                        case 2:
                            //printcard(turn, handcard[turn-1]); AI2
                            if(pass[1] == 1)
                                break;
                            ///////////////////////////////
                            printf("輪到Player_2的回合。\n");
                            printcard(2, handcard[1]);
                            if(recordpoint != NULL){
                                printf("請問是否存檔?y/n :");
                                scanf(" %c",&savepoint);
                                getchar();
                                if(savepoint == 'y'){
                                    printf("您選擇存檔。");
                                    save_to_file(record_handcard, recordturn);;
                                }
                                else
                                    printf("您選擇否。");

                                printf("請問此局是否繼續?y/n :");
                                scanf(" %c",&savepoint);
                                getchar();
                                if(savepoint == 'n'){
                                    printf("您選擇中離。");
                                    gameOverSign = 0;
                                    break;
                                }
                            }
                            printf("請選擇想出的牌數，若要pass請輸入零: ");
                            scanf("%d",&cardmuch);
                            if(cardmuch == 0){
                                isStandard = true;
                                printf("Player_2選擇pass。\n");
                                printf("------------------------------------\n"); 
                                pass[1]=1;
                                record_func(&recordturn, turn, start, cardmuch, NULL);
                                break;
                            }
                            else if(cardmuch == 1 || cardmuch == 2 || cardmuch == 5 ){
                                isStandard = choose(cardmuch, start, &handcard[1], &recordpoint, &recordturn, turn);
                            }
                            else{
                                isStandard = false;
                                printf("不符合，請從來\n");
                                printf("------------------------------------\n"); 
                                break;
                            }
                            //////////////////////////////////////
                            if(isStandard == true){
                                if(counter == 0){
                                    start = 0;
                                    counter = counter + 1; 
                                }
                            }
                            else{
                                printf("不符合，請從來\n");
                            } 
                            ///////////////////////////////
                            printf("------------------------------------\n"); 
                            break;
                        case 3:
                            //printcard(turn, handcard[turn-1]); AI3
                            if(pass[2] == 1)
                                break;
                            ////////////////////////////////////////
                            printf("輪到Player_3的回合。\n");
                            printcard(3, handcard[2]);
                            if(recordpoint != NULL){
                                printf("請問是否存檔?y/n :");
                                scanf(" %c",&savepoint);
                                getchar();
                                if(savepoint == 'y'){
                                    printf("您選擇存檔。");
                                    save_to_file(record_handcard, recordturn);
                                }
                                else
                                    printf("您選擇否。");

                                printf("請問此局是否繼續?y/n :");
                                scanf(" %c",&savepoint);
                                getchar();
                                if(savepoint == 'n'){
                                    printf("您選擇中離。");
                                    gameOverSign = 0;
                                    break;
                                }
                            }
                            printf("請選擇想出的牌數，若要pass請輸入零: ");
                            scanf("%d",&cardmuch);
                            if(cardmuch == 0){
                                isStandard = true;
                                printf("Player_3選擇pass。\n");
                                printf("------------------------------------\n"); 
                                pass[2]=1;
                                record_func(&recordturn, turn, start, cardmuch, NULL);
                                break;
                            }
                            else if(cardmuch == 1 || cardmuch == 2 || cardmuch == 5 ){
                                isStandard = choose(cardmuch, start, &handcard[2], &recordpoint, &recordturn, turn);
                            }
                            else {
                                isStandard = false;
                                printf("不符合，請從來\n");
                                printf("------------------------------------\n"); 
                                break;
                            }
                            /////////////////////////////////////
                            if(isStandard == true){
                                if(counter == 0){
                                    start = 0;
                                    counter = counter + 1; 
                                }
                            }
                            else{
                                printf("不符合，請從來\n");
                            } 
                            ///////////////////////////////
                            printf("------------------------------------\n"); 
                            break;    
                        case 4:
                            //printcard(turn, handcard[turn-1]); AI4
                            if(pass[3] == 1)
                                break;
                            ////////////////////////////////////////
                            
                            printf("輪到Player_4的回合。\n");
                            printcard(4, handcard[3]);
                            if(recordpoint != NULL){
                                printf("請問是否存檔?y/n :");
                                scanf(" %c",&savepoint);
                                getchar();
                                if(savepoint == 'y'){
                                    printf("您選擇存檔。");
                                    save_to_file(record_handcard, recordturn);;
                                }
                                else
                                    printf("您選擇否。");

                                printf("請問此局是否繼續?y/n :");
                                scanf(" %c",&savepoint);
                                getchar();
                                if(savepoint == 'n'){
                                    printf("您選擇中離。");
                                    gameOverSign = 0;
                                    break;
                                }
                            }
                            printf("請選擇想出的牌數，若要pass請輸入零: ");
                            scanf("%d",&cardmuch);
                            if(cardmuch == 0){
                                isStandard = true;
                                printf("Player_4選擇pass。\n");
                                printf("------------------------------------\n"); 
                                pass[3]=1;
                                record_func(&recordturn, turn, start, cardmuch, NULL);
                                break;
                            }
                            else if(cardmuch == 1 || cardmuch == 2 || cardmuch == 5 ){
                                isStandard = choose(cardmuch, start, &handcard[3], &recordpoint, &recordturn, turn);
                            }
                            else {
                                isStandard = false;
                                printf("不符合，請從來\n");
                                printf("------------------------------------\n"); 
                                break;
                            }
                            //////////////////////////////////////
                            if(isStandard == true){
                                if(counter == 0){
                                    start = 0;
                                    counter = counter + 1; 
                                }
                            }
                            else{
                                printf("不符合，請從來\n");
                            } 
                            ///////////////////////////////
                            printf("------------------------------------\n"); 
                            break;    
                    }
                    //////////////////////decide whether the game end
                    if(handcard[turn-1]==NULL)
                        gameOverSign = 0;
                    //////////////////////if turn is end ,we decide to next
                    if(isStandard == true){
                        if(turn == 4)//4 player
                            turn = 1;
                        else 
                            turn = turn + 1; 
                    }
                 //////////////////////
                }    
            printf("遊戲結束!\n");
        }
















        else if(decision == 2){
            gameOverSign = 1;
            int top ;
            int count = 0;
            record_turn *recordturn1 = NULL;
            top = load(handcard,&recordturn);
            for(int i = 0;i<top;i++){
                    if(recordturn->next !=NULL)
                    recordturn = recordturn->next;
                }    
            while (gameOverSign) {
                printf("請輸入小寫f或b:");            
                scanf(" %c",&savepoint);
                getchar();
                
                if(savepoint == 'f'){
                    
                    if(recordturn->next ==NULL&& count==0){}
                    
                    else if(recordturn->pre ==NULL&& count==1){printf("you cant push f anymore\n");}    
                    else
                        {recordturn = recordturn->pre; }        
                    
                    
                    card *tmp = handcard[turn-1];//copy handcard
                    card *tmp2 = NULL;//要出的牌
                    card *tmp3 = recordturn->played_card;
                    turn = recordturn->turn;
                    printf("------------------------------------\n");
                    printf("輪到Player_%d的回合。\n",turn);
                    //printcard(turn, handcard[turn]);                       
                    cardmuch = recordturn->n;
                    start = recordturn->start;
                    if(cardmuch == 0){
                        isStandard = true;
                        printf("Player_%d選擇pass。\n",turn);
                        printf("------------------------------------\n");
                                                    
                        
                    }
                    else if(cardmuch == 1 || cardmuch == 2 || cardmuch == 5 ){
                        for(int j = 0; j < cardmuch; j++){
                            
                            tmp = handcard[turn-1];
                            for(int k = 1; k < 14; k++){
                                
                                    if(tmp3->color==tmp->color && tmp3->num == tmp->num){
                                        
                                        if(tmp->pre == NULL && tmp->next == NULL){
                                            handcard[turn-1] = NULL;
                                        }
                                        else if(tmp->pre == NULL){
                                            tmp->next->pre = NULL;
                                            handcard[turn-1] = tmp->next;
                                        }
                                        else if(tmp->next == NULL){
                                                    tmp->pre->next = NULL;
                                        }
                                        else{
                                            tmp->pre->next = tmp->next;
                                            tmp->next->pre = tmp->pre;
                                        }
                                        
                                    }
                                    if(tmp->next != NULL)
                                        tmp = tmp->next;    
                            }
                            if(tmp3->next != NULL)
                                tmp3=tmp3->next;
                         
                        }
                        printcard(turn,handcard[turn-1] );
                        play_or_not(cardmuch, start,recordturn->played_card, &recordpoint);
                        printcard(0, recordturn->played_card);
                        printf("------------------------------------\n");
                        count = 1;
                    
                    }//else if
                            
                }
                else if(savepoint == 'b'){
                    card *tmp = handcard[turn-1];//copy handcard
                    card *tmp3 = recordturn->played_card;
                    card *tmp2 = NULL;
                    
                    card *tmp4 = NULL;
                    turn = recordturn->turn;
                    cardmuch = recordturn->n;
                   /* for(int i =0;i<cardmuch;i++){
                        tmp4->color=tmp3->color;
                        tmp4->num=tmp3->num;
                        if(tmp3->next!=NULL){
                            tmp2=tmp4;
                            tmp3=tmp3->next;
                        }
                       

                    }*/

                    /*while(tmp!=NULL){
                        if(tmp->next == NULL)
                        break;
                    else{tmp = tmp->next;}    
                    }  
                    tmp->next = tmp2;
                    tmp2->pre=tmp;
                    
                    handcard[turn-1] = radix_sort(handcard[turn-1]);
                    printcard(0, handcard[turn-1]);*/
                    
                    
                    if(recordturn->pre ==NULL&& count==0){}
                    
                    else if(recordturn->next ==NULL&& count==1){printf("you cant push b anymore\n");}    
                    else
                        {recordturn = recordturn->next; }       
                     tmp = handcard[turn-1];//copy handcard
                    tmp3 = recordturn->played_card;
                    turn = recordturn->turn;

                    printf("------------------------------------\n");
                    printf("輪到Player_%d的回合。\n",turn);
                    //printcard(turn, handcard[turn]);                       
                    cardmuch = recordturn->n;
                    start = recordturn->start;
                    if(cardmuch == 0){
                        isStandard = true;
                        printf("Player_%d選擇pass。\n",turn);
                        printf("------------------------------------\n");
                                                 
                        
                    }
                    else if(cardmuch == 1 || cardmuch == 2 || cardmuch == 5 ){
                        
                        printcard(turn,handcard[turn-1] );
                        play_or_not(cardmuch, start,recordturn->played_card, &recordpoint);
                        printcard(0, recordturn->played_card);
                        printf("------------------------------------\n");
                       
                    }//else if
                     
                }
            }
        } 
        else {printf("請重新輸入引數。\n");}
    }
}