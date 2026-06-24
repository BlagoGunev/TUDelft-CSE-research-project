#include<bits/stdc++.h>
#define MST(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i = a ; i < b ; ++i)
#define per(i,a,b) for(int i = a ; i > b ; --i)
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
template<class T> void show(T *x,int len,int s = 0) {for(int i = s ; i < s+len-1 ; ++i) cout << x[i] << ' ';cout << x[s+len-1] << endl;}
void debug() {cerr << endl;}
template <typename T, typename... Args> void debug(T x,Args... args) {cerr << x << ' ';debug(args...);}

const int maxbuff = 1<<17;
char ibuff[maxbuff],obuff[maxbuff];
inline char Getchar(){
    static char *p1=ibuff,*p2=ibuff;
    if(p1 == p2) {
    	p1 = ibuff;
    	p2 = ibuff+fread(ibuff,1,maxbuff,stdin);
    	if(p1 == p2) return -1;
    }
    return *p1++;
}

int optr = 0;
inline void Putchar(char c) {
	if(optr == maxbuff) {fwrite(obuff,1,optr,stdout);optr = 0;}
	obuff[optr++] = c;
}

inline void Flush() {
	fwrite(obuff,1,optr,stdout);
}

template<class T>
	inline int read(T &x) {
		x = 0;
		char c = Getchar();
		if(c == EOF) return -1;
		for( ; c < '0' || c > '9' ; c = Getchar());
		for( ; c >= '0' && c <= '9' ; c = Getchar()) x = x*10+c-'0';
		return 0;
	}

template<class T>
	inline void write(const T &x,int tag = 0) {
		if(!x) {
			if(!tag) Putchar(x+'0');
			return ;
		}
		write(x/10,1);
		Putchar(x%10+'0');
	}
	
template<class T>
	inline void writeln(const T &x) {
		write(x);Putchar('\n');
	}

template<class T>
	inline void writesp(const T &x) {
		write(x);Putchar(' ');
	}
	
template<class T>
inline void cmin(T &A,const T &B) {A = (A<B?A:B);}
template<class T>
inline void cmax(T &A,const T &B) {A = (A>B?A:B);}
#define int LL
int n,m;

signed main() {
	read(n);read(m);
	int now = 0,pre = 0,x;
	rep(i,0,n) {
		read(x);
		now += x;
		writesp(now/m-pre);
		pre = now/m;
	}
	Flush();
	return 0;
}