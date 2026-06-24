// Bismillahirrahmanir Rahim

//NAMOMIZARAHID

#include<bits/stdc++.h>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<string>



#define nl printf("\n")



#define Rep(i,n) for(i=1;i<=n;i++)

#define rep(i,n) for(i=0;i<n;i++)

#define repab(i,a,b) for(i=a;i<=b;i++)



#define fil freopen("input.txt","rt",stdin)





#define pf printf

#define sf scanf







typedef long long l;

typedef unsigned long long ul;



using namespace std;

/*

bool isprime(l n)

{

    for(l i=2;i<=sqrt(n);i++)

    {

        if(n%i==0)return false;

    }

    return true;

}



bool prm[10000007];

l N= 10000000;



void sieve()

{

    prm[1]=1;

    for(l i=2;i<=sqrt(N);i++)

    {

        if(prm[i]==0)

        {

            for(l j=i+i;j<=N;j=j+i)prm[j]=1;

        }

    }

}





*/

/*

#define mod 1000000007

l bm(l b, l p)

{

    l namira;

    if(p==0)return 1;

    if(p%2==0)

    {

        namira=bm(b,p/2);

        return ((namira%mod)*(namira%mod))%mod;

    }

    else

    {

        return ((b%mod)*(bm(b,p-1)%mod))%mod;

    }

}



l modinverse(l a)

{



    return bm(a,mod-2);



}

*/

//#define mx 200010

//SEGMENT TREE

/*

l tree1[mx*3],nami[1000010],nam[1000010],check[1000010];

void init(l node,l b,l e)

{

    if(b==e)

    {

        tree1[node]=1;

        return;

    }

    l Left=node*2;

    l Right=node*2+1;

    l mid=(b+e)/2;

    init(Left,b,mid);

    init(Right,mid+1,e);

    tree1[node]=tree1[Left]+tree1[Right];



}



l query(l node,l b,l e,l i)

{

    if(nam[b]>i) return 0;

    if(nam[e]<=i)

    {

        return tree1[node];

    }

    l Left=node*2;

    l Right=node*2+1;

    l mid=(b+e)/2;

    l p1=query(Left,b,mid,i);

    l p2=query(Right,mid+1,e,i);

    return p1+p2;



}

void update(l node,l b,l e,l i,l newvalue)

{

    if (i > e || i < b) return;

    if (b >= i && e <= i)

    {

        tree1[node]=newvalue;

        return;

    }

    l Left=node*2;

    l Right=node*2+1;

    l mid=(b+e)/2;

    update(Left,b,mid,i,newvalue);

    update(Right,mid+1,e,i,newvalue);

    tree1[node]=tree1[Left]+tree1[Right];

}



//SEGMENT TREE END

/*

l NcR[200010][2];



l ncr(int n,int r)

{

    if(r==0)return 1;

    if(r==1)return n;

    if(n==r)return 1;

    if(NcR[n][r]!=0)

    {

        return NcR[n][r];

    }

    else

    {

        NcR[n][r]=ncr(n-1,r)+ncr(n-1,r-1);

        return NcR[n][r];

    }

}

*/

//bool L[100010],R[100010];

// Here starts main function :-)

/*char s[110][110];



bool ok(l i,l S,l e)

{

    l j;

    for(j=S+1;j<=e;j++)

    {

        if(s[j][i]<s[j-1][i])

        {

            return false;

        }

    }

    return true;

}







l gcd(l a,l b)

{

     if(b == 0)

     {

         return a;

     }

     else

       return gcd(b, a % b);

}*/

/*

int level[100010],r,c;

bool C[100010],vis[100010];

vector<int>V[100010],L[100010],R1,R2,R;

void bfs(l s)

{

	//memset(vis,0,sizeof vis);

	vis[s]=1;

	L[0].push_back(s);

	queue<l>q; //A queue containing STL pairs

	q.push(s);

	while(!q.empty())

	{

        int u=q.front();

        for(l i=0;i<V[u].size();i++)

        {

            int v=V[u][i];

            if(!vis[v])

            {

                vis[v]=1;

                level[v]=level[u]+1;

                if(level[v]>c)c=level[v];

                L[level[v]].push_back(v);

                q.push(v);

            }

            else

            {

                if(level[u]==level[v])

                {

                    r=0;

                }

            }

        }

        q.pop();

	}

}

*/

//#define valid(nx,ny,r,c) nx>=1&&nx<=r &&ny>=1&&ny<=c

//l fx[]={0,0,-1,1};

//l fy[]={-1,1,0,0};

//vector<l>outdeg[100010],indeg[100010];



/*



    for(i=0;i<n;i++)

    {

        sf("%I64d",&a[i]);

    }



*/

//sf("%I64d",&n);

//%I64d

l a[5];

int main()

{

    //fil;

    //freopen("output.txt", "w" , stdout);

    l n,i,j,r=0,N,x,x1,d;

    sf("%I64d",&n);

    for(i=1;i<=n;i++)

    {

        sf("%I64d",&a[i]);

    }

    if(n==0)

    {

        pf("YES\n1\n1\n3\n3\n");

    }

    else if(n==1)

    {

        pf("YES\n%I64d\n%I64d\n%I64d\n",a[1],a[1]*3,a[1]*3);

    }

    else if(n==4)

    {

        sort(a+1,a+5);

        if((a[1]+a[4]==a[2]+a[3])&&((a[4]-a[1])*2==a[1]+a[4]))

        {

            pf("YES\n");

        }

        else

            pf("NO\n");

    }

    else if(n==2)

    {

        sort(a+1,a+3);

        if(a[1]*3>=a[2])

        {

            x=a[1]+a[1]*3;

            x1=x-a[2];

            a[4]=a[1]*3;

            pf("YES\n%I64d\n%I64d\n",x1,a[4]);

        }

        else

            pf("NO\n");

    }

    else

    {

        sort(a+1,a+4);

        if(a[1]*3>=a[3])

        {

            if(a[1]*3==a[3])

            {

                pf("YES\n%I64d\n",a[3]+a[1]-a[2]);

            }

            else if(a[1]*3>a[3])

            {

                a[4]=a[1]*3;

                if(a[1]+a[4]==a[2]+a[3])

                {

                    pf("YES\n%I64d\n",a[4]);

                }

                else

                {

                    float d=a[3]/3;

                    l d1=d;

                    if(d1==d&&d1<a[1]&&d1+a[3]==a[1]+a[2])

                    {

                        pf("YES\n%I64d\n",d1);

                        return 0;

                    }

                    pf("NO\n");

                }

            }

        }

        else

            pf("NO\n");

    }

    //pf("%I64d\n",r);

    return 0;



}