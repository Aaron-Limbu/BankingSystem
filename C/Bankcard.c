#include <stdio.h>
#include <string.h>
struct bankcard{
    char Clientname[30],issuerBank[30],BankAccount[30]; 
    int cardId , BalanceAmount ; 
};

char display(char Clientname[30],char issuerBank[30], char BankAccount[30] ,int cardId , int BalanceAmount );

int main(int argc,int argv[]){
    FILE *Bankcard ; 
    struct bankcard b; 
    char *Cname[30] ,*issBnk[30],*BnkAcnt[30]; 
    int *card,*bamnt; int j=0; 
    Bankcard = fopen("Bankcard.txt","w"); 
    printf("enter Clientname \n"); 
    scanf("%s",&b.Clientname); 
    printf("enter issuerBank \n"); 
    scanf("%s",&b.issuerBank);
    printf("enter BankAccount \n"); 
    scanf("%s",&b.BankAccount); 
    for(int i = 0 ; i < 30 ; i++){
        Cname[i]=&b.Clientname[i];
        issBnk[i]=&b.issuerBank[i];
        BnkAcnt[i]=&b.BankAccount[i];
    }
       fprintf(Bankcard,"Clientname: %s\n",*Cname);
       fprintf(Bankcard,"issuerBank: %s\n",*issBnk);
       fprintf(Bankcard,"BankAccount: %s\n",*BnkAcnt);
    printf("enter cardId\n"); 
    scanf("%d",&b.cardId);
    card = &b.cardId; 
    printf("enter BalanceAmount\n"); 
    scanf("%d",&b.BalanceAmount);
    bamnt = &b.BalanceAmount;  
    display(*Cname,*issBnk,*BnkAcnt,*card,*bamnt);  
    fprintf(Bankcard,"Card id: %d\n",*card);
    fprintf(Bankcard,"Balance Amount: %d\n",*bamnt);
    fclose(Bankcard);
}
char display(char Clientname[30],char issuerBank[30], char BankAccount[30] ,int cardId , int BalanceAmount ){
    
       if((strcmp(Clientname,""))==0){
            printf("there is no Client Name stored\n"); 
       }
       else {
          printf("Clientname %s \n",Clientname);
        }
       printf("issuerBank %s\n" ,issuerBank); 
       printf("BankAccount %s\n" ,BankAccount); 
       printf("cardID %d\n" ,cardId); 
       printf("BalanceAmount %d\n" ,BalanceAmount); 
      
       

}
