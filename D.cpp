#include<bits/stdc++.h>
using namespace std;
 float h;string u;
 bool check(float hi,string ui){
     if(ui=="m")hi*=100;
     return hi<h;
 }
int main()
{
  //  freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);

    bool ok;
    while(cin>>h>>u){
            if(u=="m")h*=100;
            ok =true;
        int n;cin>>n;
        while(n--){
            float hi;string ui;
            cin>>hi>>ui;
            if(ok)
            ok=check(hi,ui);
                }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}
