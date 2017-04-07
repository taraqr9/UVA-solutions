#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x,y,c;
    while(scanf("%lf %lf %lf",&x,&y,&c)==3){
    double lo = 0.0,mid,h1,h2,h;
    double hi;
    hi = min(x,y);
//    printf("%lf %lf %lf\n",x,y,c);
    for(int i=1;i<=1000;i++){
        mid = (lo+hi)/2.0;
        h1 = sqrt((y*y) - (mid*mid));
        h2 = sqrt((x*x) - (mid*mid));
        h = (h1*h2)/(h1+h2);
        if(h<=c){
            hi = mid;
        }
        else lo = mid;
//        printf("%lf %lf\n",h,mid);
    }
    printf("%0.3lf\n",hi);
    }
}
