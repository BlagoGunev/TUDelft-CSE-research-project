/*input
4
3 10 1 2
7 14 3 8
20 70 2 7
5 6 1 1
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
    	long long m, n, p, q;
    	scanf("%lld %lld %lld %lld",&m,&n,&p,&q);
    	long long l = 0, r = 1000000007ll;
    	long long ans = -1;
    	while(l<=r)
    	{
    		long long mid = (l+r)/2;
    		// cout << l << " " << r << " " << mid << endl;
    		if(q*mid>=n && p*mid>=m && q*mid - n >= p*mid-m)
    		{
    			ans = mid;
    			r = mid - 1;
    		}
    		else l = mid + 1;

    	}
    	if(ans==-1) printf("%lld\n", ans);
    	else{
    		printf("%lld\n", q*ans - n);
    	}

    }
	return 0;
}