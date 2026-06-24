#include <iostream>
#include <cstring>

using namespace std;

int n, x;
int nums[3020];
int len[3020];
bool fre[3020];
bool reach[3020], nreach[3020];

int dfs(int i) {
    if(nums[i] == 0)
        return 1;
    if(nums[i] == x)
        return -1;
    int further = dfs(nums[i]);
    if(further == -1)
        return -1;
    return 1 + further;
}

int main() {
    memset(len, 0, sizeof len);
    memset(fre, true, sizeof fre);
    memset(reach, false, sizeof reach);

    cin >> n >> x;

    fre[0] = false;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        fre[ nums[i] ] = false;
    }

    for(int i = 1; i <= n; i++) {
        if(!fre[i])
            continue;
        else if(i != x) {
            int num = dfs(i);
            if(num == -1)
                continue;
            len[num]++;
        }
    }

    reach[0] = true;
    int mylen = dfs(x);
    for(int i = 1; i<= n; i++) {
        for(int j = 0; j <= n; j++)
            nreach[j] = reach[j];
        for(int j = 1; j <= len[i]; j++) {
            int add = j*i;

            for(int k = 0; k <= n; k++)
                if(reach[k]) {
                    nreach[k+add] = true;
                }
        }
        for(int j = 0; j <= n; j++)
            reach[j] = nreach[j];
    }

    for(int i = 0; i <= n; i++)
        if(reach[i])
            cout << i+mylen << endl;

    return 0;
}