#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    LL n,m,u,cnt;
    while(scanf("%lld %lld",&n,&m)==2){
    if(n==0&&m==0) break;
    cnt=0;
    map<LL,LL>mp;
    for(int i=0;i<n;i++) { scanf("%lld",&u); mp[u]=1; }
    for(int i=0;i<n;i++) { scanf("%lld",&u); if(mp.find(u)!=mp.end()) cnt++; }
    printf("%lld\n",cnt);
    }
}
