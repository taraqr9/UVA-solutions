#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
#define Max 1000005
#define mod 1000000000005
char  prime[Max+1];
vector<LL>p;
LL i,j;
void sieve()
{
    LL i,j,x;
    for(i=0;i<=Max;i++)
        prime[i]=0;
    prime[0]=prime[1]=1;
    for(i=4;i<=Max;i+=2)
        prime[i]=1;
    x=sqrt(Max);
    for(i=3; i<=x; i+=2){
        for(j=i*i;j<=Max;j+=i)
            prime[j]=1;
    }
}

int main()
{
    sieve() ;
    for(LL i=1;i<Max;i++){
        if(prime[i]==0) p.pb(i);
    }
    int t;
    cin>>t;
    while(t--){
    LL n,small,m,cnt,s,nn;
    scanf("%lld",&n);
    nn = n;
    LL sum = 1,ck=0;
    for(int i=0;i<p.size();i++){
        if(p[i]<=nn){
            if(n%p[i]==0){
                m=1,s=1;
                while(n%p[i]==0){
                    n/=p[i];
                    m*=p[i];
                    s+=m;
                }
                sum*=s;
            }
        }
    }

    m=1,s=1;
    if(n>2){
        m*=n;
        s+=m;
        sum*=s;
    }

    sum-=nn;

    if(sum==nn) puts("perfect");
    else if(sum<nn) puts("deficient");
    else puts("abundant");
    }
}
