#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ARR[200100];
long long partial_sum[200100];

int main() {
    ios_base::sync_with_stdio(0);


    cin.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> ARR[i];
    }

    long long sum = 0;
    for (int i = 1; i < M; i++)
        sum += max(ARR[i], ARR[i + 1]) - min(ARR[i], ARR[i + 1]);

    for (int i = 1; i < M; i++) {
        int left = min(ARR[i], ARR[i + 1]);
        int right = max(ARR[i], ARR[i + 1]);


        if (left != right) {
            if (right > left + 1) {
                partial_sum[left + 1]--;
                partial_sum[right]++;
            }

            int dif;
            dif = left - right + left;
            partial_sum[right] += dif;
            partial_sum[right + 1] -= dif;

            dif = right - 1 - right + left;
            partial_sum[left] += dif;
            partial_sum[left + 1] -= dif;
        }

    }

    for (int i = 1; i <= N; i++) {
        sum += partial_sum[i];
        cout << sum << ' ';
    }
    return 0;
}