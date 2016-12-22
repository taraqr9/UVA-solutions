#include<bits/stdc++.h>
using namespace std;

bool balance_check(string s)
{
    stack<char>stk;

    for(int i=0;i<s.size();i++){
    if(s[i]!='(' && s[i]!=')'&& s[i]!='[' && s[i]!=']') continue;

    if(s[i]=='(' || s[i]=='[') stk.push(s[i]);

    else{
    if (stk.empty()){
          return 0;
    }

    if(s[i]==')' && stk.top()!='('){
           return 0;
    }
    else if(s[i]==']' && stk.top()!='['){
           return 0;
    }
    stk.pop();
   }
 }

    if(stk.empty())
    return 1;

    return 0;
}

int main()
{
    int n;
    string s;
    cin>>n;
    getchar();
    while(n--){
        getline(cin,s);
        if(balance_check(s)==1)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

