#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct players{
  char name[10];
  int balance;
  int won;
}plr[10];


int main(void) {
  int i = 0, dice, dice1, dice_a, dice_b, dice_c, dice_d, point;
  int add_amount;
  char chose_name[100];
  char ask, num;
  srand(time(NULL));
 
  FILE * p = fopen("players.txt","r");
  while(!feof(p) && i < 10){
    fscanf(p, "%s\t%d\t%d", plr[i].name,&(plr[i].balance),&(plr[i].won));
    i +=1;
  }
  
  fclose(p);           
  
  
void print_menu(){
  printf("\n----------------Craps game Menu-------------------\n");
  printf("0 - Top up your balance\n");
  printf("1 - Play\n");
  printf("2 - Display top 5 players in terms of balance \n");
  printf("3 - Display top 5 players in terms of money won\n");
  printf("4 - Exit\n");
  printf("--------------------------------------------------\n\n");
  printf("Your option: ");
}


void add_balance(char chose_name[100],int add_amount){
    printf("\nEnter Your Name: ");
    scanf("%s",chose_name);
    for (int j = 0; j <= 10; j++){
      if(strcmp(chose_name,plr[j].name)==0){
        printf("\nEnter the amount you want to top up your balance: ");
          scanf("%d", &add_amount);
          plr[j].balance = add_amount + plr[j].balance;
        printf("\nThe amount added in your account: %d\n",plr[j].balance);
        break;
      }
  
    else if (j == 10){
    printf("\nIncorrect Name. Please check the namelist carefully..\n");
    printf("Please select names from the following lists..\n");
    
    for(int i = 0; i < 10; i++)
    printf("\n%s",plr[i].name);
  }
  }
  
  p = fopen("players.txt","w");
  for(int i = 0; i <10; i++){
    fprintf(p,"%s\t%d\t%d\n",plr[i].name,plr[i].balance,plr[i].won);
  }
  
  }

  
void play_game(char chose_name[100]){
  printf("\nEnter Your Name: ");
    scanf("%s",chose_name);
    for(int j = 0; j < 10; j++){
      if(strcmp(chose_name,plr[j].name)==0){
        do{
        printf("\nPlease press ENTER key to play game..");
        getchar();
        getchar();
        dice_a = (rand() % (6+1)+1);
        dice_b = (rand() % (6+1)+1);
        dice = dice_a + dice_b;
        printf("\nThe values of the dices are %d and %d whose sum is %d",dice_a,dice_b,dice);
        if((dice==7)||(dice==11)){
          plr[j].won = plr[j].won + 1;
          plr[j].balance = plr[j].balance + 10;
          printf("\n%s Winning.... and your balance value: %d\n",plr[j].name,plr[j].balance);
        }
        else if((dice == 2) || (dice == 3) || (dice == 12)){
          plr[j].won = plr[j].won - 1;
          plr[j].balance = plr[j].balance - 1;
          printf("\nPLayer lose.... Balance is %d\n",plr[j].balance);
        }
        else{
          do{
            point = dice;
            dice_c = (rand() % (6+1)+1);
            dice_d = (rand() % (6+1)+1);
            dice1 = dice_c + dice_d;
            printf("\nPlease press ENTER key to play game..");
            getchar();
            printf("The values of the dices are %d and %d whose sum is %d\n",dice_c,dice_d,dice1);
            
          }while ((dice1 != 7) && (dice1 != point));
          
          if (dice1 == 7){
             plr[j].won = plr[j].won - 1;
             plr[j].balance =  plr[j].balance - 1;
            printf("%s Lose The balance is: %d\n",plr[j].name,plr[j].balance);
          }
          
          else if (dice1 == point){
           // win++;
            plr[j].won = plr[j].won + 1;
             plr[j].balance =  plr[j].balance + 10;
            printf("%s WON...\nThe balance is: %d\n",plr[j].name,plr[j].balance);
          }
        }
      
      printf("Wanna play again (y/n)");
      scanf("%c",&ask);
      }while(ask == 'y');
      }
      else if (j == 10){
       printf("\nIncorrect Name. Please check the namelist carefully..\n");
       printf("Please select names from the following lists..\n");
      
      for(int i = 0; i < 10; i++)
       printf("\n%s",plr[i].name);
      }
    }
    
  p = fopen("players.txt","w");
  for(int i = 0; i <10; i++){
    fprintf(p,"%s\t%d\t%d\n",plr[i].name,plr[i].balance,plr[i].won);
  }  
  
  }
  
  
  
  void top_balance(){
  struct players temp;
  for (int i = 0; i < 5; i++) {
  int max=i;
  for (int j = i + 1; j < 10; j++) {
    if (plr[j].balance > plr[max].balance) {
      max=j;
    }
  }
  
    strcpy(temp.name, plr[i].name);
    strcpy(plr[i].name, plr[max].name);
    strcpy(plr[max].name, temp.name);
    
    temp.balance = plr[i].balance;  
    plr[i].balance = plr[max].balance;
    plr[max].balance = temp.balance;
  }
  
  
 for (int i = 0; i < 5; i++) {
        printf("%s\t%d\n", plr[i].name,plr[i].balance);
    }
  }
  
  
  
  
  void top_won(){
  struct players tempr;
    for (int j = 0; j < 5; j++) {
    int max=i;
    for (int i = j + 1; i < 10; i++) {
      if (plr[i].won > plr[max].won) {
      max=i;
      }
    }
  
    tempr.won = plr[j].won;
    strcpy(tempr.name, plr[j].name);
    
    plr[j].won = plr[max].won;
    strcpy(plr[j].name, plr[max].name);
    
    plr[max].won = tempr.won;
    strcpy(plr[max].name, tempr.name);
  }
  
  
 for (int i = 0; i < 5; i++) {
      printf("%s\t%d\n", plr[i].name,plr[i].won);
    }
  }
  
  
  
  
  do{
  print_menu();
  scanf("%s",&num);
  
  switch (num){
      
  case '0':
    add_balance(chose_name,add_amount);
      break; 


    
  case '1':
    play_game(chose_name);
      break;
     
     
    
  case '2':
  printf("\nDisplay the top 5 players in terms of balance.\n");
    top_balance();
      break;
    
    
    
  case '3':
  printf("\nDisplay the top 5 players in terms of Money Won.\n");
    top_won(); 
      break;
   

 
  case '4':
    exit(0);
      break;
    
    
 default:
 printf("Invalid!!! Please review the MENU choices carefully.");
    break;
  }
  
  }while(num != '4');
  return 0;
}
