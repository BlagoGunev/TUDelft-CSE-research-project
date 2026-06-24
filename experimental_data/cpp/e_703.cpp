#include<bits/stdc++.h>

#define mp make_pair

#define pb push_back

#define F first

#define S second

#define sz size

#define endl '\n'

#define all(X) (X).begin(), (X).end ()

#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

#define MOD 1000000007

#define EPS 1e-9

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

#define pr(a) printf("%d\n",a)

#define sc(a) scanf("%d",&a)

#define sc2(a,b) scanf("%d%d",&a,&b)

#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define MAX_N 500

using namespace std;

#define mytype pair<int,pair<long long,pair<int,int> > >

mytype dp[1010][7777];

pair<mytype,int> dpp[7777];

vector<pair<int,int> >pf;

vector<int> apv[1001];

int64_t a[1010],k;

int cnt=1,n,bh,eh;

int g[7777][1010];



mytype def(INT_MAX-1010,mp(LONG_MAX,mp(1010,7777)));



inline int geth(vector<int>&v){

    int ret=0,b=1;

    for(int i=0;i<(int)v.size();++i)ret+=v[i]*b,b*=(pf[i].S+1);

    return ret;

}

void bt(int i,vector<int>&v){

    if(i==(int)pf.size()){

        int hv=geth(v);

        vector<int>ed(pf.size(),0);

        for(int l=0;l<n;++l){

            for(int j=0;j<(int)v.size();++j){

                ed[j]=max(v[j]-apv[l][j],0);

            }

            g[hv][l]=geth(ed);

        }

        return;

    }

    for(int j=0;j<=pf[i].S;++j){

        bt(i+1,v);

        --v[i];



    }v[i]+=pf[i].S+1;

}

int main(){

//    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//    freopen("input.txt","r",stdin);

//    freopen("output.txt","w",stdout);

    scanf("%d%I64d",&n,&k);

    vector<int>tpf;

    for(int i=2;i*1LL*i<=k;++i){

        if(k%i==0){

            int c=0;

            while(k%i==0){

                k/=i;

                ++c;

            }

            tpf.pb(c);

            pf.pb(mp(i,c));

        }

    }if(k>1)pf.pb(mp(k,1)),tpf.pb(1);



    eh=0;

    bh=geth(tpf);

    cnt=bh+1;

    int64_t ta;

    for(int i=0;i<n;++i){

        scanf("%I64d",&a[i]);

        ta=a[i];

        apv[i]=vector<int>(pf.size(),0);

        for(int j=0;j<(int)pf.size();++j){

            int c=0;

            while(ta%pf[j].F==0&&c<pf[j].S)++c,ta/=pf[j].F;

            apv[i][j]=c;

        }

    }

    if(pf.size()==0){

        int64_t mn=1e18;

        int mni=0;

        for(int i=0;i<n;++i)

            if(a[i]<mn)mn=a[i],mni=i;

        pr(1);

        pr(mni+1);

        return 0;

    }

    bt(0,tpf);



//    for(int i=0;i<cnt;++i)

//        for(int j=0;j<cnt;++j)

//            cout<<i<<" "<<j<<" "<<g[i][j]<<endl;

/// a.F     --->  # of elements

/// a.S.F   --->  sum of elements

/// a.S.S.F --->  next element

/// a.S.S.S --->  hash value of next element

    dpp[eh]=mp(mp(0,mp(0,mp(-1,-1))),-1);

    for(int j=1;j<cnt;++j)

        dpp[j]=mp(def,-1);

    for(int i=n-1;i>=0;--i){

        mytype tmp;

        for(int hv=1,to;hv<cnt;++hv){

            dp[i][hv]=def;

            to=g[hv][i];

            if(dpp[to].F.F==def.F)continue;

            tmp=dpp[to].F;

            ++tmp.F;

            tmp.S.F+=a[i];

            tmp.S.S=mp(dpp[to].S,to);

            dp[i][hv]=min(dp[i][hv],tmp);



        }

        for(int hv=1;hv<cnt;++hv)

            if(dp[i][hv]<dpp[hv].F)

                dpp[hv]=mp(dp[i][hv],i);

    }

    mytype ans=dpp[bh].F;

    if(ans.F==def.F){

        pr(-1);

    }else{

        int m=ans.F;

        pr(m);

        printf("%d ",dpp[bh].S+1);

        while(--m){

            printf("%d ",ans.S.S.F+1);

            ans=dp[ans.S.S.F][ans.S.S.S];

        }

    }



}