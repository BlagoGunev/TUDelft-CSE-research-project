#include<bits/stdc++.h>

#define mp make_pair

using namespace std;

int val[2][100032],k;

int n,arr[2][100002];

int func()

{

	queue<pair<pair<int,int>,int> >q;

	q.push(mp(mp(0,0),0));

	while(!q.empty())

	{

		int side=q.front().first.first,col=q.front().first.second,tim=q.front().second;

		if(col>=n)

		return 1;

		q.pop();

		if((arr[side][col+1]==1)&&(col+1>=tim+1)&&(val[side][col+1]>(tim+1))){

		q.push(mp(mp(side,col+1),tim+1));

		val[side][col+1]=tim+1;}

		if((arr[side][col-1]==1)&&(col-1>=tim+1)&&(val[side][col-1]>(tim+1))){

		q.push(mp(mp(side,col-1),tim+1));

		val[side][col-1]=tim+1;}

		if(col+k>=n)

		return 1;

		if((arr[side^1][col+k]==1)&&(col+k>=tim+1)&&(val[side^1][col+k]>(tim+1))){

		q.push(mp(mp(side^1,col+k),tim+1));

		val[side^1][col+k]=tim+1;}

	}

	return 0;

}

int main()

{

	char s[100022];

	int i,j;

	for(i=0;i<2;i++)

	{

		for(j=0;j<100002;j++)

		val[i][j]=9999999;

	}

	scanf("%d%d",&n,&k);

		scanf("%s",s);

	for(i=0;i<n;i++)

	{

		if(s[i]=='X')

		arr[0][i]=0;

		else

		arr[0][i]=1;

	}

		scanf("%s",s);

	for(i=0;i<n;i++)

	{

		if(s[i]=='X')

		arr[1][i]=0;

		else

		arr[1][i]=1;

	}

	int ans=func();

	if(ans)

	printf("YES");

	else

	printf("NO");

	return 0;

}