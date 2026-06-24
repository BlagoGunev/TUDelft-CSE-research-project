#include<bits/stdc++.h>

#define rg register

#define il inline

typedef long long ll;

using namespace std;

char str[1000100];

il bool f(char* str, int start, int n) {

	for (rg int i=0;i<n/2;i++) {

		if (str[start+i] != str[start+n-1-i]) return false;

	}

	return true;

}



int main() {

	rg int t;

	scanf("%d", &t);

	while(t--){

		scanf("%s", str);

		rg int len =strlen(str);

//		for(int i=0;i<=len-1;i++){

//			fan[i]=str[len-i-1];

//		}

//		for(int i=0;i<=len-1;i++){

//			cout<<fan[i]<<" \n"[i==n];

//		}

		int now = 0;

		for (rg int i = 0; i < len / 2; i++) {

			if (str[i] == str[len - 1 - i])now++;

			else break;

		}

		int l = 0, r = 0;

		for (rg int i = now; i <=len-now-1; i++) {

			int dl=i-now+1;

			if (f(str,now,dl)) {

				l=dl;

			}

		}

		for (rg int i=len-now-1;i>=now;i--){

			int dr=len-now-i;

			if (f(str,i,dr)){

				r=dr;

			}

		}

		if (l>=r){

			for(rg int i=0;i<=now+l-1;i++){

				putchar(str[i]);

			}

			for(rg int i=len-now;i<len;i++){

				putchar(str[i]);

			}

		}

		else {

			for (rg int i=0;i<now;i++) {

				putchar(str[i]);

			}

			for (rg int i=len-now-r;i<len;i++) {

				putchar(str[i]);

			}

		}

		puts("");

	}

}