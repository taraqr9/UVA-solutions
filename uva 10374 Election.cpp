#include<bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
int main()
{
    int t;
    string line;
    scanf("%d",&t); getline(cin,line);  //for empty line
    for(int tt=1;tt<=t;tt++){
    int n;
    string candidate,party,save;
    getline(cin,line);   //for empty line
    scanf("%d",&n);  getline(cin, line); //for empty line
    vector< pair<string,string> > v;
    vector<string>V;
    for(int i=1;i<=n;i++){
        getline(cin,candidate);
        getline(cin,party);
        v.pb(make_pair(candidate,party));
    }
    int m;
    scanf("%d",&m); getline(cin, line); //for empty line

    map<string,int>mp;
    for(int i=1;i<=m;i++){
        string s;
        getline(cin,s);
        V.pb(s);
        mp[s]++;
    }
    int mx=0;
    for(int i=0;i<V.size();i++){
        if(mp[V[i]]>mx){
            save = V[i];
            mx = mp[V[i]];
        }
    }
    int cnt = 1;
    for(int i=0;i<V.size();i++){
        if(mp[V[i]]==mx) {
            if(V[i]!=save) cnt=0;
        }
    }
    if(!cnt){
        printf("tie\n");
    }
    else if(cnt){
        for(int i=0;i<v.size();i++){
            if(v[i].X == save){
                cout<<v[i].Y<<endl;
                break;
            }
        }
    }

    if(tt!=t) { cout<<endl; }
    }
}
