#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

const int MAXN = 200 + 5;

const int mod = 998244353;



inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}



#define bbit(i) (1<<(i))

#define bdig(x,i) (((x)>>(i))&1)



int n;

char s[MAXN];



const int all = 2 * 2 * 3 * 3 * 3;

const int c_s1 = 2 * 3 * 3 * 3;

const int c_s2 = 3 * 3 * 3;

const int c_p0 = 3 * 3;

const int c_p1 = 3;



int encode(int s1,int s2,int p0,int p1,int p2)

{

	return s1 * c_s1 + s2 * c_s2 + p0 * c_p0 + p1 * c_p1 + p2;

}

void decode(int mask,int &s1,int &s2,int &p0,int &p1,int &p2)

{

	s1 = (mask / c_s1) % 2;

	s2 = (mask / c_s2) % 2;

	p0 = (mask / c_p0) % 3;

	p1 = (mask / c_p1) % 3;

	p2 = mask % 3;

}



bool iswin(int,int s2,int s3,int p)

{

	if(p == 2) return 0;

	if(p == 1) return s2 == s3;

	if(p == 0) return 1;

	return 0;

}



int getmask(int p0,int p1,int p2)

{

	vector<int> to(3), vis(3);

	to[0] = p0; to[1] = p1; to[2] = p2;

	

	int u = 0;

	for(int i=1; i<=20; ++i)

		++vis[u], u = to[u];

	

	int res = 0;

	for(int i=0; i<3; ++i)

		if(vis[i] > 1)

			res |= bbit(i);

	return res;

}



int dp[MAXN][MAXN * 2][all];

int ans[3];



void getres(int mask)

{

	s[n+1] = s[1]; s[n+2] = s[2];

	

	vector< vector< vector<pii> > > trans(all);

	for(int u=0; u<all; ++u)

	{

		trans[u].resize(2);

		for(int s3=0; s3<=1; ++s3)

		{

			int s1, s2, p0, p1, p2;

			decode(u, s1, s2, p0, p1, p2);

			

			int delta = 0, cur = s3 == 0? 1: -1;

			if(iswin(s1, s2, s3, p0)) p0 = 3, delta += bdig(mask,0) * cur;

			if(iswin(s1, s2, s3, p1)) p1 = 3, delta += bdig(mask,1) * cur;

			if(iswin(s1, s2, s3, p2)) p2 = 3, delta += bdig(mask,2) * cur;

			

			trans[u][s3].emplace_back(encode(s2, s3, p0-1, p1-1, p2-1), delta);

		}

	}

	

	memset(dp, 0, sizeof(dp));

	{

		int p0 = 0, beg = n;

		if(s[1] == s[2] && bdig(mask,0))

			beg += s[1] == 'a'? 1: -1;

		if(s[1] == s[2])

			p0 += 2;

		

		dp[2][beg][encode(s[1] - 'a', s[2] - 'a', p0, 1, 2)] = 1;

	}

	for(int i=3; i<=n+2; ++i)

		for(int c=0; c<=2*n; ++c)

			for(int u=0; u<all; ++u)

			{

				ll cur = dp[i-1][c][u];

				if(!cur) continue;

				

				for(int s3=0; s3<=1; ++s3)

				{

					if(s[i] != '?' && s[i]-'a' != s3) continue;

					for(auto t: trans[u][s3])

						add_mod(dp[i][c + t.second][t.first], cur);

				}

			}

	

	for(int c=0; c<=2*n; ++c)

		for(int u=0; u<all; ++u)

		{

			ll cur = dp[n+2][c][u];

			if(!cur) continue;

			

			int s1, s2, p0, p1, p2;

			decode(u, s1, s2, p0, p1, p2);

			

			if(getmask(p0, p1, p2) == mask)

			{

				add_mod(ans[c > n? 0: c == n? 1: 2], cur);

			}

		}

}



int main(void)

{

//	printf("%lf\n",(double)sizeof(dp) / sizeof(int));

	

	scanf("%s",s+1);

	n = strlen(s+1);

	

	if(n == 1)

	{

		if(s[1] == 'a')

			printf("1\n0\n0");

		else if(s[1] == 'b')

			printf("0\n0\n1");

		else

			printf("1\n0\n1");

		return 0;

	}

	

	for(int i=0; i<=1; ++i)

		for(int j=0; j<=1; ++j)

		{

			char s1 = s[1], s2 = s[2];

			if(s1 != '?' && s1 - 'a' != i) continue;

			if(s2 != '?' && s2 - 'a' != j) continue;

			

			s[1] = i + 'a'; s[2] = j + 'a';

			

			for(int mask=0; mask<8; ++mask)

				getres(mask);

			

			s[1] = s1; s[2] = s2;

		}

	

	for(int i=0; i<3; ++i)

		printf("%d\n",ans[i]);

	return 0;

}