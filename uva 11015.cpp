#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int main()
{
    int n,m,ans;
    int t_case = 0;
    while(scanf("%d %d",&n,&m)==2){
    getchar();
    if(n==0 && m==0) break;
    t_case++;
    map<int,string>mp;
    for(int i=1;i<=n;i++){
        string s;
        getline(cin,s);
        mp[i] = s;
    }
    int matrix[35][35];
    for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if (i!=j) matrix[i][j] = inf;
                else matrix[i][j] = 0;
            }
    }

    for(int i=1;i<=m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        matrix[u][v] = cost;
        matrix[v][u] = cost;
    }

    for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
        }
      }
    }

    int mini = inf;
    int total_cost;

    for(int i=1;i<=n;i++){
        total_cost = 0;
        for(int j=1;j<=n;j++){
            if(matrix[i][j]!=inf)
            total_cost+= matrix[i][j];
        }
//        cout<<total_cost<<endl;
        if(total_cost<mini) { ans = i; mini = total_cost; }
    }
//    cout<<ans<<endl;
    printf("Case #%d : ",t_case);
    cout<<mp[ans]<<endl;
    }
    return 0;
}
