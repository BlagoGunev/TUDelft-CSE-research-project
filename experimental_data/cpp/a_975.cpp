#include<cstdio>
#include<set>

using namespace std;

const int N=1005;
int n;
char s[N];

int main()
{
	int i,j;
	
	scanf("%d",&n);
	set<int> st;
	while(n--) {
		scanf("%s",s);
		j=0;
		for(i=0;s[i];i++) j|=1<<(s[i]-'a');
		st.insert(j);
	}
	printf("%d",(int)st.size());
	return 0;
}