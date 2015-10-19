#include<bits/stdc++.h>
using namespace std;
typedef struct pb{ int c;double p;}pb;
long solve( vector<pb> v,double P,long S,int n,double m){
        if(n<0)return 0;
        if(P>=m)
            return S;
      return max(solve(v,P/v[n-1].p,S-v[n-1].c,n-1,m),solve(v,P,S,n-1,m));
}
int main()
{
   freopen("A.in","r",stdin);
   freopen("A.out","w",stdout);

    int tc;
    cin>>tc;
    while(tc--){
            cerr<<tc<<endl;
        int N;cin>>N;
        vector<pb> v(N);
        double P=1;
        long S=0;
        for(int i=0;i<N;i++){
            double x;int C;
            cin>>x>>C;
            v[i]={C,x};
            P*=x;
            S+=C;
        }
        double M;cin>>M;
        cout<<solve(v,P,S,N,1-M)<<endl;
    }
}
