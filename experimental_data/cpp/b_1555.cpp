#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
const int maxn=5e5+1000;

int t;


 
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int W,H;
        scanf("%d%d",&W,&H);
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int w,h;
        scanf("%d%d",&w,&h);
        int nw,nh;
        int ans=999999999;
        if(H>=h)
        {
            if(W-x2+x1>=w)
            {
                if(W-x2>=w||x1>=w)
                {
                    printf("0\n");
                    continue;
                }
                else
                    ans=min(ans,min(w-(W-x2),w-x1));
            }
        }
        if(W>=w)
        {
            if(H-y2+y1>=h)
            {
                if(H-y2>=h||y1>=h)
                {
                    printf("0\n");
                    continue;
                }
                else
                    ans=min(ans,min(h-(H-y2),h-y1));
            }
        }
        if(ans==999999999)
        {
            printf("-1\n");
        }
        else printf("%d\n",ans);
    }
	return 0;
}