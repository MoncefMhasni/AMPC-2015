#include<bits/stdc++.h>
using namespace std;
int treat(vector<int> q,int m){
    int ans=0;
    do{
    for(int i=1;i<q.size();){

        if(q[0]<q[i]){
            q.push_back(q[0]);
            q.erase(q.begin()); 
            m--; 
            if(m<0)m=q.size()-1; 
            i=1; 
        }
        else i++; 
    }
    q.erase(q.begin()); 
    m--; 
    ans++; 
    }while(m>=0);
    return ans;

}
int main () {
    freopen("J.in","r",stdin);
    freopen("out1.txt","w",stdout);
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<int> Q(n);
        for(int i=0;i<n;i++)
            cin>>Q[i];
        int ans=treat(Q,m);
        cout<<ans<<endl;
    }

}
