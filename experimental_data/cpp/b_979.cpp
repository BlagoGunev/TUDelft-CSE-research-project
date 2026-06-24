#include <bits/stdc++.h>
using namespace std;
int cnt[55],maxn[3],num[3],maxx;
int main()
{
	int n;
	cin>>n;
	char c = getchar();
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<52; j++)
			cnt[j] = 0;
		maxn[i] = 0;
		c = getchar();
		while (c!='\n')
		{
			num[i]++;
			if (c>='a' && c<='z')
				cnt[c-'a'] ++;
			else cnt[c-'A'+26] ++;
			c = getchar();
		}

		for (int j = 0; j<52; j++)
			if (cnt[j] > maxn[i])
				maxn[i] = cnt[j];
	}
	for (int i = 0; i<3; i++)
		if (maxn[i]==num[i] && n==1)
			maxx=max(--maxn[i] ,maxx);
		else if (maxn[i] + n <= num[i])
			maxx=max((maxn[i] += n),maxx);
		else maxx=max((maxn[i]=num[i]),maxx) ;

	if (maxx==maxn[0] && maxx>maxn[1] && maxx>maxn[2])
		cout<<"Kuro"<<endl;
	else if (maxx==maxn[1] && maxx>maxn[0] && maxx>maxn[2])
		cout<<"Shiro"<<endl;
	else if (maxx==maxn[2] && maxx>maxn[0] && maxx>maxn[1])
		cout<<"Katie"<<endl;
	else cout<<"Draw"<<endl;
}