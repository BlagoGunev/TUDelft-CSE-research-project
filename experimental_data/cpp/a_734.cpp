#include<cstdio>
//#include<cstdlib>
//#include<climits>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
using namespace std;
int main(){
    int n, cnt = 0;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++){
        char c;
        scanf("%c", &c);
        if (c == 'A')
            cnt++;
    }
    if (cnt == n-cnt)
        printf("Friendship\n");
    else if (cnt > n-cnt)
        printf("Anton\n");
    else
        printf("Danik\n");
    return 0;
}