#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,newline=0;
    while(cin>>k && k!=0){
    if(newline!=0) printf("\n"); newline++;
    int se[k];
    for(int i=0;i<k;i++) cin>>se[i];
    for(int a=0;a<k-5;a++)
        for(int b=a+1;b<k-4;b++)
          for(int c=b+1;c<k-3;c++)
             for(int d=c+1;d<k-2;d++)
               for(int e=d+1;e<k-1;e++)
                 for(int f=e+1;f<k;f++)
                   printf("%d %d %d %d %d %d\n",se[a],se[b],se[c],se[d],se[e],se[f]);
    }
    return 0;
}
