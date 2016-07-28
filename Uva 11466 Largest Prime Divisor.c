#include<stdio.h>
int main()
{
    long long int n,rslt,i,counter;
    while(scanf("%lld",&n)==1){
        if(n<0) n=(-1)*n;
    counter=0;
    for(i=2;i*i<=n&&n!=1;i++){
            if(n%i==0){
                    counter++;
        while(n%i==0){
            n/=i;
            if(n==1) break;
            rslt=n;
        }
    }
    }
    if(counter>=1&&n!=1)
    printf("%lld\n",n);
    else if(counter>1&&n==1)
    printf("%lld\n",rslt);
    else
    printf("-1\n");
}
return 0;
}
