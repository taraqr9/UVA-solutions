#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL coin[22];  //value of coins available
LL make ;  //we will try to make this amount
LL dp[22][10001];
LL call(LL i,LL amount)
{
    if(i>=21) { //All coins have been taken
        if(amount==0) return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount]; //no need to calculate same state twice
    LL ret1=0,ret2=0;
    if(amount-coin[i]>=0) ret1 = call(i,amount - coin[i]); //try to take coin i
    ret2 = call(i+1,amount); //dont take coin i
    return dp[i][amount] = ret1 + ret2; //storing and returning the total ways.

}
int main()
{
    for(LL i=1;i<=21;i++){
        coin[i-1] = i*i*i;
    }

    memset(dp,-1,sizeof(dp));
    while(scanf("%lld",&make)==1){
        printf("%lld\n",call(0,make));
    }
    return 0;
}



