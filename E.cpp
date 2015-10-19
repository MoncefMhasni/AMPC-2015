#include<bits/stdc++.h>
#define INF INT_MAX/2
using namespace std;
void solve(vector<vector<int> >&g)
{
   queue<pair<int,int>> Q;
   int M=g.size(),N=g[0].size();
   vector<vector<int> > visited(M);visited.clear();
   for(int i=0;i<M;i++)visited[i].resize(N);
   visited[M-1][0]=1;
   Q.push(make_pair(M-1,0));
   while(!Q.empty())
   {
      pair<int,int> p = Q.front();
      Q.pop();
      for(int x =-2;x<=2;x++)
      {
         for(int y =-2;y<=2;y++)
         {
            int i = p.first+x;
            int j = p.second+y;
            if(i<0 || i>=M || j<0 || j>=N || g[i][j]==-1||abs(x)+abs(y)!=3) continue;
            g[i][j]=min(g[i][j],g[p.first][p.second]+1);
            if(visited[i][j]==0)
            {
                visited[i][j]=1;
                Q.push(make_pair(i,j));
            }
         }
      }
   }
}
int main(){
   // freopen("E.in","r",stdin);
   // freopen("E.out","w",stdout);
    int n,m;
    while(cin>>m>>n){
        vector<vector<int> >g;
        g.resize(m);
        for(int i=0;i<m;i++){
            g[i].resize(n);
            for(int j=0;j<n;j++)g[i][j]=INF;
        }
        g[m-1][0]=0;
        solve(g);
        if(g[0][m-1]==INF)
            cout<<"-1"<<endl;
        else
        cout<<g[0][n-1]<<endl;
    }
    return 0;

}
