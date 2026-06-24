//Date & time of submission: Sorry, not during contest

#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
using namespace std;
const ll N=1e5+5;
ll t,n,m;
int main() {
	fio;
	cin>>t;
	while(t--)
	{
        cin>>n>>m;
        ll p=n*m;
        if(p&1)
        cout<<(p/2)+1;
        else
        cout<<p/2;
        cout<<"\n";
	}
	return 0;
}