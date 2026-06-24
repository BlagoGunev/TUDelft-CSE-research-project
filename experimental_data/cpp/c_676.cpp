#include<bits/stdc++.h>

using namespace std;

int n,k;

char s[100005];

int main()

{

    scanf("%d%d",&n,&k);

    scanf("%s",s);

    int maxna=0;

    int maxnb=0;

    int l=0,r=0;

    int cc=0;

    while(l<n)

    {

        while(r<n&&cc<=k)

        {

            if(s[r]=='b')

            {

                if(cc==k)

                    break;

                cc++;

            }

            r++;

        }

        maxna=max(r-l,maxna);

        if(s[l]=='b')

        {

            cc--;

        }

        l++;

    }

    l=0,r=0,cc=0;

    while(l<n)

    {

        while(r<n&&cc<=k)

        {

            if(s[r]=='a')

            {

                if(cc==k)

                    break;

                cc++;

            }

            r++;

        }

        maxnb=max(r-l,maxnb);

        if(s[l]=='a')

        {

            cc--;

        }

        l++;

    }

    printf("%d\n",max(maxna,maxnb));

    return 0;

}