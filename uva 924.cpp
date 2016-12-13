#include<bits/stdc++.h>
using namespace std;
vector<int>adj[30000];
int path[30000],visited[30000];
int dis[30000];
void bfs(int s)
{
    queue<int>Q;
    memset(visited,0,sizeof(visited));
    memset(dis,0,sizeof(dis));
    Q.push(s);
    visited[s]=1;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        int cnt = 0;
        for(int i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]]!=1){
                int v=adj[u][i];
                visited[v]=1;
                dis[v]=dis[u]+1;
                path[v]=u;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int e;
    cin>>e;

    for(int i=0;i<e;i++){
        int n;
        cin>>n;
        while(n--){
            int f;
            cin>>f;
            adj[i].push_back(f);
        }
    }
    int t;
    cin>>t;
    while(t--){
    int s;
    cin>>s;
    bfs(s);
    vector<int>v;
    for(int i=0;i<e;i++){
       if(i!=s && dis[i]>0){
       v.push_back(dis[i]);
       }
     }
     int pos[3000];
     for(int i=0;i<e;i++) pos[i]=0;
     for(int i=0;i<v.size();i++){
        pos[v[i]]++;
     }
     int mn = 0;
     for(int i=0;i<e;i++){
        if(pos[i]>mn && i!=s){
            mn = max(pos[i],mn);
      }
     }
     vector<int>d;
     int cnt = 0;
     for(int i=0;i<v.size();i++){
        if(pos[v[i]]==mn) {
            d.push_back(v[i]);
        }
     }
     if(d.size()>0){
     sort(d.begin(),d.end());
     for(int i=0;i<v.size();i++){
        if(v[i]==d[0]) {
            cnt++;
        }
      }
     }
     if(d.size()==0 || cnt==0 || mn==0) cout<<0<<endl;
     else{
     if(d[0]==0) cout<<0<<endl;
     else cout<<cnt<<" "<<d[0]<<endl;
     }
    }
    return 0;
}
