#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,type,topp;
    while(scanf("%d",&n)==1){
    vector<int>t,xx;
    for(int i=0;i<n;i++){
        cin>>type;
        cin>>x;
        t.push_back(type);
        xx.push_back(x);
    }
    priority_queue<int> pq;
    int c = 1;
    for(int i=0;i<n;i++){

        if(!pq.empty()) topp = pq.top();
        if(t[i]==1){
        pq.push(xx[i]);
        }
        else if(t[i]==2){
            if(topp!=xx[i] || pq.empty()) { c = 0; break; }
            if(!pq.empty()) pq.pop();
        }
    }

    stack<int> st;
    int s = 1;
    for(int i=0;i<n;i++){

        if(!st.empty()) topp = st.top();
        if(t[i]==1){
        st.push(xx[i]);
        }
        else if(t[i]==2){
            if(topp!=xx[i] || st.empty()) { s = 0; break; }
            if(!st.empty()) st.pop();
        }
    }

    queue<int>qu;
    int q=1;
    for(int i=0;i<n;i++){

        if(!qu.empty()) topp = qu.front();
        if(t[i]==1){
        qu.push(xx[i]);
        }
        else if(t[i]==2){
            if(topp!=xx[i] || qu.empty()) { q = 0; break; }
            if(!qu.empty()) qu.pop();
        }
    }

  if(c==0 && s==0 && q==0) cout<<"impossible"<<endl;
  else if(c==1 && s==0 && q==0) cout<<"priority queue"<<endl;
  else if(s==1 && c==0 && q==0) cout<<"stack"<<endl;
  else if(q==1 && c==0 && s==0) cout<<"queue"<<endl;
  else cout<<"not sure"<<endl;
}
return 0;
}
