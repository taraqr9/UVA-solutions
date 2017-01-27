#include<bits/stdc++.h>
using namespace std;

using namespace std;

int main(){
    int tc = 1,T,n,r[100001];
    r[0] = 0;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);

        for(int i = 1;i <= n;++i)
            scanf("%d",&r[i]);

        sort(r,r + n);

        int lo = 0,hi = 10000000,mid;

        for(int w=1;w<=1000;w++){
            mid = (lo + hi) /2;

            bool ok = true;

            for(int i = 0,k = mid;i + 1 <= n && ok;++i){
                if(r[i + 1] - r[i] > k) ok = false;
                else if(r[i + 1] - r[i] == k) --k;
            }

            if(!ok) lo = mid + 1;
            else hi = mid;
        }

        printf("Case %d: %d\n",tc++,lo);
    }

    return 0;
}
