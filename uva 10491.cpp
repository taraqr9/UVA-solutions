#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ncow,ncars,nshow;
    while(cin>>ncow>>ncars>>nshow){

    double case1 = (ncow/(ncow+ncars)) *  (ncars/(ncow - 1.0 - nshow + ncars));
    double case2 = ((ncars/(ncow+ncars)) * ((ncars - 1.0)/(ncars - 1.0 + ncow - nshow )));

    cout<<fixed<<setprecision(5)<<case1+case2<<endl;
    }
}
