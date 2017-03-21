#include<bits/stdc++.h>
using namespace std;
int main(){

    long long N, M, ans;
    while(scanf("%lld %lld", &N, &M) == 2){
        ans = 1;
        for( long long int a = N - M + 1; a <= N; a++ ){
            ans *= a;
            while(ans %10 == 0) ans /= 10;
            ans %= 100000000000;
        }
        printf("%lld\n", ans%10);
    }
    return 0;
}
