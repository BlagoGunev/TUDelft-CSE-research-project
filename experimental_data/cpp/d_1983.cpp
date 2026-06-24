#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
struct custom_hash {size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}};
const long long mod=998244353;
//1000000007
long long modpow(long long n, long long m){long long res=1;while(m){if(m&1)res=res*n%mod;n=n*n%mod;m>>=1;}return res;}

long long _mergeSort(long long arr[], long long temp[], long long left, long long right);
long long merge(long long arr[], long long temp[], long long left, long long mid,
          long long right);

// This function sorts the
// input array and returns the
// number of inversions in the array
long long mergeSort(long long arr[], long long array_size)
{
    long long temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
long long _mergeSort(long long arr[], long long temp[], long long left, long long right)
{
    long long mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and
        // call _mergeSortAndCountInv()
        // for each of the parts
        mid = (right + left) / 2;

        // Inversion count will be sum of
        // inversions in left-part, right-part
        // and number of inversions in merging
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        // Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// This function merges two sorted arrays
// and returns inversion count in the arrays.
long long merge(long long arr[], long long temp[], long long left, long long mid,
          long long right)
{
    long long i, j, k;
    long long inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }

    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long a[200000],b[200000],aa[200000],bb[200000];
signed main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        for(long long i=0; i<n; i++) cin>>a[i];
        for(long long i=0; i<n; i++) cin>>b[i];
        for(long long i=0; i<n; i++) aa[i]=a[i];
        for(long long i=0; i<n; i++) bb[i]=b[i];
        sort(aa,aa+n);
        sort(bb,bb+n);
        long long ok=1;
        for(long long i=0; i<n; i++){
            if(aa[i]!=bb[i]) ok=0;
        }
        if(ok==0){
            cout<<"NO\n";
        }else{
            for(long long i=1; i<n; i++){
                if(aa[i]==aa[i-1]) ok=0;
            }
            if(ok==0){
                cout<<"YES\n";
            }else{
                //count swaps needed to go from a to b
                //swaps in merge sort
                if((mergeSort(a,n)+mergeSort(b,n))%2==0){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }
        }
    }
    cin>>t;
}