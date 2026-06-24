#include <bits/stdc++.h>
using namespace std;
static char inp[1024];static char* sde = inp+1024;static const char* sp = sde;struct X{bool d[256]{},s=true;X(){for(int i=48;i<=57;++i)d[i]=true;d['-']=true;}
    inline void ra(){size_t r =sde-sp;if(r<24){memcpy(inp,sp,r);size_t sz=fread(inp+r,1,1024-r,stdin);sp=inp;sde=inp+r+sz;if(sde!=inp+1024)*sde=0;}}
    template<class T>inline X&operator,(T&x){x=s=0;ra();while(!d[*sp])ra(),++sp;if(*sp=='-')s=1;else x=(*sp&15);++sp;while(d[*sp])x=(x<<1)+(x<<3)+(*(sp++)&15);if(s)x=-x;return*this;}
}in;
int main() {
#ifdef Vishnu
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n,i,k,x,j;
    in,n,x;
    int a[400005]={};
    for(j=i=0;i<n;++i){
        in,k;
        a[k%x]++;
        for(;j<=i;++j)
            if(a[j%x])
                a[j%x]--;
            else
                break;
        cout<<j<<'\n';
    }
}