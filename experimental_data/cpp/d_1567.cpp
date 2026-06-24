#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 3e5+10;

const int mod = 998244353;

int t,n,s,bit[109],ans[109],a[109];

void fenjie(int x)

{

	memset( a,0,sizeof a );

	while( x )

		a[++a[0]] = x%10, x /= 10;

	return;

}

signed main()

{

	ios::sync_with_stdio( false );

    cin >> t;

    while( t-- )

    {

        cin >> s >> n;

        /*

        n个数字相加等于10

		解释为十进制时,相加和最小 

		分配在第一位,第二位,第三位....... 

		总共至少需要有n个1才行

		每一位的1不多于9n个 

        */

        memset( ans,0,sizeof ans ); memset( bit,0,sizeof bit );

        fenjie( s );

        int base = 1, now = 0;

        for(int i=1;i<a[0];i++)	base *= 10;

        for(int i=a[0];i>=1;i--)

        {

        	for(int j=9*n;j>=0;j--)

        	{

        		int val = j*base;

        		if( val>s )	continue;

        		if( s-val+now+j<n )	continue;

        		bit[i] = j, s -= val; now += j; 

        		break;

			}

			base /= 10;

		}

		for(int i=1;i<=n;i++)

		{

			int base = 1;

			for(int j=1;j<=a[0];j++)

			{

				if( !bit[j] )	base *= 10;

				else

				{

					bit[j]--; ans[i] += base;

					break;

				}

			}

		}

		for(int i=1;i<=n;i++)

		{

			int base = 1;

			for(int j=1;j<=a[0];j++)

			{

				int x = min( 9ll,bit[j] );

				bit[j] -= x; ans[i] += x*base; base *= 10;

			}

		}

		for(int i=1;i<=n;i++)	cout << ans[i] << " ";

		for(int i=1;i<=n;i++)	ans[i] = 0;

		cout << endl;

    }

}