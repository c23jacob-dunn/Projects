#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STARTING_BET 4

int black[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
int red[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
int green[18] = {0,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bet = STARTING_BET;
int number = 38;
char color = 'n';
int total = 0;
int winnings = 0;
int maxBet = 0;
int profit = 0;
int loseStreak = 0;
int longestLoseStreak = 0;

int Roll(int bet){
   number = rand() % 38;
   if(number<0 || number>37){
      return 0;
   }

   for(int i=0; i<18; i++){
      if(number == black[i]){
         color = 'b';
         winnings += (bet*2);
         loseStreak = 0;
         break;
      }
      else if(number == red[i]){
         color = 'r';
         loseStreak++;
         break;
      }
      else if(number == green[i]){
         color = 'g';
         loseStreak++;
         break;
      }
   }

   if(color == 'n'){
      return 0;
   }
   return 1;
}

int main(){
   srand (time(NULL));
   while(1){
      int check = Roll(bet);
      if(check == 0){
         return 0;
      }
      total += bet;
      profit = winnings - total;
      printf("Num: %d, Color: %c, Bet: %d, Winnings: %d, Total: %d, Highest Bet: %d, Profit: %d, Most Losses: %d\n", number, color, bet, winnings, total, maxBet, profit, longestLoseStreak);

      if(color == 'b'){
         bet = STARTING_BET;
      }
      else if(color == 'r'){
         bet = bet*2;
      }
      else if(color == 'g'){
         bet = bet*2;
      }
      if(bet>maxBet){
         maxBet = bet;
      }
      if(loseStreak>longestLoseStreak){
         longestLoseStreak = loseStreak;
      }
   }
   
   return 1;
}
