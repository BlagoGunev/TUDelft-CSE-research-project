#include<cstdio>

#include<string.h>

#include<stdlib.h>

#include<math.h>

#include<algorithm>

using namespace std;

const int maxn = 1e5+ 5;

char st[maxn];

int main(){

    int n;

    scanf("%d%s",&n,st);

    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;

    for(int i=0;i<n;i++){

        if(i%2==0&&st[i]!='r') cnt1++;

        else if(i%2==1&&st[i]!='b') cnt2++;

    }

    for(int i=0;i<n;i++){

        if(i%2==0&&st[i]!='b') cnt3++;

        else if(i%2==1&&st[i]!='r') cnt4++;

    }

    int ans1=abs(cnt1-cnt2)+(cnt1+cnt2-abs(cnt1-cnt2))/2;

    int ans2=abs(cnt3-cnt4)+(cnt3+cnt4-abs(cnt3-cnt4))/2;

    printf("%d\n",min(ans1,ans2));

    return 0;

}