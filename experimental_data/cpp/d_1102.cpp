#define IO std::ios::sync_with_stdio(0) 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[300005];
int a[3],b[3];
int main(){
	cin>>n;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='0')a[0]++;
		else if(s[i]=='1')a[1]++;
		else a[2]++;
	}
	int m=n/3;
	for(int i=1;i<=n;i++){
		int v=s[i]-'0';
		b[v]++;
		if(v==0){
			if(a[0]>m&&b[0]>m){
				a[0]--;
				if(a[1]<m){
					s[i]='1';
					a[1]++;
					b[1]++;
				}
				else if(a[2]<m){
					s[i]='2';
					a[2]++;
					b[2]++;
				}
			}
		}
		else if(v==1){
			if(a[1]>m){
				if(a[0]<m){
					a[1]--;
					s[i]='0';
					a[0]++;
					b[1]--;
				}
				else if(a[2]<m&&b[1]>m){
					a[1]--;
					s[i]='2';
					a[2]++;
				}
			}
		}
		else{
			if(a[2]>m){
				a[2]--;
				if(a[0]<m){
					s[i]='0';
					a[0]++;
				}
				else if(a[1]<m){
					s[i]='1';
					a[1]++;
				}
			}
		}
	}
	printf("%s\n",s+1);
	/*int m=n/3;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			if(b[0]<m){
				b[0]++;
				printf("0");
			}
			else if(b[1]<m){
				b[1]++;
				printf("1");
			}
			else if(b[2]<m){
				b[2]++;
				printf("2");
			}
		}
		else if(s[i]=='1'){
			if(a[1]>m){
				if()
			}
		}
	}*/
}