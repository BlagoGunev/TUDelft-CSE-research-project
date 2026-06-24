/**



   Pradip chandra karmaker

   Comilla University(6th_ICT)

*/







#include<bits/stdc++.h>



using namespace std;

#define xx first

#define yy second

#define pb push_back

#define mp make_pair

#define clr(a) memset(a,0,sizeof a)

#define neg(a) memset(a,-1,sizeof a)

#define Sort(a) sort(a.begin(),a.end())

#define All(a) a.begin(),a.end()

typedef long long i64;

typedef pair<int,int> pi;

#define mod 1000000007LL











template<class T>T Bitcnt(T a){int sum=0;while(a){if(a&1)sum++;a/=2;}return sum;}

template<class T>T Max3(T a,T b,T c){return max(a,max(b,c));}

template<class T>T Lcm(T a,T b){T tmp=__gcd(a,b);return (a/tmp)*b;}

template<class T> T Pow(T a,T b){T ans=1;T base=a;while(b){if(b&1)ans=(ans*base);base=(base*base);b/=2;}return ans;}

i64 Bigmod(i64 a,i64 b)

{

    i64 res=1;

    i64 pw=a%mod;

    while(b>0)

    {

       if(b&1)res=(res*pw)%mod;

       pw=(pw*pw)%mod;

       b/=2;

    }

    return res;

}





#define s1(a) scanf("%d",&a)

#define s2(a,b) scanf("%d %d",&a,&b)

#define s3(a,b,c) scanf("%d %d %d",&a,&b,&c)

#define sl1(a) scanf("%lld",&a)

#define sl2(a,b) scanf("%lld %lld",&a,&b)

#define sl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define p1(a) printf("%d",a)

#define p2(a,b) printf("%d %d",&a,&b)

#define NL printf("\n")

#define N 4000000

#define rep(i,a,b)    for(int i=a;i<=b;i++)

#define rrep(i,b,a)   for(int i=b;i>=a;i--)

#define fs(i,a,s)     for(int i=a;s[i];i++)



int a_x[]={1,-1,0,0};

int a_y[]={0,0,1,-1};

i64 X,Y;



void extend_euclid(i64 a,i64 b)

{

    if(b==0)

    {

        X=a;Y=0;return;

    }

    extend_euclid(b,a%b);

    i64 x,y;

    x=Y;

    y=X-(a/b)*Y;

    X=x;

    Y=y;

}



i64 inverse_modulo(i64 a,i64 b)

{

    extend_euclid(a,b);

    return (X+mod)%mod;

}



/** dijkstra,bitmask,ME,scc,backtracking,grid dp,segment tree,bit,LCA,bfs,dfs,BPM,MAX_FLOW,MCM,Tree dp,kmp,MST,Meet in the middle*/



/**Triangle characteristics,Phi,bitwise_seive,SOD,articulation,topological,HLD,Z,knapsack,Coin,Digit,LIS,LCS,minimum vertex

cover,josephus,chinese remainder,square root decomposition,ternary search,binary search,Number of theory(divisor,prime),chinese remainder,Generic functoin,Convex hull*/



/*************************************************************************************************************************************************************************************************/



struct node

{

    int id,x,y,val;

    node(){}

    node(int a,int b,int c,int d){id=a;val=b;x=c;y=d;}

    bool operator<(const node&now)const

    {

        return val<now.val;

    }

};

int ax[N],ay[N];

node data[N];

int pa[N];

int ans[N];

int f[N];



int Find(int x)

{

    if(pa[x]==x)

        return x;

    return pa[x]=Find(pa[x]);

}

int main()

{





   ///freopen("input.txt","r",stdin);

    int n,m;

    int cnt=0;

    s2(n,m);

    int val;



    rep(i,1,n)

      rep(j,1,m)

         {

            s1(val);

            cnt++;

            data[cnt]=node(cnt,val,i,j+n);

         }





    sort(data+1,data+cnt+1);



    int i,j;

    for(i=1;i<=cnt;i=j)

    {

        for(j=i;j<=cnt && data[j].val==data[i].val;j++);



        for(int k=i;k<j;k++)

        {

            pa[data[k].x]=data[k].x;

            pa[data[k].y]=data[k].y;

            f[data[k].x]=f[data[k].y]=0;

        }



        for(int k=i;k<j;k++)

        {

            int r1=Find(data[k].x);

            int r2=Find(data[k].y);

            pa[r1]=r2;

            f[r2]=max(f[r1],max(f[r2],max(ax[data[k].x],ay[data[k].y])));

        }



        for(int k=i;k<j;k++)

        {

            ans[data[k].id]=max(f[Find(data[k].x)],f[Find(data[k].y)])+1;

            ax[data[k].x]=max(ans[data[k].id],ax[data[k].x]);

            ay[data[k].y]=max(ans[data[k].id],ay[data[k].y]);

        }

    }



    cnt=1;

    for(int i=1;i<=n;i++)

    {

        for(int j=1;j<=m;j++)

            printf("%d ",ans[cnt++]);

        printf("\n");

    }



   return 0;

}