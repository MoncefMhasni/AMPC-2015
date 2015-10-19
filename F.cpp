#include<bits/stdc++.h>
using namespace std;
const int MAXN=510;

int N, M, B;
long long MOD = 999999999;
long long dp[MAXN][MAXN];

int main()
{
    freopen("F.in","r",stdin);
    freopen("F.out","w",stdout);
    int tc;
    cin>>tc;
    while(tc--){
    cin>>N>>M>>B;
    for (int i=0;i<MAXN;i++)
        for (int j=0;j<MAXN;j++)
            dp[i][j]=0;
    dp[0][0]=1;
    for (int i=0;i<N;i++)
    {
        int a;cin>>a;

        for (int j=0;j<M;j++)
            for (int k=0;k<=B-a;k++)
                if (dp[j][k])
                    dp[j+1][k+a]=(dp[j+1][k+a]+dp[j][k])%MOD;
    }

    long long ans=0;
    for (int i=0;i<=B;i++)
        ans=(ans+dp[M][i])%MOD;
    cout <<ans<< "\n";
    }
    return 0;
}
