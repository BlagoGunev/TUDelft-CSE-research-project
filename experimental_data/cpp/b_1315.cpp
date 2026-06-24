#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define P3(X,Y,Z) cout<<"d3 "<<X<<" "<<Y<<" "<<Z<<endl;
#define SQ(x) ((x) * (x))
#define ll long long
#define pii pair<int,int>
#define bchk(n,i) (bool)(n&(1<<i))
#define bon(n,i) n=(n|(1<<i))
#define boff(n,i) n=n&(~(1<<i))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define MAX3(a,b,c) max(a,max(b,c))
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define FastIO ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define eps 10e-9
#define MX 100005
using namespace std;
ll m,n;
char sx[MX];
int main()
{
    ll i,j,test,cas=0;
    ll a,b,c,sp,ln,ps,p;
    char *s=sx+1;
    //freopen("test.txt","r",stdin);
    scanf("%lld",&test);
    while(test--){

        scanf("%lld%lld%lld",&a,&b,&ps);
        scanf(" %s",s);
        ln=strlen(s);
        p=ln-2;
        c=0;
        sp=ln;
        //P(s)
        //P2(sp,ln)
        for(i=p;i>=0;i--){
            if(s[i]!=s[i-1]){
                if(s[i]=='A')c+=a;
                else c+=b;
                //P2(c,ps)
                if(c>ps) break;
                else sp=i+1;
            }
        }
        printf("%lld\n",sp);
    }
    return 0;
}