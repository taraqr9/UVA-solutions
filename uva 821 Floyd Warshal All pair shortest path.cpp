//Floyd Warshall
//complexity O(n^3)
#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int main()
{
    int a,b,pairr;
    int t_case = 0;
    while(scanf("%d %d",&a,&b)==2){
    if(a==0 && b==0) break;
    t_case++;

    int matrix[200][200];
    for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) matrix[i][j]=inf;
    map<int,int>mp;
    matrix[a][b] = 1;

    while(scanf("%d %d",&a,&b)==2 && (a!=0&&b!=0)){
    matrix[a][b] = 1;
    mp[a]=0; mp[b]=0;
    }
    for(int i=1;i<=100;i++){
     for(int j=1;j<=100;j++){
        if(i==j) matrix[i][j] = 0;
     }
    }

    for(int k=1;k<=100;k++){
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    int length_sum=0;
    for(int i=1;i<=100;i++){
     for(int j=1;j<=100;j++){
       if(matrix[i][j]!=inf && matrix[i][j]!=0){
         length_sum+= matrix[i][j];
       }
     }
    }

     pairr = mp.size();
     pairr = pairr * (pairr-1);
     double ans = (double) (length_sum*1.0) / (pairr*1.0);
     printf("Case %d: average length between pages = %0.3lf clicks\n",t_case,ans);
    }
    return 0;
}
