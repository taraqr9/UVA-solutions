#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    while(cin>>n){
    cin>>m;
    char a,b,c;
    cin>>a>>b>>c;
    vector<int>adj[131];
    set<int>awake;
    int ara[131];   for(i=1;i<=130;i++) ara[i]=0;

    awake.insert(a);  awake.insert(b);  awake.insert(c);
    ara[a]=ara[b]=ara[c]=1;

    for(i=1;i<=m;i++){
        char ch1,ch2;
        cin>>ch1>>ch2;
        int check1,check2;
        check1=check2=1;
        for(j=0;j<adj[ch1].size();j++){
            if(adj[ch1][j]==ch2){ int check1 = 0; break; }
        }
        if(check1==1) adj[ch1].push_back(ch2);
        for(j=0;j<adj[ch2].size();j++){
            if(adj[ch2][j]==ch1){ int check2 = 0; break; }
        }
        if(check2==1) adj[ch2].push_back(ch1);

    }
    int cc=1; int y,w;
    y=0;
    while(1){
        w=0;
        vector<int>vv;
    for(i=1;i<=130;i++){
      if(ara[i]!=1){
        int cnt = 0;
        for(j=0;j<adj[i].size();j++){
            set<int>::iterator it;
            for(it=awake.begin();it!=awake.end();it++){
                if(*it==adj[i][j]) cnt++;
            }
        }
        if(cnt>=3) { /*awake.insert(i);*/ vv.push_back(i);  w=1; ara[i]=1; }
      }
    }
    for(int k=0;k<vv.size();k++) awake.insert(vv[k]);
    if(w==1) y++;
      cc++;
      if(cc==500) break;
    }


    if(awake.size()==n) printf("WAKE UP IN, %d, YEARS\n",y);
    else printf("THIS BRAIN NEVER WAKES UP\n");
}
return 0;
}
