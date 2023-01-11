#ifndef _fp
#define _fp

#define spade 4
#define heart 3
#define diamand 2
#define club 1
#define one_card 1 //單牌
#define pair 2 //對子
#define straight 3 //順子
#define full_house 4 //葫蘆
#define four_of_a_kind 5 //鐵支
#define straight_flush 6 //同花順
#define false 0
#define true 1

typedef struct card{
    int color;
    int num;
    struct card *pre;
    struct card *next;
}card;

typedef struct card_point{
    int card_type;
    int point;
    struct card_point *next;
}card_point;

typedef struct record_turn{
    int turn;
    int start;
    int n;
    card *played_card;
    struct record_turn *pre;
    struct record_turn *next;
}record_turn;

extern int initial(card *handcard[], card *record_handcard[]);
extern void printcard(int who, card *handcard);
extern card *radix_sort(card *be_sorted);
extern int choose( int cardmuch,int start, card **handcard, card_point **recordpoint, record_turn **recordturn, int turn);
extern int play_or_not(int n, int start, card *be_judged, card_point **record_point);
extern void record_func(record_turn **recordturn, int turn, int start, int n, card *played);
extern void save_to_file(card *record_handcard[], record_turn *recordturn);
extern int load(card *handcard[],record_turn **recordturn);
#endif