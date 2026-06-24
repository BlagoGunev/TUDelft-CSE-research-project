#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define k5 100005

int n;

int fs[k5];
int bs[k5];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &fs[i], &bs[i]);
		if(bs[i]==fs[i]){bs[i] = -1;};
	}
	unsigned int ans=0;
	ans--;
	unsigned int ned = (n+1)/2;
	sort(fs, fs+n);
	sort(bs, bs+n);
	fs[n]=-2;
	bs[n]=-3;
	int fid = 0;
	int bid = 0;
	while(bid<n && bs[bid]==-1)bid++;
	while(fid < n)
	{
		int fc = fs[fid];
		int bc = bs[bid];
		unsigned int cntf=0;
		while(fs[fid]==fc){cntf++;fid++;}

		while(bs[bid]<fc){
			if(bid>=n)break;
			unsigned int c2=0;
			int tbc=bs[bid];
			while(bs[bid]==tbc){c2++;bid++;};

			if(c2>=ned)ans = min(ans, ned);
		}
		int cntb=0;
		if(fc == bs[bid]){
			while(bs[bid]==fc){cntb++; bid++;};
		}
		if(cntf>= ned)ans = 0;
		else if(cntf + cntb >= ned){
			ans = min(ans, ned-cntf);
		}
	}
	while(bid < n){
		unsigned int cnt = 0;
		int cl = bs[bid];
		while(bs[bid]==cl){cnt++; bid++;}
		if(cnt>=ned)ans = min(ans, ned);
	}	

	printf("%d\n", ans);

	return 0;
}