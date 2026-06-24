#include <bits/stdc++.h>



using namespace std;



#define ll long long



struct Edge{

    int x,y,link;

};



const int maxN=1e5+10;



map <int,int> A[maxN];



Edge E[maxN*2];

int Head[maxN],c[maxN],d[maxN],M[maxN],R[maxN];

ll Ans[maxN];

int n,m,P;



void themcanh(int u, int v)

{

    m++; E[m].x=u; E[m].y=v;

    E[m].link=Head[u]; Head[u]=m;

}

void docdl()

{

    scanf("%d",&n);

    for (int i=1; i<=n; i++)

    {

        Head[i]=0;

        scanf("%d",&c[i]);

    }

    m=0;

    int u,v;

    for (int i=1; i<n; i++)

    {

        scanf("%d%d",&u,&v);

        themcanh(u,v); themcanh(v,u);

    }

}

void dfs(int i)

{

    d[i]=1;

    int t=Head[i];

    while (t!=0)

    {

        int v=E[t].y;

        if (d[v]==-1)

        {

            dfs(v);

            d[i]+=d[v];

        }

        t=E[t].link;

    }

}

void duyet(int i,int Tr)

{

    Ans[i]=c[i]; R[i]=1;

    int t=Head[i],maxd=0,vd=-1;

    while (t!=0)

    {

        int v=E[t].y; if (v!=Tr && d[v]>maxd) {maxd=d[v]; vd=v;}

        t=E[t].link;

    }

    if (vd==-1) {A[M[i]][c[i]]++; return;}

    M[vd]=M[i];

    duyet(vd,i);

    t=++A[M[i]][c[i]];

    if (t>R[vd])

    {

        R[i]=t;

    } else if (t==R[vd])

        {

            R[i]=t; Ans[i]+=Ans[vd];

        }

        else

        {

            R[i]=R[vd]; Ans[i]=Ans[vd];

        }

    //---

    t=Head[i];

    int dem=0;

    while (t!=0)

    {

        int v=E[t].y;

        if (v!=vd && v!=Tr)

        {

            dem++; P++; M[v]=P;

            duyet(v,i);

            for (map <int,int>::iterator it=A[M[v]].begin(); it!=A[M[v]].end(); it++){

                A[M[i]][it->first] += it->second;

                int tt=A[M[i]][it->first];

                if (tt>R[i])

                {

                    R[i]=tt; Ans[i]=it->first;

                }

                else if (tt==R[i]) Ans[i]+=it->first;

            }

            //---

            /*if (R[i]>R[v])

            {

            } else if (R[i]==R[v])

                {

                    Ans[i]+=Ans[v];

                }

                else

                {

                    R[i]=R[v]; Ans[i]=Ans[v];

                }*/

        }

        t=E[t].link;

    }

    /*if (dem>0)

    {

        R[i]=-1; Ans[i]=0;

        for (map <int,int>::iterator it=A[M[i]].begin(); it!=A[M[i]].end(); it++)

            if (it->second>R[i])

            {

                Ans[i]=it->first;

                R[i]=it->second;

            }

            else if (it->second==R[i])

                {

                    Ans[i]+=it->first;

                }

    }*/

}

int main()

{

    docdl();

    for (int i=1; i<=n; i++) {d[i]=-1; R[i]=0;}

    dfs(1);

    P=1; M[1]=1;

    duyet(1,0);

    for (int i=1; i<=n; i++)

        printf("%I64d ",Ans[i]);

}