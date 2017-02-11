#include<bits/stdc++.h>
#define  ull unsigned long long
using namespace std;
int main()
{
    ull t,now,neu;
    cin>>t;
    while(t--){
    ull l,r;
    cin>>l>>r;
    if(l==r){
        if( (l-2)%4==0 ) cout<<l<<endl;
        else if(l%4==0) cout<<l+1<<endl;
        else if((l-3)%4==0) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else if((r-l) == 1){
        if((l-1)%4==0 || (r-1)%4==0) cout<<0<<endl;
        else if( (l-2)%4==0 || (r-2)%4==0) cout<<0<<endl;
        else{
            cout<<1<<endl;
        }
    }
    else cout<<0<<endl;
    }
    return 0;
}

