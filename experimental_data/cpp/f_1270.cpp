//{{{ 
// BEGIN CUT HERE
 
 // END CUT HERE
 #include <cstdlib>
 #include <cctype>
 #include <cstring>
 #include <cstdio>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <iostream>
 #include <sstream>
 #include <map>
 #include <set>
 #include <queue>
 #include <stack>
 #include <fstream>
 #include <numeric>
 #include <iomanip>
 #include <bitset>
 #include <list>
 #include <stdexcept>
 #include <functional>
 #include <utility>
 #include <ctime>
 using namespace std;
 
 #define PB push_back
 #define MP make_pair
 
 #define REP(i,n) for(int i=0;i<(n);++i)
 #define FOR(i,l,h) for(int i=(l);i<=(h);++i)
 #define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define SORT(vec) sort(vec.begin(), vec.end())
 
 typedef vector<int> VI;
 typedef vector<string> VS;
 typedef vector<double> VD;
 typedef long long LL;
 typedef pair<int,int> PII;
 //}}}
 
const int mod=1000000007;;
const int maxn=200010;

char str[maxn];

int cnt[maxn*220];
int pos[maxn];
long long gao1(int len, int bei)
{
	int poscnt=0;
	int cur=maxn;
	cnt[cur]++;
	pos[poscnt++] = cur;
	REP(i, len)
	{
		if (str[i]=='0')
			cur--;
		else
			cur+=bei;
		if (cnt[cur]==0)
			pos[poscnt++]=cur;
		cnt[cur]++;
	}
	long long ret=0;
	REP(i, poscnt)
	{
		ret+=(cnt[pos[i]]-1ll)*cnt[pos[i]]/2;
		cnt[pos[i]]=0;
	}
	return ret;
}

long long gao2(int len, int minbei)
{
	pos[0]=-1;
	int cnt1=0;
	int minlen=0;
	int maxlen=0;
	long long ret=0;
	REP(i, len)
	{
		if (str[i]=='1')
		{
			cnt1++;
			pos[cnt1]=i;
		}
		for (int j=1;j<=cnt1 && j*minbei<=i+1;j++)
		{
			int p1 = pos[cnt1-j];
			int p2 = pos[cnt1-j+1];
			minlen = max(i-p2+1, j*minbei); 
			maxlen = i-p1;

			int yu=minlen%j;
			if (yu>0)
				minlen+=j-yu;
			if (maxlen>=minlen)
				ret+=(maxlen+j-minlen)/j;
		}
	}
	return ret;
}

long long gao(int len, int bei)
{
	long long ret=gao2(len, bei+2);
	//cout<<"gao2: "<<ret<<endl;
	for (int i=0;i<=bei;i++)
	{
		long long tmp=gao1(len, i);
		//printf("gao1:(%d): %lld\n", i, tmp);
		ret+=tmp;
	}
	return ret;
}

int main()
{
	scanf("%s", str);
	int len=strlen(str);
	cout<<gao(len, 200)<<endl;
}