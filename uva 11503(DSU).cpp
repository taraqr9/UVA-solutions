#include<bits/stdc++.h>
using namespace std;

int parent[200000];
int Size[200000];
void makeset(int x)
{
    parent[x]=x;
    Size[x]=1;
}
int Find(int x)
{
    while(x!=parent[x]){
        x = parent[x];
    }
    return x;
}
void Union_by_size(int x,int y)
{
    int r = Find(x);
    int s = Find(y);
    if(r==s) return;
    else if(Size[r]>Size[s]){
        parent[s] = r;
        Size[r]+=Size[s];
    }
    else{
        parent[r] = s;
        Size[s]+= Size[r];
    }
}
int main()
{

    int n,i,j,t;
    cin>>t;
    while(t--){
    cin>>n;
    for(i=1;i<=2*n;i++) makeset(i);
    map<string,int>mp;
    int as=1;
    for(i=1;i<=n;i++){
        string a,b;
        cin>>a;
        cin>>b;
        if(mp.find(a)==mp.end()) mp[a] = as++;
        if(mp.find(b)==mp.end()) mp[b] = as++;

        Union_by_size(mp[a],mp[b]);
        int cnt = Find(mp[a]);

        printf("%d\n",Size[cnt]);
    }
    }
    return 0;
}




