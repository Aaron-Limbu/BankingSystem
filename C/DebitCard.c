#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1024

struct debitcard{
    int pinnumber, WithdrawalAmount,BalanceAmount ; 
    char DateofWithdrawal[20]; 
    bool haswithdrawn ;
    
}; 

void display(); 
void withdraw(int pinnumber,int WithdrawalAmount,int BalanceAmount,bool haswithdrawn,char DateofWithdrawal[20]);
void displaydetails(int pinnumber,int WithdrawalAmount,int BalanceAmount,bool haswithdrawn,char DateofWithdrawal[20]);

int main(int argc,int argv[]){
     struct debitcard d;
     d.haswithdrawn = false; 
     char ans[3]; 
     int *pin , *wd ,*ba;  
     printf("Enter your pin number\n"); 
     scanf("%d",&d.pinnumber);
     pin = &d.pinnumber;
     printf("Enter your WithdrawalAmount \n"); 
     scanf("%d",&d.WithdrawalAmount); 
     wd = &d.WithdrawalAmount;
     printf("Enter your BalanceAmount\n"); 
     scanf("%d",&d.BalanceAmount);
     ba = &d.BalanceAmount; 
     printf("Do you want to withdraw: Y or N \n"); 
     scanf("%s",&ans) ;
        if(ans[0] =='Y'){
                withdraw(*pin,*wd,*ba,d.haswithdrawn,d.DateofWithdrawal); 
                return 0 ; 
            }else {
                d.haswithdrawn = false;

            }
     displaydetails(*pin,*wd,*ba,d.haswithdrawn,d.DateofWithdrawal);
} 
void display(){
    FILE *prop; 
    int max =0 ;
    char get[MAX];
    prop = fopen("Bankcard.txt","r"); 
    while (fgets(get,MAX,prop)!=NULL && max++ < 3){
        printf("%s\n",get);
    }
    fclose(prop);
  
}
void withdraw(int pinnumber,int WithdrawalAmount,int BalanceAmount,bool haswithdrawn,char DateofWithdrawal[20] ){
    FILE *fp;
    fp=fopen("date.txt","w");
    int pin,count=0;
    printf("Enter your pin number \n"); 
    scanf("%d",&pin);
    do{
        if(pin == pinnumber){
        printf("logged in \n"); 
             if(BalanceAmount > WithdrawalAmount){
                int YY,MM,DD; 
                char Y[12],M[4],D[4];
                 printf("the amount has been withdrawn\n");
                 BalanceAmount -= WithdrawalAmount; 
                 printf("current BalanceAmount is %d\n",BalanceAmount);  
                 printf("Enter Withdrawal date : YYYY-MM-DD\n"); 
                  scanf("%d%d%d",&YY,&MM,&DD);
                 itoa(YY,Y,10);itoa(MM,M,10);itoa(DD,D,10);
                 strcat(DateofWithdrawal,Y);
                 strcat(DateofWithdrawal,M);
                 strcat(DateofWithdrawal,D); 
                fprintf(fp,"%s",DateofWithdrawal); 
                 
                 haswithdrawn = true; 
                  displaydetails(pinnumber,WithdrawalAmount,BalanceAmount,haswithdrawn, DateofWithdrawal);
                  break ;
             }else{
                 printf("You have insufficient Bank Amount \n"); 
             }
        }else{
            printf("your pin nummber is incorrect\n"); 
        }
        count++; 
    }while(count != 3);
   fclose(fp);
} 

void displaydetails(int pinnumber,int WithdrawalAmount,int BalanceAmount,bool haswithdrawn,char DateofWithdrawal[20]){
        
        if(haswithdrawn == true){
            display(); 
            printf("BalanceAmount: %d\n",BalanceAmount); 
            printf("pin number: %d\n",pinnumber); 
            printf("Date of Withdrawal: %s",DateofWithdrawal);
        } else{
            display();
        }
}