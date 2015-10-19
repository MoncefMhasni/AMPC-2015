#include<bits/stdc++.h>
#define INF 1+10000*2000
using namespace std;
int f(int n){
    if(n%10>=5)return n+10-n%10;
    else return n-n%10;
}
int main()
{
    freopen("I.in","r",stdin);
    freopen("I.out","w",stdout);
    int n,d,sum[2001];
    int tc;
    cin>>tc;
    while(tc--){
    cin>>n>>d;
    d++;
    int tmp;
    sum[0]=0;
    for(int i=0;i<n;i++){
            cin>>tmp;
            sum[i+1]=sum[i]+tmp;
    }
    vector<vector<int> >dp(n+1,vector<int>(d+1, INF) );
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=d;j++)
            for(int x=0;x<i;x++)
                dp[i][j]=min(dp[i][j],dp[x][j-1]+f(sum[i]-sum[x]));
    cout<<*min_element(dp[n].begin()+1,dp[n].end())<<endl;
    }

}
