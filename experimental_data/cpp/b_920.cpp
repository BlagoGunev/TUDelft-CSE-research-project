#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;

    scanf("%d",&tc);

    while(tc--){

         int n;
         scanf("%d",&n);
         int ans[n];
         int last=0;
         for(int i=0;i<n;i++){
            int l,r;

            scanf("%d %d",&l,&r);
            if(l>=last){

                if(l==last){
                   if(l==r)
                    ans[i]=0;
                   else
                    ans[i]=l+1;
                }
                else
                ans[i]=l;
                }
            else{
                while(++l<=r){
                    if(l>last){
                        ans[i]=l;
                        break;
                        }
                }
                if(l>r)
                    ans[i]=0;
            }
            if(ans[i]!=0)
             last=ans[i];

         }

         for(int i=0;i<n;i++)
            printf("%d ",ans[i]);
         printf("\n");
    }
    return 0;
}