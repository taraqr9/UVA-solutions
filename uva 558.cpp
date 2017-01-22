//   complexity O(node*edge)
//   In case of negative cycle it works

#include<bits/stdc++.h>
#define pii pair<int,int>
#define inf  1000000000
#define X    first
#define Y    second
#define pb   push_back
#define Max_node  10000
int flag;
using namespace std;
int dis[Max_node],cost[Max_node][Max_node];
void bellman(vector<pii>G,int source,int node)
{
    for(int i=0;i<node;i++) dis[i] = inf;
    dis[source] = 0;
    for(int i=0;i<node;i++){
        for(int i=0;i<G.size();i++){
            if(dis[G[i].X] + cost[G[i].X][G[i].Y]<dis[G[i].Y])
                dis[G[i].Y] = dis[G[i].X] + cost[G[i].X][G[i].Y];
        }
    }
    for(int i=0;i<G.size();i++){
            if(dis[G[i].X] + cost[G[i].X][G[i].Y]<dis[G[i].Y]){
                flag=1;
                return;
            }
        }
//        cout<<"not possible"<<endl;
}
int main()
{
    int c;
    cin>>c;
    while(c--){
    int node,edge,u,v,w;
    cin>>node>>edge;
    vector<pii>G;

    for(int i=0;i<edge;i++){
        cin>>u>>v>>w;
        G.pb({u,v});
        cost[u][v] = w;
    }
    int source,des;
    flag=0;
    for(int i=0;i<node-1;i++){
    bellman(G,i,node);
    if(flag==1) { cout<<"possible"<<endl; break; }
    break;
    }
    if(flag==1) continue;
    cout<<"not possible"<<endl;
    }
    return 0;
}

