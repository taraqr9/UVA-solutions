#include<bits/stdc++.h>
#define pb push_back
using namespace std;
stack <int> stk;
vector<int>adj[10000],Radj[1000],component[10000];
// Radj means to reverse the edges of the graph
int vis[10000],mark;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
             int v = adj[u][i];
             if(vis[v]==0) dfs(v);
    }
    stk.push(u);
}

void dfs2(int u,int mark)
{
           component[mark].pb(u);  //save the nodes of the new component
           vis[u] = 1;
           for(int i=0;i<Radj[u].size();i++){
               int v = Radj[u][i];
               if(vis[v]==0) dfs2(v,mark);
           }
}

int main()
{
         int n,e;
         while(scanf("%d %d",&n,&e)==2){
         if(n==0 && e==0) break;
         mark = 0;  /* mark is to name the component */
         for(int i=1;i<=e;i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(w==1){
            adj[u].pb(v);
            Radj[v].pb(u);
            }
            if(w==2){
                 adj[u].pb(v);
                 adj[v].pb(u);
                 Radj[v].pb(u);
                 Radj[u].pb(v);
            }
         }
//         topsort
         memset(vis,0,sizeof(vis));
         for(int i=1;i<=n;i++){
            if(vis[i]==0) dfs(i);
         }

        memset(vis,0,sizeof(vis));
        while (!stk.empty()){
               int u = stk.top();
               stk.pop();
               if (vis[u]==0){
                    mark = mark+1; //A new component found, it will be identified by ‘mark’
                    dfs2(u,mark);
              }
        }
//        for(int i=1;i<=mark;i++){
//            for(int j=0;j<component[i].size();j++) cout<<component[i][j]<<" ";
//            printf("\n");
//        }

        if(mark!=1) printf("0\n");
        else printf("1\n");
        for(int i=1;i<=n;i++) {
            adj[i].clear();
            Radj[i].clear();
            component[i].clear();
        }
        while(!stk.empty()) stk.pop();
     }
}
