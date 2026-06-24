#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll  long long int
#define pb push_back
#define IO ios::sync_with_stdio(false);
typedef vector<int> vi;
#define H return 0;
#define C continue;
#define B break;
#define sec second

int main()
{

int n,m;
cin>>n>>m;
bool a[m+1]={0};
int l,r;
for(int i=0;i<n;i++)
{
    cin>>l>>r;
    for(int j=l;j<=r;j++)
        a[j]=true;

}
vi ans;
int k=0;
for(int i=1;i<=m;i++)
{
    if(!a[i])
    {ans.pb(i);k++;}

}
cout<<k<<endl;
for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";

}