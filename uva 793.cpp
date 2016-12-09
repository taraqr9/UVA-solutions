//you can print the size of a set by any node
#include<bits/stdc++.h>
using namespace std;
int parent[200000];
int Size[200000]; /* size[i] = s where i is the representative of the set  */

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
    return x; /* x means reprasentative */
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
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
    if(i!=1) printf("\n");
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++) makeset(i);
    int yes,no; yes=no=0;
    char line[1000];
    while(1){
            char c;
            int a,b;

            gets(line);
            if (strcmp(line, "") == 0 || feof(stdin)) break;
			sscanf(line, "%c %d %d", &c, &a, &b);

            if(c=='c') Union_by_size(a,b);
            else {
            if(Find(a)==Find(b)) yes++;
            else no++;
        }
    }
     printf("%d,%d\n",yes,no);
    }
    return 0;
}
