#include<bits/stdc++.h>
using namespace std;
int treat(vector<int> q,int m){
    int ans=0;
    do{
    for(int i=1;i<q.size();){

        if(q[0]<q[i]){
            q.push_back(q[0]);//put the one in the front in the back of the queue
            q.erase(q.begin()); // ans remove it from the front
            m--; // the submission may advance in the queue
            if(m<0)m=q.size()-1; //if the submission was removed from the front then it is in the back
            i=1; // recheck from 1
        }
        else i++; // check next one
    }
    q.erase(q.begin()); // the front has been judged, go to next
    m--; // the sub may advance
    ans++; // it took 1 minute to make the treatment above
    }while(m>=0);
    return ans;

}
int main () {
   // freopen("J.in","r",stdin);
   // freopen("out1.txt","w",stdout);
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
