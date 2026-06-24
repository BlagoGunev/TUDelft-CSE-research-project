#include  <algorithm>//           ¨|¨|¨|        ¨|¨|¨|¨|
#include   <iostream>//         ¨}¨}¨}¨}      ¨~¨~¨~
#include    <cstring>//        ¨~¨~ ¨~¨~    ¨~¨~
#include    <stdio.h>//       ¨~¨~  ¨~¨~   ¨~¨~
#include     <vector>//      ¨~¨~   ¨~¨~  ¨~¨~
#include      <cmath>//     ¨~¨~    ¨~¨~  ¨~¨~
#include      <queue>//    ¨~¨~ ¨~¨~¨~¨~  ¨~¨~
#include        <map>//   ¨~¨~      ¨~¨~   ¨~¨~
using namespace std ;//  ¨~¨~       ¨~¨~    ¨~¨~¨~
typedef long long ll;// ¨~¨~        ¨~¨~      ¨~¨~¨~¨~¨~
#define pi pair<int,int>  ///////////////////////////////
#define P(x,y) make_pair(x,y)
const int maxn = 1e5 + 5;
const ll mod = 998244353;
ll read()
{
	ll x=0;char ch=getchar(); bool flag = false;
	if(ch=='-') { flag = true; ch = getchar();}
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	if(flag) return -x;  else return x;
}
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
int main()
{   if(fopen("in.txt","r")) freopen("in.txt","r",stdin);
    int T,n,m,k,i,sum,j,t,tmp;
    int cnt[105]={0},a[2*maxn];
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        a[i] = read();
        cnt[a[i]%k]++;
    }
    ll ans = cnt[0]-(cnt[0]&1);
   // cout<<ans<<endl;
    for(i=1;i<=k/2;i++){
      //  cout<<i<<" "<<cnt[i]<<" "<<cnt[k-i]<<endl;
        if(k-i!=i){
            ans += min(cnt[i] , cnt[k-i])*2;
        }else ans += cnt[i]-(cnt[i]&1);
    }
    printf("%d\n",ans);
    return 0;
}