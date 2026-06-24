#define maxn 60

#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;


int c[maxn];
long long a[10][maxn];
int n=0;
long long sum,mn=1;
char x;
string s;

int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	getline(cin,s);
	n=int(s.size());
	for (int i=0; i<n; i++) c[i]=s[i]-'0';
	memset(a,0,sizeof(a));
	for (int i=0; i<10; i++) a[i][n-1]=1;
	for (int j=n-2; j>=0; j--)
		for (int i=0; i<10; i++){
			if ((i+c[j+1])%2!=0) a[i][j]+=a[(i+c[j+1])/2+1][j+1];
			a[i][j]+=a[(i+c[j+1])/2][j+1];
		}
	/*for (int i=0; i<10; i++){
		for (int j=0; j<n; j++) printf("%d ",a[i][j]);
		printf("\n");
	}*/
	sum=0;
	for (int i=0; i<10; i++) 
		sum+=a[i][0];
	mn=1;
	for (int i=0; i<n-1; i++) 
		if (abs(c[i]-c[i+1])>1) mn=0;
	//printf("%d",sum-mn);
	cout << (sum-mn);
}