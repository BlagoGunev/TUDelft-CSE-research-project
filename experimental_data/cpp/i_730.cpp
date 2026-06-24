#include <cstdio>

#include <cstring>

#include <cmath>

#include <queue>

#include <algorithm>

#include <iostream>

#define REP(i,x,y) for (int i=x;i<=y;i++)

#define REPF(i,x,y) for (int i=x;i>=y;i--)

using namespace std;

int p[3030],s[3030];

struct nod

{

    int s,p,i,z;

};

bool cmp(nod q,nod w)

{

    return q.z>w.z;

}

struct cmp1{

    bool operator ()(nod &a,nod &b){

        return a.p>b.p;//最小值优先

    }

};

struct cmp2{

    bool operator ()(nod &a,nod &b){

        return a.s>b.s;//最大值优先

    }

};

nod g[3030];

int f[3030][3030];

int ps[3030],sss[3030];

int mp[3030],ms[3030];

int v[3030];

int main()

{

    int n,pp,ss;

    cin>>n>>pp>>ss;

    REP(i,1,n) cin>>g[i].p;

    REP(i,1,n) cin>>g[i].s;

    REP(i,1,n) g[i].i=i;

    REP(i,1,n) g[i].z=g[i].p-g[i].s;

    sort(g+1,g+1+n,cmp);

    priority_queue<nod,vector<nod>,cmp1>que1;

    mp[0]=0;

    REP(i,1,pp) {mp[i]=mp[i-1]+g[i].p;que1.push(g[i]);}

    REP(i,pp+1,n)

        if (g[i].p>que1.top().p)

        {

           mp[i]=mp[i-1]-que1.top().p+g[i].p;

           que1.pop();

           que1.push(g[i]);

        }

        else mp[i]=mp[i-1];

    priority_queue<nod,vector<nod>,cmp2>que2;

    ms[n+1]=0;

    REPF(i,n,n-ss+1) {ms[i]=ms[i+1]+g[i].s;que2.push(g[i]);}

    REPF(i,n-ss,1)

        if (g[i].s>que2.top().s)

        {

           ms[i]=ms[i+1]-que2.top().s+g[i].s;

           que2.pop();

           que2.push(g[i]);

        }

        else ms[i]=ms[i+1];

    int ans=0,k=0;

    REP(i,pp,n-ss) if (mp[i]+ms[i+1]>ans){ans=mp[i]+ms[i+1];k=i;}

    cout<<ans<<endl;

    {

        priority_queue<nod,vector<nod>,cmp1>que1;

        priority_queue<nod,vector<nod>,cmp2>que2;

        REP(i,1,pp) que1.push(g[i]);

        REP(i,pp+1,k) if (g[i].p>que1.top().p) {que1.pop();que1.push(g[i]);}

        REP(i,k+1,k+ss) que2.push(g[i]);

        REP(i,k+1+ss,n) if (g[i].s>que2.top().s) {que2.pop();que2.push(g[i]);}

        REP(i,1,pp) {ps[i]=que1.top().i;que1.pop();}

        REP(i,1,ss) {sss[i]=que2.top().i;que2.pop();}

        sort(ps+1,ps+1+pp);

        sort(sss+1,sss+1+ss);

    }

    REP(i,1,pp) cout<<ps[i]<<' ';

    cout<<endl;

    REP(i,1,ss) cout<<sss[i]<<' ';



}