#include<cstdio>

#include<cstring>

#include<set>

#include<algorithm>

#include<iostream>

using namespace std;



set<int>s;



int main()

{

    int p,n;

    while(scanf("%d%d",&p,&n)!=EOF)

    {

        s.clear();

        bool flag=true;

        int cnt;

        for(int i=1;i<=n;i++)

        {

            int x;

            scanf("%d",&x);

            x=x%p;

            if(s.count(x)==1&&flag)

            {

                cnt=i;

                flag=false;

            }

            else s.insert(x);

        }

        if(flag) printf("-1\n");

        else printf("%d\n",cnt);

    }

    return 0;

}