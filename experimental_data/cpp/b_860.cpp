#include<bits/stdc++.h>
using namespace std;
const int maxn=70010;

int n;


int son[maxn*9*5][10];
int dep[maxn*9*5];
pair<int,int> val[maxn*9*5];

int tot=0;
void insert(char *s,int len,int id,int st){
	int u=0;
	for(int i=0;i<len;i++){
		int c=s[i]-'0';
		if(!son[u][c]){
			son[u][c]=++tot;
			dep[son[u][c]]=dep[u]+1;
		}
		u=son[u][c];
		if(val[u].first==0){
			val[u].first=id;
			val[u].second=st;
		}else{
			if(val[u].first!=id)
				val[u].first=-1;
		}
	}
}
string s[maxn];
string ans[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char str[11];
		scanf("%s",str);
		s[i]=string(str);
		for(int j=0;j<9;j++){
			insert(str+j,9-j,i,j);
		}
	}
	for(int i=1;i<=tot;i++){
		if(val[i].first>0){
			int x=val[i].first;
			int st=val[i].second;
			int len=dep[i];
			if(ans[x]==""||ans[x].length()>len){
				ans[x]=s[x].substr(st,len);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		printf("%s\n",ans[i].c_str());
	return 0;
}