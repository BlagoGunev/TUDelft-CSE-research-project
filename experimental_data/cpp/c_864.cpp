#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <ctime>
using namespace std;
const int mod = 1e9+7;

int main()
{
    int a,b,f,k,tp;
    cin>>a>>b>>f>>k;
    tp=b;
    int bb = b;
    int ans = 0,rel = 0;
    int ff = 0;
    b-=f;
    if(b<0)
        printf("-1\n");
    else
    {


        while(1)
        {

            if(ans==k)
                break;
            if(ans==k-1)
            {
                if(b-(a-f)<0)
                {
                    rel++;
                    //   cout<<b<<endl;
                    b = bb;
                }
                if(b-(a-f)<0)
                {
                    ff = 1;
                    break;
                }
                ans++;
                b-=(a-f);
            }
            else
            {
                  if(b-(a+a-f-f)<0)
            {
                rel++;
                //   cout<<b<<endl;
                b = bb;
            }
            if(b-(a+a-f-f)<0)
            {
                ff = 1;
                break;
            }
            ans++;
            b-=(2*a-2*f);
            }



             if(ans==k)
                break;
            if(ans==k-1)
            {
                if(b-f<0)
                {
                    rel++;
                    b = bb;
                }
                if(b-f<0)
                {
                    ff = 1;
                    //break;
                }
                ans++;
            }
            else
            {
                if(b-2*f<0)
                {
                    rel++;
                    //ans++;
                    b = bb;
                }
                if(b-2*f<0)
                {
                    ff = 1;
                    break;
                }
                ans++;
                b = b-2*f;
            }

        }
       
        if(ff)printf("-1\n");
        else
		{
			//printf("%d %d %d %d\n",a,tp,f,k);
			printf("%d\n",rel);
		}
    }
    return 0;
}