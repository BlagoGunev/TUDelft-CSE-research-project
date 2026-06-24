#include <bits/stdc++.h>
#define ll long long
#define all(v)     v.begin(),v.end()
const int v = 100016;
using namespace std;
void naruto()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
}
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
bool BinSearch(int* arr, int n, int num)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == num)
            return true;
        else if (arr[mid] > num)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;
}
bool prime(int n)
{
    if (n < 2)return false;
    if (n <= 3)return true;
    if (n % 2 == 0)return false;
    for (int i = 3;i * i <= n;i += 2)
    {
        if (n % i == 0)return false;
    }
    return true;
}
//Surface Area of Sphere = 4πr²,
//the volume of a sphere is V = 4/3 πr³.
int main() {
    //وَلَسَوْفَ يُعْطِيكَ رَبُّكَ فَتَرْضَى
    naruto();
    //cout << fixed << setprecision(12);
    //set<int> s;
    //deque<int> d;
    //map<int, int> mp;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>ans;
        for (int i = m+1; i <n; ++i)
            ans.push_back(i);//   ما بين الرقمين
        cout<<ans.size()*2+2<<'\n';
        cout<<m<<' ';
        for(auto it:ans)cout<<it <<' ';
        cout<<n<<' ';
        reverse(ans.begin(),ans.end());
        for(auto it:ans)cout<<it <<' ';
        cout<<'\n';
    }
}