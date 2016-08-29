#include <bits/stdc++.h>
#define i64 long long
i64 global;
i64 get_powers(i64 n, i64 p)
{
    i64 res = 0;
    for (i64 power = p ; power <= n ; power *= p)
        res += n/power;
    return res;
}
i64 prime[1000];
void prime_factor(i64 n)
{
    i64 i,j=0;
//    print the number of 2s that divide n

    while(n%2==0){
        prime[j++]=2;
        n/=2;
    }

//    n must be odd at this point . So we can skip one element ( i.e = i+=2)
    for(i=3;i*i<=n;i+=2){
        while(n%i==0){
            prime[j++]=i;
            n/=i;
        }
    }
//    at this point if n is greater than 2 than n itself is a prime factor
    if(n>2)
        prime[j++]=n;
    global = j;
//    printing the prime factors
//    for(i=0;i<j;i++)
//        printf("%d\n",prime[i]);
}
int main()
{
    i64 n , m ,i ,check,count;
    while(scanf("%lld  %lld",&n,&m) == 2){
            if ( m==1 )
       printf("%lld divides %lld!\n",m,n);

    else if(m!=0){
    prime_factor(m);
    i64 a = 0;
    while(a<global){
            count = 0;
    for( i=0 ;i<global ; i++){
        if(prime[i]==prime[a])
            count ++;
    }
    if(get_powers(n, prime[a])>=count)
        check= 1;
    else{
        check = 0 ;
        break;
    }
    a++;
    }
    if(check==1)
        printf("%lld divides %lld!\n",m,n);
    else
        printf("%lld does not divide %lld!\n",m,n);
    }
//    else if(m>n)
//
    else
        printf("%lld does not divide %lld!\n",m,n);


}
return 0;
}
