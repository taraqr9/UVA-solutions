#include<bits/stdc++.h>
#define mx 100005
#define LL long long
#define pb push_back
int arr[mx],start[mx],End[mx];
int tree[mx * 4];

using namespace std;
map<int,int>mp;
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = mp[arr[b]];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    if(tree[Left]>tree[Right]) tree[node] = tree[Left];
    else tree[node] = tree[Right];
}

int query(int node, int b, int e, int i, int j)  /* takes O(logn) time */
{
    if (i > e || j < b)
        return 0; /* gone outside */
    if (b >= i && e <= j)
        return tree[node]; /* relevant segment */
    int Left = node * 2; /* should be divided more */
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    if(p1>p2) return p1;
    else return p2;
}

int main()
{
    int n,q,a,i,j;
    while(scanf("%d",&n)==1){
    if(n==0) break;
    scanf("%d",&q);
    int as = 1;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        mp[arr[i]]++;
    }
    int save1,save2;
    for(int i=1;i<=n;i++){
        int S = arr[i];
        start[i] = i;
        save1 = i;
        i++;
        if(i>n) { End[i-1] = save1; break; }
        while(arr[i]==S){
            start[i] = save1;
            i++;
            if(i>n) break;
        }
        i--;
        for(int k=save1;k<=i;k++) End[k] = i;
    }

    init(1,1,n);
    while(q--){
        scanf("%d %d",&i,&j);

        if(i==1 && j==n)
        printf("%d\n",query(1,1,n,i,j));

        else{

             int q=0,ans1,ans2;
//................. 1st part
             int beg1 = start[j];
             int END1 = End[j];
             if(beg1>=i){
                ans1 = j-beg1+1;
             }
             else{
                 ans1 = j - i + 1;
             }
//................... 2nd part
            int beg2 = start[i];
            int END2 = End[i];
            if(END2<=j){
                ans2 = END2 - i + 1;
            }
            else {
                ans2 = j - i + 1;
            }
//            cout<<ans1<<" "<<ans2<<endl;
            int ans = max(ans1,ans2);

            if(i+ans2<=j-ans1)
            q = query(1,1,n,i+ans2,j-ans1);
            printf("%d\n",max(ans,q));
        }
    }
    mp.clear();
    }
}
