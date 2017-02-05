#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    char mini = 'z';
    int ara[150];
    for(int i=0;i<=122;i++) ara[i] = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] < mini) mini = s[i];
        ara[s[i]]++;
    }

    for(int i=0;i<s.size();i++){
        if(ara[s[i]]>1) {
//            cout<<i+1<<endl;
//            cout<<ara[s[i]]<<endl;
            ara[s[i]]--;
            s[i] = mini;
//            cout<<ara[s[i]]<<endl;
        }
    }
    sort(s.begin(),s.end());
    cout<<s<<endl;
    }

}
