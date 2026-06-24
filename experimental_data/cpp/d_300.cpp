#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>

#include <iostream>

#include <algorithm>

#include <string>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <vector>

#include <bitset>

using namespace std;



#define bll long long

#define dou double

#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)

#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)

#define rep(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)

#define rek(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)

#define Mem(a,b) memset(a,b,sizeof(a))

#define Cpy(a,b) memcpy(a,b,sizeof(b))

//__builtin_popcountll



const double PI=acos(-1);

const int modd=7340033;

const int L=15,MASK=(1<<L)-1;

const int maxn=(1024)+10;

struct Complex

{

    double real,image;

    Complex(double a=0.0,double b=0.0)

    {

        real=a,image=b;

    }

    friend Complex operator + (const Complex &a,const Complex &b)

    {

        return Complex(a.real+b.real,a.image+b.image);

    }

    friend Complex operator - (const Complex &a,const Complex &b)

    {

        return Complex(a.real-b.real,a.image-b.image);

    }

    friend Complex operator * (const Complex &a,const Complex &b)

    {

        return Complex(a.real*b.real-a.image*b.image,a.real*b.image+a.image*b.real);

    }

    Complex conj() const

    {

        return Complex(real,-image);

    }

}w[maxn],A[maxn],B[maxn],C[maxn],D[maxn];

int F[33][maxn];

long long R[35];



void FFTInit(int n)

{

    for (int i=0; i<n; i++)

        w[i]=Complex(cos(2*i*PI/n),sin(2*i*PI/n));

}



void FFT(Complex *p,int n)

{

    for (int i=1,j=0; i<n-1; i++)

    {

        for (int s=n; j^=s>>=1,~j&s; );

        if (i<j) swap(p[i],p[j]);

    }

    for (int d=0; (1<<d)<n; d++)

    {

        int m=1<<d,m2=m*2,rm=n>>(d+1);

        for (int i=0; i<n; i+=m2)

        {

            for (int j=0; j<m; j++)

            {

                Complex &p1=p[i+j+m],&p2=p[i+j];

                Complex t=w[rm*j]*p1;

                p1=p2-t;

                p2=p2+t;

            }

        }

    }

}



void baoli(int n,int *a,int *b,int *ans)

{

    static int c[maxn];

    Mem(c,0);

    For(i,0,n-1)

        For(j,0,n-1)

        {

            if (i+j>=n) continue;

            c[i+j]+=(bll)a[i]*b[j] %modd;

            c[i+j]%=modd;

        }

    Cpy(ans,c);

}



void mul(int n,int *a,int *b,int *ans)

{

    baoli(n,a,b,ans); return ;

    for (int i=0; i<n; i++)

    {

        A[i]=Complex(a[i]>>L,a[i] % MASK);

        B[i]=Complex(b[i]>>L,b[i] % MASK);

    }

    FFT(A,n); FFT(B,n);

    for (int i=0; i<n; i++)

    {

        int j=(i==0 ? 0 : n-i);

        Complex da=(A[i]-A[j].conj())*Complex(0,-0.5);

        Complex db=(A[i]+A[j].conj())*Complex(0.5,0);

        Complex dc=(B[i]-B[j].conj())*Complex(0,-0.5);

        Complex dd=(B[i]+B[j].conj())*Complex(0.5,0);

        C[j]=da*dd+da*dc*Complex(0,1);

        D[j]=db*dd+db*dc*Complex(0,1);

    }

    FFT(C,n); FFT(D,n);

    for (int i=0; i<n; i++)

    {

        long long da=(long long)(C[i].image/n+0.5) %modd;

        long long db=(long long)(C[i].real/n+0.5) %modd;

        long long dc=(long long)(D[i].image/n+0.5) %modd;

        long long dd=(long long)(D[i].real/n+0.5) %modd;

        ans[i]=((dd<<(L*2)) + ((db+dc)<<L) + da) %modd;

    }

}



void Prepare()

{

    int n=1024;

    FFTInit(n);

    memset(F[0],0,sizeof(F[0]));

    memset(F[1],0,sizeof(F[1]));

    F[0][0]=1;

    F[1][0]=1;

    F[1][1]=1;

    For(i,2,32)

    {

        mul(n,F[i-1],F[i-1],F[i]);

        mul(n,F[i],F[i],F[i]);

        //mul(n,F[i],F[i-1],F[i]);

        Rof(j,n-1,1) F[i][j]=F[i][j-1];

        F[i][0]=1;

        //if (R[i]<n)

        //    For(j,R[i]+1,n-1) F[i][j]=0;

        ///printf("%d:\n",i);

        //For(j,0,20) printf("%d ",F[i][j]);

        //printf("\n");

    }

}



int get(int n)

{

    if (n==1) return 0;

    if (n&1) return get(n>>1)+1;

    return 0;

}



int calc(int n,int k)

{

    if (n==0) return (k==0 ? 1 : 0);

//printf("%d %d\n",n,k);

    return F[n][k];

}



int main(int argc, char* argv[])

{

    Prepare();

    int q=0; scanf("%d",&q);

    For(cc,1,q)

    {

        int n,k; scanf("%d%d",&n,&k);

        n=get(n);

        int ans=calc(n,k);

        printf("%d\n",ans);

    }

    return 0;

}