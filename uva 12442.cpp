#include<bits/stdc++.h>
using namespace std;

int adj[60000];
int vis[60000];
int save[60000];
int dfs(int start)
{
   int dist=0;
   if(vis[start]==1) return 0;
   vis[start]=1;
   dist = 1 + dfs(adj[start]);
   vis[start]=0;
   return save[start] = dist;
}
int main()
{
     int n,i,t;
     scanf("%d",&t);
     for(int t_case=1; t_case<=t; t_case++){
     scanf("%d",&n);
     for(int j=1;j<=n;j++) { vis[j]=0; save[j]=-1; }

     for(i=1;i<=n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u]=v;
     }
     int mn = 0;
     int node;
     for(i=1;i<=n;i++){
        if(save[i]==-1){
        dfs(i);
        vis[i]=0;
        if(save[i]>mn){
            mn = save[i];
        	node = i ;
        }
       }
     }
     printf("Case %d: %d\n",t_case,node);
    }
    return 0;
}
