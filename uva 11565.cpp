#include<bits/stdc++.h>
#define p printf
#define s scanf
#define LL long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    int A,B,C;
    s("%d %d %d",&A,&B,&C);
    int solve = 1;

    for(int i=-100;i<=100 && solve==1;i++){
        for(int j=-100;j<=100 && solve==1;j++){
            for(int k=-100;k<=100 && solve==1;k++){
                if(i!=j && j!=k && k!=i && i+j+k==A && i*j*k==B && i*i+j*j+k*k==C){
                    p("%d %d %d\n",i,j,k);
                    solve=0;
                }
            }
        }
      }
      if(solve==1) p("No solution.\n");
    }
    return 0;

}

