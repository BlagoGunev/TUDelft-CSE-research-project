//Generated at 2020-02-23 18:16:04 UTC+8
//Created by Alphagocc
#include<bits/stdc++.h>
#ifdef USE_PBDS
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#endif
#define FORCE_INLINE __inline__ __attribute__((always_inline))
class IO
{
static const int bufSize=1<<18;char inBuf[bufSize],outBuf[bufSize];char*ip1=inBuf,*ip2=inBuf;int goodReadBit=0,op1=-1,op2=bufSize-1;
template <typename T>FORCE_INLINE void __RI(T&x){int ch=gc(),neg=1;x=0;for(;!(isdigit(ch)||ch=='-'||ch==EOF);ch=gc());if(ch==EOF){goodReadBit=0;return;}if(ch=='-')neg=-1,ch=gc();for(;isdigit(ch);ch=gc())x=x * 10 +(ch - 48) * neg;}
template <typename T>FORCE_INLINE void __RC(T&x){unsigned char ch;while(isspace(ch=gc()));x=ch;}
FORCE_INLINE void __RS(std::string&x){char ch;x.clear();for(ch=gc();isspace(ch);ch=gc());if(ch==EOF){goodReadBit=0;return;}for(;!isspace(ch);ch=gc())x.push_back(ch);}
public:
FORCE_INLINE int gc(){return ip1==ip2 &&(ip2 =(ip1=inBuf)+fread(inBuf,1,bufSize,stdin),ip1==ip2)? EOF: *ip1++;}
FORCE_INLINE void R(char&x){__RC(x);}FORCE_INLINE void R(unsigned char&x){__RC(x);}FORCE_INLINE void R(std::string&x){__RS(x);}
template <typename T1,typename T2>FORCE_INLINE void R(std::pair<T1,T2>&x){R(x.first),R(x.second);}template <typename T>FORCE_INLINE void R(std::vector<T>&x){for(auto it=x.begin();it != x.end();++it)R(*it);}
template <typename T,typename...Args>FORCE_INLINE void RA(T*a,int n){for(int i=0;i < n;++i)R(a[i]);}template <typename T,typename...Args>FORCE_INLINE void R(T&x,Args&...args){R(x),R(args...);}
template <typename T,typename...Args>FORCE_INLINE void RA(T*a,int n,Args...args){for(int i=0;i < n;++i)RA(a[i],args...);}template <typename T>FORCE_INLINE void R(T&x){static_assert(std::is_integral<T>::value,"Unsupported types");if(std::is_integral<T>::value)__RI(x);}
private:
char space;template <typename T>FORCE_INLINE void __WI(T x){static char buf[64];static int len=-1;if(x >= 0){do{buf[++len]=x % 10+48,x /= 10;} while(x);} else{pc('-');do{buf[++len]=-(x%10)+48,x/=10;}while(x);}while(len>=0){pc(buf[len]),--len;}}
public:
FORCE_INLINE void pc(const char&x){if(op1==op2)flush();outBuf[++op1]=x;}
FORCE_INLINE void flush(){fwrite(outBuf,1,op1+1,stdout),op1=-1;}FORCE_INLINE void W(const char&x){pc(x);}FORCE_INLINE void W(const char* x){while(*x!='\0')pc(*(x++));}FORCE_INLINE void W(const std::string&x){W(x.c_str());}
template <typename T>FORCE_INLINE void W(const std::vector<T>&x){for(auto it=x.begin();it != x.end();it++)WS(*it);WL();}FORCE_INLINE void WL(){W('\n');}
template <typename T>FORCE_INLINE void WL(const T&x){W(x),W('\n');}FORCE_INLINE void WS(){W(' ');}
template <typename T>FORCE_INLINE void WS(const T&x){W(x),W(space);}
template <typename T>FORCE_INLINE void WA(T* a,int n){for(int i=0;i < n;i++)WS(a[i]);WL();}
template <typename T,typename...Args>FORCE_INLINE void W(const T&x,const Args&...args){W(x),W(space),W(args...);}
template <typename...Args>FORCE_INLINE void WL(const Args&...args){W(args...),W('\n');}
template <typename T,typename...Args>FORCE_INLINE void WA(T* a,int n,Args...args){for(int i=0;i < n;i++)WA(a[i],args...);}
template <typename T>FORCE_INLINE void W(const T&x){static_assert(std::is_integral<T>::value,"Unsupported types");if(std::is_integral<T>::value)__WI(x);}
template <typename T>FORCE_INLINE IO&operator>>(T&x){R(x);return(*this);}
template <typename T>FORCE_INLINE IO&operator<<(const T&x){W(x);return(*this);}IO(){space=' ';}
} io;
namespace Alphagocc{decltype(std::chrono::high_resolution_clock::now()) tStart;};void TimeBegin(){Alphagocc::tStart=std::chrono::high_resolution_clock::now();}long long TimeEnd(){return(std::chrono::high_resolution_clock::now() - Alphagocc::tStart).count();} // namespace Alphagocc
using namespace std;
#define REP(i,x,y) for(int i=x;i < y;i++)
const int8_t INFC=0x3f;
const int16_t INFS=0x3f3f;
const int32_t INF=0x3f3f3f3f;
const int64_t INFL=0x3f3f3f3f3f3f3f3fLL;

const int MAXN = 6e5;
long long pre[MAXN], suf[MAXN];
int main()
{
    int n;
    io >> n;
    vector<int> a(n);
    io >> a;
    vector<int> b = a;
    long long ans = 0, ansI = -1;
    stack<pair<int, int>> st;
    st.push({ 0, 0 });
    for (int i = 0; i < n; i++) {
        while (st.top().first > b[i]) st.pop();
        pre[i + 1]
            = pre[st.top().second] + 1ll * (i - st.top().second + 1) * a[i];
        st.push({ b[i], i + 1 });
    }
    while (st.size()) st.pop();
    st.push({ 0, n });
    b = a;
    for (int i = n - 1; i >= 0; i--) {
        while (st.top().first > b[i]) st.pop();
        suf[i] = suf[st.top().second] + 1ll * (st.top().second - i) * a[i];
        st.push({ b[i], i });
    }
    // io.WA(pre, n + 1);
    // io.WA(suf, n + 1);
    for (int i = 0; i < n; i++)
        if (pre[i] + suf[i] > ans) ans = pre[i] + suf[i], ansI = i;
    for (int j = ansI - 1; j >= 0; j--) a[j] = min(a[j + 1], a[j]);
    for (int j = ansI + 1; j < n; j++) a[j] = min(a[j - 1], a[j]);
    // io.WL(ans, ansI);
    // for (auto i : a) io.WL(i);
    io.W(a);
    io.flush();
    return 0;
}