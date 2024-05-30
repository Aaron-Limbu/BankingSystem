#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1024

struct creditcard
{
    int CVCnumber, creditlimit, graceperiod;
    char ExpirationDate[20];
    float InterestRate;
    bool isGranted;
};
void setcreditlimit(int CVCnumber, int InterestRate, char ExpirationDate[20], int newcreditlimit, int newgraceperiod, int BalanceAmount,bool isGranted);
void cancelcreditcard(int creditlimit, int graceperiod, int BalanceAmount, bool isGranted);
void display(int CVCnumber, int InterestRate, char ExpirationDate[20], int creditlimit, int BalanceAmount, int graceperiod, bool isGranted);

int main(int argc, int argv[])
{
    FILE *expdate;
    expdate = fopen("expdate.txt", "w");
    int BalanceAmount;
    struct creditcard c;
    int YY, MM, DD;
    char Y[12], M[4], D[4];
    int *cvc, *bamnt;
    char ans[3];
    printf("Enter your CVCnumber\n");
    scanf("%d", &c.CVCnumber);
    cvc = &c.CVCnumber;
    printf("Enter your BalanceAmount\n");
    scanf("%d", &BalanceAmount);
    bamnt = &BalanceAmount;
    printf("Enter your Interest Rate\n");
    scanf("%f", &c.InterestRate);
    printf("Enter your Expiration Date\n");
    scanf("%d%d%d", &YY, &MM, &DD);
    itoa(YY, Y, 10);
    itoa(MM, M, 10);
    itoa(DD, D, 10);
    strcat(c.ExpirationDate, Y);
    strcat(c.ExpirationDate, M);
    strcat(c.ExpirationDate, D);
    fprintf(expdate, "%s", c.ExpirationDate);
    printf("do you want to set credit limit? Y or N\n");
    scanf("%s", &ans);
    if (ans[0] == 'Y')
    {
        setcreditlimit(c.CVCnumber,c.InterestRate,c.ExpirationDate, c.creditlimit, c.graceperiod, BalanceAmount, c.isGranted);
    }
    else
    {
        c.isGranted = false;
    }
    printf("do you want to cancel credit limit? Y or N\n");
    scanf("%s", &ans);
    if (ans[1] == 'Y')
    {
        cancelcreditcard(c.CVCnumber, c.creditlimit, c.graceperiod, c.isGranted);
    }
    else
    {
    }
    display(c.CVCnumber, c.InterestRate , c.ExpirationDate,c.creditlimit, BalanceAmount, c.graceperiod, c.isGranted);
    fclose(expdate);
}
void setcreditlimit(int CVCnumber, int InterestRate, char ExpirationDate[20], int newcreditlimit, int newgraceperiod, int BalanceAmount,bool isGranted)
{
    int cd, gp;

    printf("Enter your credit limit\n");
    scanf("%d", &cd);
    printf("Enter your graceperiod \n");
    scanf("%d", &gp);
    if (cd <= 2.5 * BalanceAmount)
    {
        cd=newcreditlimit;
        gp=newgraceperiod;
        isGranted = true;
    }
    else
    {
        printf("Credit cannot be issued. \n");
    }
}
void cancelcreditcard(int creditlimit, int graceperiod, int BalanceAmount, bool isGranted)
{
    creditlimit = '0';
    graceperiod = '0';
    BalanceAmount = '0';
    isGranted = false;
    
}
void sdisplay()
{
    FILE *pf;
    pf = fopen("Bankcard.txt", "r");
    int max = 0;
    char dis[MAX];
    while (fgets(dis, MAX, pf) != NULL && max++ < 4)
    {
        printf("%s\n", dis);
    }
    fclose(pf);
}
void display(int CVCnumber, int InterestRate, char ExpirationDate[20], int creditlimit, int BalanceAmount, int graceperiod, bool isGranted)
{
    sdisplay();
    if(isGranted == true ){
        printf("CVCnumber: %d\n", CVCnumber);
        printf("InterestRate: %d\n", InterestRate);
        printf("ExpirationDate: %s\n", ExpirationDate);
        printf("creditlimit: %d\n", creditlimit);
        printf("graceperiod: %d\n", graceperiod);
    }
}