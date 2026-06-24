#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef orewabaka
    #define f first
    #define s second
    #define vse(a) a.begin(), a.end()
    #define ovse(a) a.rbegin(), a.rend()
    #define pb push_back
    #define endl aut '\n'
    #define ar vector
    #define var auto
    #define rand() (((rand()<<15)+rand())&INT32_MAX)
    #define ain cin,
    #define aut cout,
    #define $(a) (i32)a.size()
    #define in insert
    #define fusrodah return

    typedef int i32;
    typedef unsigned u32;
    typedef long long i64;
    typedef unsigned long long u64;
    typedef pair<i32, i32> p32;
    typedef pair<i64, i64> p64;
    typedef double lf;
    typedef tree<i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

    namespace shyutsuryoku{
        const i32 STRSZ=3e6+13;
        char inbufer[STRSZ];
        inline void cscan(string& i){
            i32 c=getc(stdin), cnt=0;while(c<=32)c=getc(stdin);
            while(c>32)*(inbufer+cnt)=c,c=getc(stdin),++cnt;
            *(cnt+inbufer)=0;i=inbufer;
        }
        inline void cprint(string& i){
            char *s=new char[i.size()+1]; 
            strcpy(s, i.c_str());
            while(*s)putchar(*s), s++;
        }
        inline void cprint(const char*& i){
            i32 cnt=0;
            while(*(i+cnt))putc(*(i+cnt), stdout),cnt++;
        }
        inline void cscan(i32&i){
            i=0;i32 c=getc(stdin), b=0;while(c<=32)c=getc(stdin);if(c=='-')b=1, c=getc(stdin);
            while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
            if(b)i=-i;
        }
        inline void cprint(i32 i){
            if(i<0)putc('-',stdout),i=-i;
            i32 sz=0;char ans[12];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
            while(sz--)putc(ans[sz],stdout);
        }
        inline void cscan(i64&i){
            i=0;i32 c=getc(stdin), b=1;while(c<=32)c=getc(stdin);if(c=='-')b=-1,c=getc(stdin);
            while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
            i*=b;
        }
        inline void cprint(i64 i){
            if(i<0)putc('-',stdout),i=-i;
            i32 sz=0;char ans[21];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
            while(sz--)putc(ans[sz],stdout);
        }
        inline void cscan(u32&i){
            i=0;i32 c=getc(stdin);while(c<=32)c=getc(stdin);
            while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
        }
        inline void cprint(u32 i){
            i32 sz=0;char ans[12];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
            while(sz--)putc(ans[sz],stdout);
        }
        inline void cscan(u64&i){
            i=0;i32 c=getc(stdin);while(c<=32)c=getc(stdin);
            while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
        }
        inline void cprint(u64 i){
            i32 sz=0;char ans[21];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
            while(sz--)putc(ans[sz],stdout);
        }
        inline void cscan(lf&i){
            scanf("%lf", &i);
        }
        inline void cprint(lf i){
            printf("%.10lf", i);
        }
        inline void cprint(char i){
            putc(i, stdout);
        }
        inline void cscan(char&i){
            i32 b=getc(stdin);
            while(b<=32)b=getc(stdin);
            i=b;
        }
        template<class T, class K>inline void cscan(pair<T, K>& i){
            cscan(i.f);cscan(i.s);
        }
        template<class T, class K>inline void cprint(pair<T, K>& i){
            cprint('(');cprint(i.f);cprint(' ');cprint(i.s);cprint(')');
        }
        template<class T>inline void cscan(ar<T>& i){
            for(var& j:i)cscan(j);
        }
        template<class T>inline void cprint(ar<T>& i){
            for(var& j:i)cprint(j), cprint(' ');
        }
        template<class T>inline void cprint(ar<ar<T> >& i){
            for(var& j:i)cprint(j), cprint('\n');
        }
        template<class T>ostream &operator,(ostream &os, T v){
            cprint(v);
            return os;
        }
        template<class T>istream &operator,(istream &is, T &v) {
            cscan(v);
            return is;
        }
    }
    using namespace shyutsuryoku;
#endif

void AnimeConservativeRevolution();

i32 main(){
    #ifdef home
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    srand(time(0));
    AnimeConservativeRevolution();
    #ifdef home
        aut '\n', (lf)clock()/CLOCKS_PER_SEC, " 秒\n";
    #endif
    fusrodah 0;
}

void AnimeConservativeRevolution(){
    i64 n, q;
    ain n, q;
    deque<i64> d;
    i64 mx=-1;
    for(i64 i=0;i<n;i++){
        i64 v;
        ain v;
        mx=max(v, mx);
        d.pb(v);
    }
    ar<p64> z(q), ans(q);
    for(i64 i=0;i<q;i++){
        ain z[i].f;
        z[i].s=i;
    }
    sort(vse(z));
    i64 i=1, ind=0;
    while(d.front()!=mx){
        i64 a=d.front();
        d.pop_front();
        i64 b=d.front();
        d.pop_front();
        while(ind<q&&z[ind].f==i){
            ans[z[ind].s].f=a;
            ans[z[ind].s].s=b;
            ind++;
        }
        d.push_front(max(a, b));
        d.pb(min(a, b));
        i++;
    }
    ar<i64> buf(n);
    for(i64 j=0;j<n;j++){
        buf[j]=d.front();
        d.pop_front();
    }
    for(i64 j=ind;j<q;j++){
        ans[z[j].s].f=mx;
        ans[z[j].s].s=buf[(z[j].f-i)%(n-1)+1];
    }
    for(var i:ans){
        aut i.f, ' ', i.s, '\n';
    }
}