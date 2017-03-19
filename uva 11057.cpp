#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int main()
{
    int n,p,i;
    while(scanf("%d",&n)==1){
    int ara[n];
    for(int i=0;i<n;i++) scanf("%d",&ara[i]);
    scanf("%d",&p);

    sort(ara,ara+n);
    pii ans;
    for(int i=0;i<n;i++){
        int one = ara[i];
        int rest = p - ara[i];
        if(rest>=one){
            if(binary_search(ara+i,ara+n,rest)==1) {
                ans.first = one;
                ans.second = rest;
            }
        }
    }
      printf("Peter should buy books whose prices are %d and %d.\n\n",ans.first,ans.second);
    }
}
