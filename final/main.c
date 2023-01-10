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
        printf("請輸入引數，1為開新局，2為負盤。\n");
        scanf("%d",&decision);

        if(decision == 1){
            bool gameOverSign = 1;//遊戲是否結束，0結束
            bool isStandard = 1;//是否符合規則，初始值1，符合
            int cardmuch;
            int cardnumber;
            int turn;
            int start;
            card *handcard[4] = {NULL};
            card_point *recordpoint = NULL;
            record_turn *recordturn = NULL;
            int firstone = initial(handcard); // have the club 3
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
    else {printf("請重新輸入引數。\n");}

    }
}