#include<bits/stdc++.h>
using namespace std;
int toint(string s){int v;stringstream ss(s); ss>>v; return v;}
typedef struct op{
    string d;
    long a;
    int t;
    inline bool operator<(op a){
        if(toint(d.substr(6,4))<toint(a.d.substr(6,4)))
            return true;
        if(toint(d.substr(6,4))>toint(a.d.substr(6,4)))
            return false;
        if(toint(d.substr(3,2))<toint(a.d.substr(3,2)))
            return true;
        if(toint(d.substr(3,2))>toint(a.d.substr(3,2)))
            return false;
        return toint(d.substr(0,2))<toint(a.d.substr(0,2));
    }
    op& operator=(const op& x){
    d = x.d;
    a = x.a;
    t = x.t;
    return *this;
    }
    op& operator+ (const op&x){
    a+=x.a;
    return *this;
    }
}op;

int main()
{
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        int N;cin>>N;string tmp; long v; char t;
        op D={"00/00/0000",0,1},W={"00/00/0000",0,0},X;
        while(N--){
          do{
            cin>>tmp;
          }while(!isdigit(tmp[0]));
            cin>>v>>t;
            if(t=='D'){
                    X={tmp,v,1};
                    D=D+X;
                    if(D<X)
                    D.d=X.d;
                }
            else{
                    X={tmp,v,0};
                    W=W+X;
                    if(W<X)
                    W.d=X.d;
                }
        }
       cout<<"Case #"<<tc<<":\n";
       cout<<D.a<<" "<<D.d<<endl;
       cout<<W.a<<" "<<W.d<<endl;
    }
}
