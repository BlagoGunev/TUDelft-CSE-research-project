#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<iterator>
#include<functional>
#include<ctime>
#include<iomanip>
#include<cmath>
#include<algorithm>
#define P pair<int, int>
using namespace std;

typedef long long ll;
typedef double db;

const int N=201000;

int a[N], cnt[N];

int main(){
	int n, s, kol=0, ans, p=1;
	cin>>n>>s; s--;
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(int i=0; i<n; i++){
		if(a[i]==0 && i!=s)
			kol++;
	}
	ans=kol;

	if(a[s]!=0){ a[s]=0; ans++; }

	for(int i=0; i<n; i++)
		if(a[i]!=0) cnt[a[i]]++;

	for(int i=1; kol>0; i++){
		if(cnt[i]==0){
			kol--; cnt[i]=1;
		}
	}

	for(int i=1; i<N; i++)
		if(cnt[i]) p=i;

	for(int i=1; i<p; i++)
		kol+=(cnt[i]==0);

	for(int i=1; i<=p && kol; i++){
		if(cnt[i]==0){
			kol--; ans++;
			cnt[i]=1; cnt[p]--;
			if(!cnt[p]) p--;
			while(!cnt[p]){
				p--; kol--;
			}
		}
	}
	printf("%d", ans);
}