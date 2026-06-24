#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],f[N];
vector<int>v;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(b+1,b+1+n,a[i])-b;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!f[i]){
            int u=i;
            while(!f[u]){
                f[u]=1;
                u=a[u];
            }
            ans++;
        }
    }
    memset(f,0,sizeof(f));
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(!f[i]){
            v.clear();
            int u=i;
            while(!f[u]){
                f[u]=1;
                v.push_back(u);
                u=a[u];
            }
            printf("%d ",v.size());
            for(int i=0;i<v.size();i++) printf("%d ",v[i]);
            printf("\n");
        }
    }
    return 0;
}