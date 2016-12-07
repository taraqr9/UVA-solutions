#include<bits/stdc++.h>
using namespace std;
#define MAX_NODE 1000000
#define MAX_LEN 100
int node[MAX_NODE][100];
int root,nnode;
void initialization(){
    root = 0;
    nnode = 0;
    for(int i=0;i<100;i++) node[root][i] = -1;
}
void insert(string S){
    int len = S.size();
    int now = root;
    for(int i=0;i<len;i++){
        if(node[now][S[i]]==-1){
            node[now][S[i]] = ++nnode;
        }
        for(int j=0;j<100;j++) node[nnode][j] = -1;
        now = node[now][S[i]];
    }
}
bool search(string S){
    int len = S.size();
    int now = root; int chk=0;
    for(int i=0;i<len;i++){
        if(node[now][S[i]]==-1){
            chk = 1;
        }
        now = node[now][S[i]];
    }
    if(chk==0) return 1;
    return 0;
}
int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--){
    string str;

    cin>>n;
    initialization();
    vector<pair<int,string> >v;
    while(n--){
    cin>>str;
    v.push_back(make_pair(str.size(),str));
    }
    int check=0;
    sort(v.begin(),v.end());
    for(i=v.size()-1;i>=0;i--){
        if(search(v[i].second)==1) { check=1; break; }
        insert(v[i].second);
    }
    if(check==1) printf("NO\n");
    else printf("YES\n");
    }
    return 0;
}
