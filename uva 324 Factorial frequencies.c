#include<stdio.h>
int a[100000];
int n,i,j,temp,m,x;
void factorial(int n)
{
    a[0]=1;
       m=1;
       temp = 0;
       for(i=1;i<=n;i++)
       {
            for(j=0;j<m;j++)
            {
               x = a[j]*i+temp;
               a[j]=x%10;
               temp = x/10;
            }
             while(temp>0)
             {
               a[m]=temp%10;
               temp = temp/10;
               m++;
             }
      }
}
int main()
{
    int num,zero,one,two,three,four,five,six,seven,eight,nine;
    while(scanf("%d",&num)==1&&num!=0){
    zero=one=two=three=four=five=six=seven=eight=nine=0;
    factorial(num);
    for(i=m-1;i>=0;i--){
        if(a[i]==0)
            zero++;
        if(a[i]==1)
            one++;
        if(a[i]==2)
            two++;
        if(a[i]==3)
            three++;
        if(a[i]==4)
            four++;
        if(a[i]==5)
            five++;
        if(a[i]==6)
            six++;
        if(a[i]==7)
            seven++;
        if(a[i]==8)
            eight++;
        if(a[i]==9)
            nine++;
    }

printf("%d! --\n", num);
printf("(0)    %d    (1)    %d    (2)    %d    (3)    %d    (4)    %d\n", zero, one, two, three, four);
printf("(5)    %d    (6)    %d    (7)    %d    (8)    %d    (9)    %d\n", five, six, seven, eight, nine);
    }
return 0;
}
