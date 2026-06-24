#include<iostream>

#include<cstring>

using namespace std;

using LL = long long;

const int maxn = 4e5 + 5, len = 650;		//len为A的根号，区间长度

int a[maxn], stk[maxn];			//stk单调栈维护

LL f[maxn];



int main(){



    cin.tie(0);

    cout.tie(0);

    ios::sync_with_stdio(0);



    auto sqr = [](int x){

        return 1LL * x * x;

    };



    int n;

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(f, 0x3f, sizeof f);

    f[1] = 0;

    int top = 0;

    cout << f[1] << ' ';

    stk[++top] = 1;

    for(int i = 2; i <= n; i++)

	{

		//case 1：当a[j,i]的最小值>=len时

		//可以推断出，最小值上一次位置一定在[i-len, i-1]中，所以枚举这个区间

        //推断的性质是：对比一步一步走的情况

		//只是没有加判断条件，因为没有必要

        int mn = a[i];		//mn维护区间最小值

        for(int j = i - 1; j >= max(1, i - len); j--)

        {		

            mn = min(mn, a[j]);

            f[i] = min(f[i], f[j] + mn * sqr(i - j));

        }



        //case 2：假设的a[i]是最小值

        //这里的共同复杂度为n*len，可以思考一下

        if (a[i] <= len)

        {

            for(int j = i - 1; j >= 1; j--){

                f[i] = min(f[i], f[j] + a[i] * sqr(i - j));

                if (a[j] <= a[i])   break;      //一旦遇到了必a[i]还小的数，那a[i]就非最小值了

            }

        }



        //case 3：前面的那个是最小值

        //stk[]保存的是下标

        for(int j = 1; j <= top; j++)       //先品鉴一下单调栈里面的数

            f[i] = min(f[i], f[stk[j]] + a[stk[j]] * sqr(i - stk[j]));

        if (a[i] <= len)

        {

            while(top && a[stk[top]] >= a[i]) top--;

            stk[++top] = i;

        }

        cout << f[i] << ' ';

    }



}