#include<bits/stdc++.h>
int main()
{
    long long int num,x,n,a,i,start,end;
    while (scanf("%lld",&num)==1 && num!=-1){
    x=sqrt(2*num);
    for(n=x;n>=1;n--){
       a = ( 2*num + n - n*n )/ (2*n) ;
       if( ( (2*num + n - n*n) % (2*n) )==0 ){
          start =a;
          end = a + n - 1 ;
          break ;
       }
    }
    printf("%lld = %lld + ... + %lld\n", num,start , end);
    }
    return 0;
}
