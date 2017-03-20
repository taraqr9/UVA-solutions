#include<bits/stdc++.h>
#define mod 131071
using namespace std;
int main()
{
    string s,total;
    while(cin>>s){
        int len = s.size();
        if(s[len-1]=='#'){
            total += s;
            int res = 0;
            int p = 1;
            for(int i=total.size()-2;i>=0;i--){
                res += (total[i]-48)*p;
                res %= mod;
                p*=2;
                p%=mod;
            }
            if(res==0) puts("YES");
            else puts("NO");
            total.clear();
        }
        else total+=s;
    }
    return 0;
}
