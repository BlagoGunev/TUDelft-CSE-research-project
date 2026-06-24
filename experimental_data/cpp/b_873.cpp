/*
* @FileName: D:\代码与算法\2017训练比赛\CF#873\b.cpp
* @Author: Pic
* @Created Time: 2017/10/12 22:42:46
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+30;
char str[maxn];
int l[maxn*2+30];
int main()
{
//	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int n;
	scanf("%d",&n);
	memset(l,-1,sizeof(l));
//	cin.getline(str,n+1);
	scanf("%s",str);
	int sum=0;
	int res=0;
	l[maxn]=0;
	for(int i=0;i<n;i++){
		if(str[i]=='1'){
			sum++;
		}	
		else{
			sum--;
		}
		if(sum==0){
			res=max(res,i+1);
		}
		else
		  	if(l[sum+maxn]==-1){
			l[sum+maxn]=i;
		}
		else{
			int len=i-l[sum+maxn];
			res=max(res,len);
		}
	}	
	if(sum==0) res=n;
	printf("%d\n",res);
	return 0;
}