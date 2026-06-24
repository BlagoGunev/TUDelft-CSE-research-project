// Problem      : D. Playoff Tournament
// From         : Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL          : https://codeforces.com/contest/1535/problem/D
// Memory Limit : 256 MB
// Time Limit   : 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

#define FREAD_OPTION

#ifdef FREAD_OPTION
	#define MAXBUFFERSIZE 1000000
	inline char fgetc(){
	    static char buf[MAXBUFFERSIZE+5],*p1=buf,*p2=buf;
	    return p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXBUFFERSIZE,stdin),p1==p2)?EOF:*p1++;
	}
	#undef MAXBUFFERSIZE
	#define gc fgetc
#else
	#define gc getchar
#endif 
struct IOReader{
	template<typename T>
	inline IOReader& operator >> (T& a){
		 a=0;bool flg=false;
		char ch=gc();
		while(ch<'0' || ch>'9'){if(ch=='-')	flg^=1;ch=gc();}
		while(ch>='0' && ch<='9'){a=(a<<3)+(a<<1)+(ch^'0');ch=gc();}
		if(flg)	a=-a;
		return *this;
	}
	inline IOReader& operator >> (string& a){
		a.clear();char ch=gc();
		while(isspace(ch) && ch!=EOF)	ch=gc();
		while(!isspace(ch) && ch!=EOF)	a+=ch,ch=gc();
		return *this;
	}
	inline IOReader& operator >> (char* a){
		#ifdef FREAD_OPTION
			char ch=gc();
			while(isspace(ch) && ch!=EOF)	ch=gc();
			while(!isspace(ch) && ch!=EOF)	*(a++)=ch,ch=gc();
			*a='\0';
		#else
			scanf(" %s",a);
		#endif
		return *this;
	}
	inline IOReader& operator >> (char &a){
		a=gc();
		while(isspace(a))	a=gc();
		return *this;
	}
	#define importRealReader(type) inline IOReader& operator >> (type& a){\
		a=0;bool flg=false;char ch=gc();\
		while((ch<'0' || ch>'9') && ch!='.'){if(ch=='-')flg^=1;ch=gc();}\
		while(ch>='0' && ch<='9'){a=a*10+(ch^'0');ch=gc();}\
		if(ch=='.'){\
			ch=gc();type p=0.1;\
			while(ch>='0' && ch<='9'){a+=p*(ch^'0');ch=gc();p*=0.1;}\
		}\
		if(flg)	a=-a;return *this;\
	}
	importRealReader(float)
	importRealReader(double)
	importRealReader(long double)
	#undef importRealReader
}iocin;
#define importReadInteger(type, name) type name(){type a=0;bool flg=false;char ch=gc();while(ch<'0' || ch>'9'){if(ch=='-')	flg^=1;ch=gc();}while(ch>='0' && ch<='9'){a=(a<<3)+(a<<1)+(ch^'0');ch=gc();}if(flg)	a=-a;return a;}
importReadInteger(int, readInt)
importReadInteger(unsigned int, readUInt)
importReadInteger(long long, readLL)
importReadInteger(unsigned long long, readULL)
importReadInteger(short, readShort)
importReadInteger(unsigned short, readUShort)
#undef importReadInteger
#define importReadDecimal(type, name) type name(){type a=0;bool flg=false;char ch=gc();while((ch<'0' || ch>'9') && ch!='.'){if(ch=='-')flg^=1;ch=gc();}while(ch>='0' && ch<='9'){a=a*10+(ch^'0');ch=gc();}if(ch=='.'){ch=gc();type p=0.1;while(ch>='0' && ch<='9'){a+=p*(ch^'0');ch=gc();p*=0.1;}}if(flg) a=-a;return a;}
importReadDecimal(float, readFL)
importReadDecimal(double, readDB)
importReadDecimal(long double, readLDB)
#undef importReadDecimal

#define readI(l,r,A) for(int tiger2005=l;tiger2005<=r;tiger2005++)	iocin >> A[tiger2005]
#define outA(l,r,A,sp)	for(int tiger2005=l;tiger2005<=r;tiger2005++)	printf(sp,A[tiger2005])
#define pdYes printf("Yes\n")
#define pdNo printf("No\n")
#define pdYES printf("YES\n")
#define pdNO printf("NO\n")
#define pdyes printf("yes\n")
#define pdno printf("no\n")
#define openFile(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout)
#define closeFile() fclose(stdin),fclose(stdout)
#undef gc
int N, M;
char str[600010];
int sm[600010];
inline void calc(int x){
	if(str[x]=='0')	sm[x]=sm[(x<<1)+1];
	if(str[x]=='1')	sm[x]=sm[x<<1];
	if(str[x]=='?')	sm[x]=sm[(x<<1)+1]+sm[x<<1];
}
int main(){
	iocin >> N;
	M = (1 << N) - 1;
	iocin >> (str+1);
	for(int i=M+1;i<=2*M+2;i++)	sm[i]=1;
	for(int i=1;i*2<=M;i++)
		swap(str[i],str[M+1-i]);
	for(int i=M;i;i--)	calc(i);
	int x, Q=readInt();char ch;
	while(Q--){
		iocin >> x >> ch;
		x = M+1-x;
		str[x]=ch;
		while(x!=0)	calc(x),x>>=1;
		printf("%d\n",sm[1]);
	}
	return 0;
}