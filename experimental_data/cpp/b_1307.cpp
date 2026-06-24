#include<bits/stdc++.h>

#define WDNMDYPDLNMDB 1

using namespace std;

namespace IO
{
    static char buf[1<<20],*fs,*ft;
    inline char gc()
    {
        if(fs==ft)
        {
			ft=(fs=buf)+fread(buf,1,1<<20,stdin);
			if(fs==ft)return EOF;
        }
        return *fs++;
    }
    #define gc() getchar()
	inline long long read()
	{
		long long x=0,f=1;char s=gc();
		while(s<'0'||s>'9'){if(s=='-')f=-f;s=gc();}
		while(s>='0'&&s<='9'){x=x*10+s-'0';s=gc();}
		return x*f;
	}
}using IO::read;

int main() {
	long long cnm,nmsl,wdnmd,ljwy,smg;

	long long T;
	T = read();
	while (T --) {
		long long Max = 0, opt = 0;WDNMDYPDLNMDB;
		long long n, x;WDNMDYPDLNMDB;
		n = read(), x = read();WDNMDYPDLNMDB;
		for (int i = 1; i <= n; ++ i) {
			long long M;WDNMDYPDLNMDB;
			M = read();WDNMDYPDLNMDB;
			Max = max(Max, M);WDNMDYPDLNMDB;
			if (x == M) opt = 1;WDNMDYPDLNMDB;
		}
		if (opt == 1)
			printf("1\n");
		else if (Max > x)
			printf("2\n");
		else if (! (x % Max))
			printf("%lld\n", x / Max);
		else
			printf("%lld\n", x / Max + 1);
			WDNMDYPDLNMDB;
			WDNMDYPDLNMDB;
			WDNMDYPDLNMDB;
			WDNMDYPDLNMDB;
			WDNMDYPDLNMDB;
			WDNMDYPDLNMDB;
	}
	return 0;
}