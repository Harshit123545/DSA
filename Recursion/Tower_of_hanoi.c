#include<stdio.h>
int towerHanoi(int n,char s,char d,char t);
int count;
int main()
{
    int n;
    printf("Enter number of disk : ");
    scanf("%d",&n);
    towerHanoi(n, 's', 'd', 't');
    printf("Total number of moves : %d",count);
}
int towerHanoi(int n,char s,char d,char t)
{
    if(n>0)
    {
        towerHanoi(n-1,s,t,d);
        printf("Move %d disk from %c to %c \n", n,s,d);
        towerHanoi(n-1,t,d,s);
        count++;
    }
}