#include <bits/stdc++.h>

using namespace std;

int n;

char s[51][51];

int main()

{

	scanf("%d",&n);

	for(int i=0;i<n;i++)

		scanf("%s",s[i]);

	for(int i=0;i<n;i++)

		for(int j=0;j<n;j++)

			if(s[i][j]!='0'&&(i&&j&&s[i-1][j-1]!='0')+(i&&j!=n-1&&s[i-1][j+1]!='0')

			+(i!=n-1&&j&&s[i+1][j-1]!='0')+(i!=n-1&&j!=n-1&&s[i+1][j+1]!='0')!=s[i][j]-'0')

			return puts("No"),0;

	puts("Yes");

}