#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a[10];
    while(scanf("%d",&n)==1&& n!=0){
    map<string,int>mp;
    string ara[100000];
    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            scanf("%d",&a[j]);
        }
        stringstream yy;
        sort(a,a+5);
        for(j=0;j<5;j++){
            yy<<a[j];
        }
        string str ;
        str = yy.str();
        ara[i]=str;
//        cout<<str<<endl;
       if(mp.find(str)==mp.end()){
            mp[str] = 0;
        }
    }
    int mn =0;
    for(i=0;i<n;i++){
        mp[ara[i]]++;
        mn=max(mn,mp[ara[i]]);
    }
    int rslt=0;
    for(i=0;i<n;i++){
        if(mp[ara[i]]==mn)
        rslt+=mn;
    }

    if(rslt!=1)
    printf("%d\n",rslt/mn);
    else  printf("%d\n",n);
}
return 0;
}
