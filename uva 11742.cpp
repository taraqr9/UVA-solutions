#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2 ){
    if(n==0&&m==0) break;
    vector< pair<int, pair<int,int> > > v;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v.push_back(make_pair(a,make_pair(b,c)));
    }
    int p[n];
    for(int i=0;i<n;i++) p[i]=i;
    int cnt = 0;
    do{
      int ara[n];
      for(int i=0;i<n;i++){
        ara[p[i]] = i;
//        cout<<p[i]<<" ";
      }
//      cout<<endl;
      int f = 1;
      for(int i=0;i<m;i++){
        if(v[i].second.second>0){
            int dis = abs( ara[v[i].first] - ara[v[i].second.first] );
            if(dis > v[i].second.first) { f=0; break; }
        }
         if(v[i].second.second<0){
            int dis = abs( ara[v[i].first] - ara[v[i].second.first] ) ;
            if(dis < ((-1)*v[i].second.second)) { f=0; break; }
        }
      }
     if(f==1) cnt++;

    }while(next_permutation(p,p+n));
    printf("%d\n",cnt);
    }
    return 0;
}
