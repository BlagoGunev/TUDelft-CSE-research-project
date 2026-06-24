#include<iostream>
using namespace std;
const int N = 4e6+5;
int nums[105];
int dp[N] = {0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, sum = 0;
	cin >> n;
	for(int i=0; i<n; i++) cin >> nums[i], sum += nums[i];
	if(sum&1) cout << 0 << endl;
	else
	{
		sum /= 2;
		dp[0] = 1; 
		for(int i=0; i<=n; i++)
			for(int j=sum; j>=nums[i]; j--)
				dp[j] = dp[j-nums[i]] | dp[j];
		if(!dp[sum]) cout << 0 << endl;
		else
			while(1)
				for(int i=0; i<n; i++)
				{
					if(nums[i]&1)
					{
						cout << 1 << "\n" << i+1 << endl;
						return 0;
					}
					nums[i] /= 2;
				}
	}
	return 0;
}