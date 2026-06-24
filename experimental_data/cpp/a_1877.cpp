#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool f(ll a,ll b)
{
	return a>b;
}
int main()
{
	int mod = 1e9+7;
    int mod1 = 998244353;
	int T;
    cin>>T;
    //T = 1;
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
 	cout<<setprecision(19);
 	while(T-->0)
	{
        int n;
        cin>>n;
        int ar[n-1];
        int s = 0;
        for(int i=0;i<n-1;i++)
        {
            cin>>ar[i];
            s+=ar[i];
        }
        cout<<-s<<endl;
    }
}