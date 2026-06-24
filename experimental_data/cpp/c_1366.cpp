#include<bits/stdc++.h>
using namespace std;

namespace HABIT{
    #define f(a,b,c,d) for(register int a=b,c=d;a<=c;a++)
    #define g(a,b,c,d) for(register int a=b,c=d;a>=c;a--)
    #define LOCAL
    typedef int i32;
    typedef unsigned int u32;
    typedef long long int i64;
    typedef unsigned long long int u64;
    typedef pair<i32,i32> pii;
    const i32 MAXN=1024;
    typedef i32 ar[MAXN];
    
    template<typename T> inline T Max(T a) { return a; }
    template<typename T,typename... Args> inline T Max(T a,Args... args){
        T b=Max(args...);
        return (a>b)?a:b;
    }
    template<typename T> inline T Min(T a) { return a; }
    template<typename T,typename... Args> inline T Min(T a,Args... args){
        T b=Min(args...);
        return (a<b)?a:b;
    }

    #ifdef LOCAL
        inline char gc() { return getchar(); }
    #else
        inline char gc() {
            static char s[1<<20|1]={0},*p1=s,*p2=s;
            return (p1==p2)&&(p2=(p1=s)+fread(s,1,1<<20,stdin),p1==p2)?EOF:*(p1++);
        }
    #endif
    inline i64 read(){
        register i64 ans=0;register char c=gc();register bool neg=0;
        while(c<48||c>57) neg^=!(c^'-'),c=gc();
        while(c>=48&&c<=57) ans=(ans<<3)+(ans<<1)+(c^48),c=gc();
        return neg?-ans:ans;
    }

    char Output_Ans[1<<20|1],*Output_Cur=Output_Ans;
    inline void output() { Output_Cur-=fwrite(Output_Ans,1,Output_Cur-Output_Ans,stdout); }
    inline void print(char c){
        if(Output_Cur-Output_Ans+1>>20) output();
        *(Output_Cur++)=c;
    }
    inline void print(char *s) { while(*s) print( *(s++) ); }
    inline void print(u64 x){
        if(!x) { print('0'); return ; }
        char buf[30]={0},*p=buf+28;
        while(x) *(p--)=x%10+48,x/=10;
        print(p+1);
    }
    inline void print(u32 x) { print( (u64)x ); }
    inline void print(i64 x){
        if(x<0) print('-'),x=-x;
        print( (u64)x );
    }
    inline void print(i32 x){
        if(x<0) print('-'),x=-x;
        print( (u64)x );
    }
}
using namespace HABIT;

inline i64 ans(){
    i64 N=read(),M=read();
    i64 Cnt[64][2]={0};
    f(i,1,I,N)
        f(j,1,J,M)
            Cnt[i+j-1][read()]++;
    i64 Head=1,Tail=N+M-1,Ans=0;
    while(Head<Tail){
        if(Head==Tail){
            Ans+=Min(Cnt[Head][0],Cnt[Tail][0]);
        }
        else{
            i64 Cnt0=Cnt[Head][0]+Cnt[Tail][0];
            i64 Cnt1=Cnt[Head][1]+Cnt[Tail][1];
            Ans+=Min(Cnt0,Cnt1);
        }
        Head++,Tail--;
    }

    return Ans;
}

int main(){
    f(i,1,I,read()) print( ans() ),print('\n');
    output();
    return 0;
}