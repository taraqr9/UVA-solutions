#include<bits/stdc++.h>
using namespace std;
int prime[100000]; /* sob prime factor gulo thakbe */
void prime_factor(int n)
{
    int i,j=0;
    while(n%2==0){
        prime[j++]=2;
        n/=2;
    }
    for(i=3;i*i<=n;i+=2){
        while(n%i==0){
            prime[j++]=i;
            n/=i;
        }
    }
    if(n>2)
        prime[j++]=n;
    for(i=0;i<j;i++){
        if(i!=0)
        printf(" x ");
        printf("%d",prime[i]);
    }
    printf("\n");
}
int main()
{
    int n,n1;
    while(scanf("%d",&n)==1&&n!=0){
    printf("%d = ",n);
    if(n==-1) printf("-1"); else if(n<0) printf("-1 x ");
    n1 = abs(n);
    if(n1==2147483647) {printf("%d\n",n1); continue; }
    prime_factor(n1);
    }
    return 0;

}
