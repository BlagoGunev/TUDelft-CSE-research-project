#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N =1e5+400;
string g[100010];
vector<int> pre[100010];
int gt(int x1,int y1,int x2,int y2)
{
    return pre[x2][y2]-(x1==0?0:pre[x1-1][y2])-(y1==0?0:pre[x2][y1-1])+(x1==0||y1==0?0:pre[x1-1][y1-1]);
}
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 0;i<n;i++) {cin>>g[i];pre[i].resize(m);}
    pre[0][0] = (g[0][0]=='#');
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(i==0&&j==0) continue;
            if(i==0) pre[i][j] = pre[i][j-1]+(g[i][j]=='#');
            else if(j==0) pre[i][j] = pre[i-1][j]+(g[i][j]=='#');
            else pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(g[i][j]=='#');
        }
    }
    int ans = 0;
    if(n<m) //暴力枚举行.
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                //枚举四种方式
                int sum = 0;
                for(int l = 0;l<=k;l++)
                {
                    int row = i-l,col = min(j+k-l,m-1);
                    if(row<0) break;
                    sum+=gt(row,j,row,col);
                }
                ans = max(ans,sum);
                sum = 0;
                for(int l = 0;l<=k;l++)
                {
                    int row = i+l,col = min(j+k-l,m-1);
                    if(row>=n) break;
                    sum+=gt(row,j,row,col);
                }
                ans = max(ans,sum);
                sum = 0;
                for(int l = 0;l<=k;l++)
                {
                    int row = i+l,col = max(j-k+l,0);
                    if(row>=n) break;
                    sum+=gt(row,col,row,j);
                }
                ans = max(ans,sum);
                sum = 0;
                for(int l = 0;l<=k;l++)
                {
                    int row = i-l,col = max(j-k+l,0);
                    if(row<0) break;
                    sum+=gt(row,col,row,j);
                }
                ans = max(ans,sum);
            }
        }
    } else //暴力枚举列. 
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                //枚举四种方式
                int sum = 0;
                for(int l = 0;l<=k;l++)
                {
                    int col = j+l,row = max(0,i-k+l);
                    if(col>=m) break;
                    sum+=gt(row,col,i,col);
                }
                ans = max(ans,sum);
                sum = 0;
                for(int l = 0;l<=k;l++)
                {
                    int col = j+l,row = min(n-1,i+k-l);
                    if(col>=m) break;
                    sum+=gt(i,col,row,col);
                }
                ans = max(ans,sum);
                sum = 0;
                for(int l = 0;l<=k;l++)
                {
                    int col = j-l,row = min(n-1,i+k-l);
                    if(col<0) break;
                    sum+=gt(i,col,row,col);
                }
                ans = max(ans,sum);
                sum = 0;
                for(int l = 0;l<=k;l++)
                {
                    int col = j-l,row = max(0,i-k+l);
                    if(col<0) break;
                    sum+=gt(row,col,i,col);
                }
                ans = max(ans,sum);
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin >>T;
	while(T--){
		solve();
	}
}