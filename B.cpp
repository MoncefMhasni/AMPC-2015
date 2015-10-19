#include<bits/stdc++.h>
#define N 1001
using namespace std;
long knapSack(long W, long wt[], long val[], long n)
{
   long i, w;
   long K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int  main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    long  C[N];
    long  K[N];
    long tc;
    cin>>tc;
    while(tc--){
        long n,B;
        cin>>n>>B;
       // cerr<<n<<" "<<B<<endl;
        for(long i=0;i<n;i++)
                cin>>K[i]>>C[i];

        long ans=knapSack(B,C,K,n);
        cout<<ans<<endl;
    }
}
