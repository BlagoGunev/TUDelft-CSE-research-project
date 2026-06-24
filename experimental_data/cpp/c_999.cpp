#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int mx = 4e5+10;
char s[mx];
int vis[30];

int main(){
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    for (int i = 0; i < n; i++)
        vis[s[i]-'a'+1]++;
    for (int i = 1; i <= 26; i++)
        vis[i] += vis[i-1];
    int x = lower_bound(vis+1, vis+27, k)-vis;
    if (vis[x] != k) x--;
    int rem = k-vis[x];
    for (int i = 0; i < n; i++){
        if (x+'a' > s[i]) continue;
        if (x+'a' < s[i]) putchar(s[i]);
        else {
            if (rem) rem--;
            else putchar(s[i]);
        }
    }
    printf("\n");
	return 0;
}