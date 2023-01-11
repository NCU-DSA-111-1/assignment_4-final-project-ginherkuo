# DS Final Project
#### 108501510 郭金和 108501544 游勝翔
In the final project, we program for Big Two. 
## What will show you when run this code
1. Enter '1' for start a new game or '2' for watch a old game (does not complete).
2. Show the player's handcard.
3. Enter the number of the card you want to use, or enter '0' to pass.
4. Enter the mark of the card you want to use.
4. Show the card type you play and the played card if conform the rule.
5. Enjoy the game.
6. save in big_two.txt
## Compile & Run
```sh
# Compile
gcc -o main main.c sort.c judge.c fp.h initial.c print.c choose.c save.c
# Run
./main
```

## Explain txt file
ex:
2 3 3 3 2 4 4 4 1 5 2 5 3 5 2 9 4 10 2 11 1 12 2 13 3 13 
2 6 4 6 1 7 2 7 3 7 1 8 4 8 3 9 4 9 3 11 2 12 4 12 4 13 
1 1 4 1 1 2 3 2 3 4 4 5 1 6 3 6 4 7 3 10 1 11 4 11 1 13 
2 1 3 1 2 2 4 2 1 3 4 3 1 4 2 8 3 8 1 9 1 10 2 10 3 12 
4 1 2 1 3 4 3 
1 0 2 2 4 4 4 
2 0 2 2 6 4 6 

前四行為四人個別的卡牌，兩個數字為一組，前面的數字表示花色，後面的表示出的數字。
第四行以下為記錄打出的卡牌。
第一個數字為第幾位玩家。
第二個數字表示是否開始。
第三個數字為打出的牌數為幾張。
之後的數字也是兩個一組，同上。
