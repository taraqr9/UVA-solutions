#include<bits/stdc++.h>
using namespace std;
double p,q,r,s,t,u;

// it is sufficient to check the signs for f(0) and f(1) to determine whether there is a root in range [0,1].

double res(double x)
{
   return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)==6){
    double lo = 0.0,hi = 1.0,mid;
    int ck = 0;
    for(int i=0;i<1000;i++){
          mid = (lo+hi)/2.0;
          if(res(mid)<=0.0) hi = mid;
          else lo = mid;
    }

    if(res(mid)>=0.000000001 || res(mid)<=-0.999999999) puts("No solution");

    else printf("%0.4lf\n",mid);
    }
}
