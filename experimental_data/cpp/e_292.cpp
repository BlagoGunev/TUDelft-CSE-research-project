#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

int tree[300000];
int p;

void upd(int i,int j,int x)
{
    i+=p;
    j+=p;
    while(i<=j)
    {
        if(i%2){tree[i]=x;i++;}
        if(~j%2){tree[j]=x;j--;}
        i/=2;
        j/=2;
    }
}

int n,m,i,j,ma;

struct T
{
    int i,j,k;
}t;

vector<T>v;
int a[200000],b[200000];

int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(j=0;j<n;j++)
        scanf("%d",&b[j]);
    for(p=1;p<n;p+=p);
    while(m--)
    {
        scanf("%d",&i);
        if(i==1)
        {
            scanf("%d%d%d",&t.i,&t.j,&t.k);
            t.i--;
            t.j--;
            v.push_back(t);
            upd(t.j,t.j+t.k-1,v.size());
        }
        else
        {
            scanf("%d",&i);
            j=i-1;
            i+=p-1;
            ma=0;
            for(;i;i/=2)
                if(tree[i]>ma)
                    ma=tree[i];
            if(!ma)
                printf("%d\n",b[j]);
            else
            {
                t=v[ma-1];
                printf("%d\n",a[j-t.j+t.i]);
            }
        }
    }
    return 0;
}
/*
5 100
1 2 3 4 5
6 7 8 9 0
1 1 3 2
1 1 1 3
*/