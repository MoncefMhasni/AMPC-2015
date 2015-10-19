#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int main()
{

    int tc;
    cin>>tc;
    while(tc--){
        double S,N,theta,T1,T2,T3,T4;
        cin>>S>>N>>T1>>T2>>T3;
        double s,v,phi,Ra,t;
        double w=2*pi*N/60.0;
        T4=60/N-T1-T2-T3;
        theta=0;
        vector<pair<double,double>>ans;
        while(theta<=360){
             t=(pi*theta/180.0)/w;
            if(t<T1){
             s=0.5*S*(1-cos(pi*t/T1))+50;
             v=pi/2 * S/T1 * sin((pi*t)/T1);
             phi=atan2(v,(w*s));
             Ra=s/cos(phi);
            }
            else if(t-T1<T2){
             s=S+50;
             v=0;
             phi=0;
             Ra=s;
            }
            else if(t-T1-T2<T3){
             s=S/2 *(1-cos((pi*t)/T3))+50;
             v=pi/2 * S/T3 * sin((pi*t)/T3);
             phi=atan2(v,(w*s));
             Ra=s/cos(phi);
            }
            else{
             s=50;
             v=0;
             phi=0;
             Ra=s;
            }
            //scout<<t<<" "<<Ra<<endl;
            ans.push_back(make_pair((pi*theta/180.0+phi),Ra));
            theta+=0.01;
        }
        int x;double min=1e9;
        int n;
        cin>>n;

        while(n--){
                cin>>theta;
                x=0;
                min=1e9;
                theta=theta*pi/180.0;
            for(int i=0;i<ans.size();i++)
                if(fabs(theta-ans[i].first)<min){
                    min=fabs(theta-ans[i].first);
                    x=i;
                }
                        printf("%.3f\n",ans[x].second);


        }
    }
}
