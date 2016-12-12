#include<bits/stdc++.h>
using namespace std;
vector<int>adj[300];
int path[300],visited[300];

int bfs(int s,int des)
{
    queue<int>Q;
    memset(visited,0,sizeof(visited));
    Q.push(s);
    visited[s]=1;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]]!=1){
                int v=adj[u][i];
                visited[v]=1;
                path[v]=u;
                Q.push(v);
            }
            if(visited[des]==1) break;
        }
    }
    int now=des;
    int cnt=0;
    while(now!=s){
        cnt++;
        now=path[now];
    }
    return cnt;
}
bool is_adj(string a,string b)
{
    int l1 = a.size();
    int l2 = b.size();
    if(l1!=l2) return 0;
    int cnt = 0;
    for(int i=0;i<l1;i++){
        if(a[i]!=b[i]) cnt++;
        if(cnt>=2) break;
    }
    if(cnt==1) return 1;
    else return 0;
}
int main()
{
    int t;
    cin>>t; getchar();
    for(int w=1;w<=t;w++){
    if(w!=1) printf("\n");
    string dic;
    vector<string>v;
    map<string,int>mp;
    int as = 1;
    while(1){
        getline(cin,dic);
        if(dic=="*") break;
        if(mp.find(dic)==mp.end()) { mp[dic]=as++; v.push_back(dic); }
    }

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(is_adj(v[i],v[j])==1){
                adj[mp[v[i]]].push_back(mp[v[j]]);
                adj[mp[v[j]]].push_back(mp[v[i]]);
            }
        }
    }
    char u[100],p[100];
    char line[100];
    while(1){
        gets(line);
        if (strcmp(line, "") == 0 || feof(stdin)) break;
        sscanf(line, "%s %s", &u, &p);
        printf("%s %s %d\n",u,p,bfs(mp[u],mp[p]));
    }
    for(int i=1;i<=as;i++) adj[i].clear();
   }
   return 0;

}
