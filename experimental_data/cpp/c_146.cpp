#include <iostream>



const int MAX_N = 100000+10;



char buf[2][MAX_N];



int main() {

	scanf("%s%s",buf[0],buf[1]);

	

	int cnt[2]={0,0};

	int ans=0;

	for(int i=0;buf[0][i]>0;++i) {

		if(buf[0][i]!=buf[1][i]) {

			if(buf[0][i]=='4') ++cnt[0];

			else ++cnt[1];

		}

	}

	printf("%d\n", cnt[0]>cnt[1]?cnt[0]:cnt[1]);

	return 0;

}