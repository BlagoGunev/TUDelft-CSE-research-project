#include <bits/stdc++.h>

using namespace std;

#include <cstdio>
#include <cstring>
#include <cctype>

char str[300];
int cnt[1<<7];
int main(){
	fgets(str, sizeof(str), stdin);
	for (int i=0;str[i];i++){
		cnt[str[i]]++;
	}
	fgets(str, sizeof(str), stdin);
	for (int i=0;str[i];i++){
		if (isalpha(str[i]) && cnt[str[i]]-- ==0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}