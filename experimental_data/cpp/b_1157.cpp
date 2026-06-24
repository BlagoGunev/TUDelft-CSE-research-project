#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define di digit[i]
#define dj digit[j]

using namespace std;

const int N = 2e5+5;

int mp[10];
char digit[N];

int main()
{
    int n,m;
    while (~scanf("%d",&n)){
        scanf("%s",digit);
        for (int i=1;i<10;i++) scanf("%d",&mp[i]);
        //for (int i=1;i<10;i++) printf("%d", mp[i]);
        for (int i=0;i<n;i++){
            if (mp[digit[i]-'0']>digit[i]-'0'){
                //printf("%d %d",digit[i],mp[digit[i]]+'0');
                digit[i] = mp[digit[i]-'0']+'0';
                for (int j=i+1;j<n;j++){
                    if (digit[j]=='0') continue;
                    else if (mp[digit[j]-'0']>=digit[j]-'0') digit[j] = mp[digit[j]-'0']+'0';
                    else break;
                }
                break;
            }
        }
        printf("%s\n",digit);
    }
    return 0;
}