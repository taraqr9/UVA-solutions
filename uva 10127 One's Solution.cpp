// * nurshuvo51@gmail.com
// * Number theory , BiG Mod
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
i64 base_power_mod(i64 base,i64 power,i64 mod)
{
    i64 c;
    if(power==0)
        return 1;
        if(power%2==0){
//      i.e : 5^6 =  (5 ^3)* (5^3) ... Formula : (a*b)%m= ( (a%m)*(b%m) ) %m
        c=base_power_mod(base,power/2,mod);
        return ((c % mod) * (c % mod) )% mod;
    }
    else{
//        i.e : 5^3 = 5 * 5^2
        return ( ( base%mod)* base_power_mod(base,power-1,mod) ) % mod;
    }
}
int main()
{
    i64 n,multiple,c,modu;
    while(scanf("%lld",&n)==1){
    c=0;
    modu=0;
    while(1){
       modu=( modu + base_power_mod(10,c,n) ) %n;
       c++;
       if(modu==0)
        break;
    }
    printf("%lld\n",c);
    }
    return 0;
}
