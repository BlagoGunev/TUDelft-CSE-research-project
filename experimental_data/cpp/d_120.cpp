#include<cstdio>

#include<algorithm>

#include<cstring>

#include<iostream>

#include<cmath>

#include<string>

#include<map>

#include<list>

#include<queue>

#include<utility>

#include<sstream>

#include<cstdlib>

#include<cctype>

#include<math.h>

#include<set>

#include<stack>

#include<fstream>

#include<numeric>

#include<string>

#include<vector>

#include<iterator>

using namespace std;

#define ll long long

#define inf 1000000000

#define pf printf

#define sf scanf

#define sq(x) ((x)*(x))

#define MAX 100009

#define pb push_back

#define mem(a,x) memset(a,x,sizeof(a))

#define memc(a,c) memset(a,'c',sizeof(a))

#define mod 1000000007

/*int Set(int N,int pos){return N=N | (1<<pos);}

int reset(int N,int pos){return N= N & ~(1<<pos);}

bool check(int N,int pos){return (bool)(N & (1<<pos));}

int flip(int N,int pos){return N= N ^ (1<<pos);}

int Least_Significant_Bit(int N){return N= N & (-N);}*/

int X[] = {0, 0, 1, 0, 0, -1};

int Y[] = {0, 1, 0, 0, -1, 0};

int Z[] = {1, 0, 0, -1, 0, 0};

struct node{

    int x,y;

    node(){}

    node(int x,int y):x(x),y(y){}

};

int a[100][100],b[10];

int col[55],row[55];



bool check(int x,int y,int z)

{

    for(int i=1;i<=3;i++){

        for(int j=1;j<=3;j++){

            if(i==j) continue;

            for(int k=1;k<=3;k++){

                if(k==i || k==j) continue;

                if(b[i]==x && b[j]==y && b[k]==z) return 1;

            }

        }

    }

    return 0;

}





int main()

{

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    int i,j,k,l,x,y,z,t,m,n;

    cin>>n>>m;

    l=0;

    for(i=1;i<=n;i++){

        for(j=1;j<=m;j++){

            cin>>a[i][j];

            l+=a[i][j];

        }

        row[i]=l;

    }

    cin>>b[1]>>b[2]>>b[3];

    l=0;

    for(i=1;i<=m;i++){

        for(j=1;j<=n;j++){

            l+=a[j][i];

        }

        col[i]=l;

    }

    l=0;

    for(i=1;i<=n;i++){

        for(j=i+1;j<n;j++){

            x=row[i];

            y=row[j]-row[i];

            z=row[n]-row[j];

            l+=check(x,y,z);

        }

    }



    for(i=1;i<=m;i++){

        for(j=i+1;j<m;j++){

            x=col[i];

            y=col[j]-col[i];

            z=col[m]-col[j];

            l+=check(x,y,z);

        }

    }

    pf("%d",l);

    return 0;

}