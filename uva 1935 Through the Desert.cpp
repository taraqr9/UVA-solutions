#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int dis,n;
string event;
void make(string s)
{
    int save,save2=-1;
    string s1,s2;
    for(int i=0;s[i];i++){
        if(isdigit(s[i])) s1.pb(s[i]);
        else { save = i; break; }
    }
    stringstream (s1)>>dis;
    for(int i=save+1;s[i];i++){
        if(!isalpha(s[i])) { save2 = i; break; }
        else event.pb(s[i]);
    }
    if(save2!=-1){
    for(int i=save2;s[i];i++){
        if(isdigit(s[i])){
            for(int k=i;s[k];k++) {
                s2.pb(s[k]);
            }
            break;
        }
    }
    if(s2.size()>=1)
    stringstream (s2)>>n;
    }
}

int main()
{
    vector<string>Events;

    while(1){
    char s[100];
    gets(s);
    if (strcmp(s, "0 Fuel consumption 0") == 0 || feof(stdin)) break;
    string ss;
    for(int i=0;s[i];i++) ss.pb(s[i]);
    make(ss); Events.pb(ss);

    char check[100]; int i;
    for(i=0;i<event.size();i++) check[i]=event[i];
    check[i] = NULL;
    if (strcmp(check, "Goal") == 0 || feof(stdin)){

    event.clear();

    double lo=0.0,hi=10000000.0,ase,ase1;

    for(int step=1;step<=1000;step++){

    ase = (lo+hi)/2.0;
    ase1 = ase;

    int leak = 0;
    int flag = 1;
    for(int i=1;i<Events.size();i++){

        // previous calculation
        int d1,d2,nn;
        event.clear();
        make(Events[i-1]);
        d2 = dis;
        nn = n;
        string E = event;
        event.clear();

        make(Events[i]);
        d1 = dis;
        event.clear();

        if(E=="Fuel"){
            ase-= (nn*1.0/100.0)*(d1*1.0-d2*1.0) + (d1*1.0-d2*1.0)*leak*1.0;
        }
        else if(E=="Leak") { leak++;  ase-= ((nn*1.0/100.0)*(d1*1.0-d2*1.0) + (d1*1.0-d2*1.0)*leak*1.0); }
        else if(E=="Gas") {
                 ase = ase1;
                 ase-= ((nn*1.0/100.0)*(d1*1.0-d2*1.0) + (d1*1.0-d2*1.0)*leak*1.0);
                 if(ase<-0.00000001) { lo = ase1; flag=0; break; }
        }
        else if(E=="Mechanic") {  leak = 0; ase-= ((nn*1.0/100.0)*(d1*1.0-d2*1.0) + (d1*1.0-d2*1.0)*leak*1.0); }
        else{ ase-= ((nn*1.0/100.0)*(d1*1.0-d2*1.0) + (d1*1.0-d2*1.0)*leak*1.0); }
        if(ase<-0.00000001) { lo = ase1; flag=0;  break; }
    }
    if(flag) hi = ase1;
    }
    printf("%0.3f\n",hi);
    Events.clear();
    }
    event.clear();
    }
}
