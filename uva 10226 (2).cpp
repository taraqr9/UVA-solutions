#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cnt;
    cnt=0;
    cin>>t;
    getchar(); getchar();
    while(t--){
     if(cnt!=0) cout<<endl;
     cnt++;
    string tree;
    map<string,double>mp;
    set<string>myset;
    double total=0.0;
    while(1){
        getline(cin,tree);
        if(tree.size()==0) break;
        myset.insert(tree);
        mp[tree]++;
        total++;
    }
    set<string> :: iterator it;
    for(it=myset.begin();it!=myset.end();it++){
        cout<<*it<<" ";
        cout<<fixed<<setprecision(4)<<mp[*it]/total*100.0<<endl;
    }
  }
    return 0;
}
