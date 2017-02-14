#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,save;
    while(cin>>n && n!=0){
    int num[1000];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(num[i]!=0){
          ans.push_back(num[i]);
        }
    }
    int S = ans.size();
    for(int i=0;i<S;i++) {
        cout<<ans[i];
        if(i!=S-1) cout<<" ";
    }
    if(ans.size()==0) cout<<0;
    cout<<endl;
    }

}
