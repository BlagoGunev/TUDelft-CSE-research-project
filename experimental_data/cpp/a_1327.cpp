#include <bits/stdc++.h>
using namespace std;
#define _I __attribute__((always_inline))inline
#define _rt return*this;
#define _f __X&operator,
#define _f1 if(kk){char _t=P();for(;kk&&dd[_t];_t=P());if(_t)for(;_t&&!dd[_t];_t=P())
static char inp[1024],*sde=inp+1024;static const char*sp=sde;struct __X{bool d[256],dd[256],kk=1,s=1;__X(){for(int i=48;i<58;d[i++]=1);d[45]=dd[32]=dd[10]=dd[13]=dd[9]=1;}
_I void __ra(){size_t r=sde-sp;if(r<24){memcpy(inp,sp,r);size_t sz=fread(inp+r,1,1024-r,stdin);sp=inp;sde=inp+r+sz;if(sde!=inp+1024)*sde=0;}if(sp==sde)kk=0;}_I char P()
{if(!(sde-sp))__ra();return*(sp++);}_I _f(char&x){if(kk)for(x=P();kk&&dd[x];x=P());_rt}_I _f(char*x){_f1 *x++=_t;*x=0;}_rt}_I _f(string&x){x="";_f1 x+=_t;}_rt}
template<class T>_I _f(T&x){if(kk){x=s=0;__ra();while(!d[*sp])__ra(),++sp;if(*sp=='-')s=1;else x=(*sp&15);++sp;while(d[*sp])x=(x<<1)+(x<<3)+(*(sp++)&15);if(s)x=-x;}_rt}}in;
int main()
{
#ifdef Vishnu
    freopen("output.txt", "w", stdout);freopen("input.txt", "r", stdin);
#endif
    long long k,n,t;
    in,t;
    while(t--){
        in,n,k;
        if(n&1){
            if((k&1)&&(n>=k*k)){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        } else{
            if((k&1)||((n<k*k))){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }
    }
}