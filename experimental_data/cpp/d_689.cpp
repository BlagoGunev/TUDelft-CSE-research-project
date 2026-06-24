#include <cstdio>

#include <queue>

using namespace std;



int n, a[200001], b[200001];

long long ans;

deque<int>mx, mn;

int main() {

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        scanf("%d", &a[i]);

    }

    for(int i = 1; i <= n; i++) {

        scanf("%d", &b[i]);

    }

    for(int i = 1, j = 1; i <= n; i++) {

        while(!mx.empty() and a[mx.back()] <= a[i]) mx.pop_back();

        while(!mn.empty() and b[mn.back()] >= b[i]) mn.pop_back();

        mx.push_back(i);

        mn.push_back(i);

        while(j <= i and a[mx.front()] - b[mn.front()] > 0) {

            j++;

            while(!mx.empty() and mx.front() < j) mx.pop_front();

            while(!mn.empty() and mn.front() < j) mn.pop_front();

        }

        if(!mx.empty() and !mn.empty() and a[mx.front()] == b[mn.front()]) {

            ans += min(mx.front(), mn.front()) - j + 1;

        }

    }

    printf("%I64d\n",ans);

    return 0;

}