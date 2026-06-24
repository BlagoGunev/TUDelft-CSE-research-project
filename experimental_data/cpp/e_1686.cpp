#include <bits/stdc++.h>

using namespace std;

#define M 400005

#define ri register int 



template <class G> void read(G &x)

{

	x=0;int f=0;char ch=getchar();

	while(ch<'0'||ch>'9'){f|=ch=='-';ch=getchar();}

	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}

	x=f?-x:x;

	return ;

}





int t;

int n;

long long arr[M];

int main(){

	ios::sync_with_stdio(false);

  cin.tie(0);

	cin>>t;

	while(t--)

	{

		cin>>n;

		n*=2;

		string s;

		cin>>s;

		vector<int>p(n+1);

		int mx=1;

		for(ri i=0;i<s.length();i++)

		{

			if(s[i]=='(') p[i+1]=1;

			else p[i+1]=-1;

			arr[i+1]=arr[i]+p[i+1];

		    if(arr[mx]<arr[i+1]) mx=i+1;

		}

		int flag=1;

		for(ri i=1;i<=n;i++)

		{

			if(arr[i]<0) 

			{

				flag=0;break;

			}

		}

		if(flag)

		{

			printf("0\n");

			continue;

		}

		int l=0,r=0;

		for(ri i=1;i<=n;i++)

		{

			if(arr[i]<0)

			{

				l=i; break; 

			}

		}

		for(ri i=n;i>=1;i--)

		{

			if(arr[i]<0)

			{

				r=i; break; 

			}

		}

		r++;

		int tmp=l;

		for(ri i=0;i<=tmp;i++)

		{

			if(arr[i]>arr[l]) l=i;

		}

		tmp=r;

		for(ri i=tmp+1;i<=n;i++)

		{

			if(arr[i]>arr[r]) r=i;

		}

		l++;

		reverse(s.begin()+l-1,s.begin()+r+1-1);

	    flag=1;

		for(ri i=0;i<s.length();i++)

		{

			if(s[i]=='(') p[i+1]=1;

			else p[i+1]=-1;

			arr[i+1]=arr[i]+p[i+1];

			if(arr[i+1]<0) 

			{

				flag=0;break;

			}

		}

		if(flag)

		{

			printf("1\n");

			printf("%d %d\n",l,r);

			continue;

		}

		printf("2\n");

		printf("1 %d %d %d\n",mx,mx+1,n);

	}

	return 0;

	

}