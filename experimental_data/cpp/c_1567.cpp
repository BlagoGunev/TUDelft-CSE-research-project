#include<bits/stdc++.h>

using namespace std;

int t;

long long s;

long long a,b; 

int rd(){

	int x=0;

	int f=1;

	char ch=getchar();

	while(!(ch>='0'&&ch<='9')){

		if(ch=='-'){

			f=-1;

		}

		ch=getchar();

	}

	while(ch<='9'&&ch>='0'){

		x=(x<<1)+(x<<3)+(ch^48);

		ch=getchar();

	}

	return x*f;

}

int main(){

//	freopen("genius.in","r",stdin);

//	freopen("genius.out","w",stdout);

	t=rd();

	while(t--){

		cin>>s;

		if(s==0){

			printf("0\n");

			continue;

		}

		int p[105],fl=0;

		while(s){

			p[++fl]=(s%10);

			s/=10;

		}

		

		a=0,b=0;

		for(int i=fl;i>=1;i--){

			if(i%2==1) a=(a*10)+p[i];

			else b=(b*10)+p[i];

		}

		

		long long ans=((a+1)*(b+1))-2;

		printf("%lld\n",ans);

		

	}



	return 0;

}