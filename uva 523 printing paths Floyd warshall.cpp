#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int main()
{
    int m;
    string line;
    cin>>m;
    getchar();
    getline(cin,line);
    while(m--){
    string first;
    getline(cin,first);
    first.push_back(' ');
    vector<int>v;
    for(int i=0;i<first.size();i++){
        string t;
        while(first[i]!=' '){
            t.push_back(first[i]);
            i++;
        }
        int ans;
        stringstream(t)>>ans;
        v.push_back(ans);
    }

    int pos = v.size();
    int matrix[pos+1][pos+1];
    for(int i=0;i<pos;i++) { if(v[i]==-1) v[i]=inf; matrix[1][i+1] = v[i]; }

    for(int i=2;i<=pos;i++){
        for(int j=1;j<=pos;j++){
            int u;
            cin>>u;
            if(u==-1) u = inf;
            matrix[i][j] = u;
        }
    }
    int tax[pos+1];
    for(int i=1;i<=pos;i++) { int u; cin>>u; tax[i] = u; }

//    Floyd warshal to print path using next array
    int next[pos+1][pos+1];
    for(int i=1;i<=pos;i++) for(int j=1;j<=pos;j++) next[i][j] = j; /*essential part */

    for(int k=1;k<=pos;k++){
        for(int i=1;i<=pos;i++){
            for(int j=1;j<=pos;j++){
                if(matrix[i][k] + matrix[k][j] + tax[k]< matrix[i][j]){
                    matrix[i][j] =  matrix[i][k] + matrix[k][j] + tax[k]; /* tax is added for this problem
                                                                           specification */
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    getchar();
    int cnt =0 ;
    while(1){
        string input;
        getline(cin,input);
        if(input.empty()||input.size()==0) break;
        if(cnt!=0) printf("\n");
        cnt++;
        input.push_back(' ');

        vector<int>v;
        for(int i=0;i<input.size();i++){
            string t;
            while(input[i]!=' '){
                t.push_back(input[i]);
                i++;
            }
            int ans;
            stringstream(t)>>ans;
            v.push_back(ans);
        }
        int start = v[0];
        int des = v[1];

// printing shortest path from start to des
        vector<int>route;
        route.push_back(start);
        int u = start;
        while(start!=des){
            start = next[start][des];
            route.push_back(start);
        }
        printf("From %d to %d :\n",u,des);
        printf("Path: ");
        for(int i=0;i<route.size();i++) { if(i!=0) printf("-->"); cout<<route[i]; }
        cout<<endl;
        printf("Total cost : %d\n",matrix[u][des]);
      }
    }
    return 0;
}
