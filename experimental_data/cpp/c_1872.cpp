/*
 *                                                     __----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          __--~ ~~
 *                    -.            \_|//     |||\\  ~~~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \\            _/~~-
 *         __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
 *     _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \\ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       __--~~
 *                       |-~~-_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-~~____--~-/                  ~~==.
 *                       ((->/~   '.|||' -_|    ~~-/ ,              . _||
 *                                  -_     ~\      ~~---l__i__i__i--~~_/
 *                                  _-~-__   ~)  \--______________--~~
 *                                //.-~~~-~_--~- |-------~~~~~~~~
 *                                       //.-~~~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               神兽保佑            永无BUG
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<bitset>
#include<ctime>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#define int long long
#define endl '\n'
#define debug(a) cout<<#a<<"="<<a<<endl;
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> pir;
const double pi=acos(-1);
const LL mod=998244353;
const LL inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int maxn=1e6+5;
int a[maxn];
void Solve()
{
 	int l,r;
 	cin>>l>>r;
 	int k=(l+1)/2;
 	for(int i=l;i<=min(r,l+10);i++)
 	{
 		for(int j=2;j*j<=i;j++)
 		{
 			if(i%j==0)
 			{
 				cout<<j<<" "<<i-j<<endl;
 				return;
			}
		}
	}
	cout<<-1<<endl;
	return;
}
signed main()
{
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	 	Solve();
		/*
		if(Solve()) cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
		*/
	}
	//Solve();
	return 0;
}