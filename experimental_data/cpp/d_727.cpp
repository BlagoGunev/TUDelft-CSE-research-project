#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

struct data

{

	int first,second,id;

};

char s[11];

int num[11];

int ans[100005];

int n;

int top;

data stk[100005];

void print(int x)

{

	if(x==1)puts("S");

	else if(x==2)puts("M");

	else if(x==3)puts("L");

	else if(x==4)puts("XL");

	else if(x==5)puts("XXL");

	else if(x==6)puts("XXXL");

}

int find_size(int x)

{

	if(s[x]=='S')return 1;

	if(s[x]=='M')return 2;

	if(s[x]=='L')return 3;

	if(s[x]=='X'&&s[x+1]=='L')return 4;

	if(s[x]=='X'&&s[x+2]=='L')return 5;

	if(s[x]=='X'&&s[x+3]=='L')return 6;

}

bool cmp(data x,data y){return x.first<y.first||(x.first==y.first&&x.second<y.second);}

int main()

{

	for(int i=1;i<=6;i++)scanf("%d",&num[i]);

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		scanf("%s",&s);

		bool flag=0;

		int pos;

		for(int j=0;s[j]!='\0';j++)if(s[j]==','){flag=1;pos=j+1;break;}

		if(!flag)

		{

			int temp=find_size(0);

			num[temp]--;

			ans[i]=temp;

			if(num[temp]<0)

			{

				puts("NO");

				return 0;

			}

		}

		else

		{

			top++;

			stk[top].id=i;

			stk[top].first=find_size(0);

			stk[top].second=find_size(pos);

		}

	}

	sort(stk+1,stk+top+1,cmp);

	//for(int i=1;i<=top;i++)printf("%d %d\n",stk[i].first,stk[i].second);

	for(int i=1;i<=top;i++)

	{

		if(num[stk[i].first]!=0)

		{

			num[stk[i].first]--;

			ans[stk[i].id]=stk[i].first;

		}

		else if(num[stk[i].second]==0)

		{

			puts("NO");

			return 0;

		}

		else

		{

			num[stk[i].second]--;

			ans[stk[i].id]=stk[i].second;

		}

	}

	puts("YES");

	for(int i=1;i<=n;i++)print(ans[i]);

}