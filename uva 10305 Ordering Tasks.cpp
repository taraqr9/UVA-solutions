#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

//for directed acyclic graph
//slightly modified dfs (topological sort)

vi ts,adj[500];
int vis[500];
void dfs2(int u)
{
    vis[u] = 1;
    for(int j=0;j<adj[u].size();j++){
        int v = adj[u][j];
        if(vis[v]==0) dfs2(v);
    }
    ts.pb(u); /* this is the only change */
}
int main()
{
    int v,e;
    while(scanf("%d %d",&v,&e)==2){
    if(v==0&&e==0) break;
    ts.clear();
    for(int i=1;i<=v;i++) adj[i].clear();
    memset(vis,0,sizeof(vis));

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    for(int i=1;i<=v;i++){
        if(vis[i]==0) dfs2(i);
    }
    for(int i=ts.size()-1;i>=0;i--) { printf("%d",ts[i]); if(i!=0) printf(" "); }
    printf("\n");
    }
    return 0;
}


