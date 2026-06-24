#include <bits/stdc++.h>
using namespace std;
const int N = 500002;
int n;
int d[N],cnt[N];
long long prefix[N],suffix1[N],suffix2[N],val_suf[N];
bool valid[N];
vector<int> ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i <= n;i++)scanf("%d",&d[i]);
	sort(d,d + n + 1);
	for(int i=1;i <= n;i++) if(i < n + 1 - i)swap(d[i],d[n + 1 - i]);
	d[0] = n,d[n + 1] = -1;
	prefix[0] = 0;
	for(int i=1;i <= n;i++)prefix[i] = prefix[i - 1] + d[i];
	suffix1[n + 1] = suffix2[n + 1] = 0;
	for(int i=0;i <= n + 1;i++)cnt[i] = 0;
	long long e = 0;
	for(int i=n;i >= 1;i--){
		suffix1[i] = suffix1[i + 1] + min(i + 1,d[i]),cnt[min(i + 1,d[i])]++;
		suffix1[i] -= cnt[i + 1],cnt[i] += cnt[i + 1];
		e += d[i];
	}
	for(int i=0;i <= n + 1;i++)cnt[i] = 0;
	for(int i=n;i >= 1;i--){
		suffix2[i] = suffix2[i + 1] + min(i,d[i]),cnt[min(i,d[i])]++;
		suffix2[i] -= cnt[i],cnt[i - 1] += cnt[i];
	}
	val_suf[n + 1] = n + 1;
	for(int i=n;i >= 1;i--){
		val_suf[i] = val_suf[i + 1];
		val_suf[i] = min(val_suf[i],1ll * (i + 1) * i + suffix1[i + 1] - prefix[i]);
	}
	valid[0] = true;
	for(int i=1;i <= n;i++){
		valid[i] = valid[i - 1];
		if(prefix[i] > 1ll * (i + 1) * i + suffix2[i + 1])valid[i] = false;
	}
	long long mx = 0ll;
	for(int i=0;i <= n;i++){
		for(int j=d[i];j > d[i + 1];j--){
			bool flag = true;
			if(j < i)mx = max(mx,prefix[i] - 1ll * i * (i - 1) - suffix2[i + 1]);
			if((e + j) & 1)flag = false;
			if(j > val_suf[i + 1])flag = false;
			if(prefix[i] + j > 1ll * i * (i + 1) + suffix1[i + 1])flag = false;
			if(j < mx)flag = false;
			if(!valid[min(i,j)])flag = false;
			if(flag)ans.push_back(j);
			if(j && j <= i)mx = max(mx,prefix[j] - 1ll * j * (j - 1) - suffix2[j + 1]);
		}
	}
	if(!ans.size())printf("-1\n");
	else{
		for(int i=ans.size() - 1;i >= 0;i--)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}