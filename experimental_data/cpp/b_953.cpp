#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cstring>
using namespace std;
int a[100005];
int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}
void build_heap(int a[],int root,int size){
    if (a == NULL  || size <= 0) return;
    int mx = root;
    int lson = root << 1;
    int rson = (root << 1) | 1;
    if  (lson <= size && a[root] < a[lson]) mx = lson;
    if  (rson <= size && a[rson] > a[mx]) mx = rson;
    if (mx != root){
        int t = a[mx];
        a[mx] = a[root];
        a[root] = t;
        build_heap(a,mx,size);
    }
}
void build_Maxheap(int a[],int size){
    int len = size;
    for (int i = len / 2; i >= 1; i--){
         build_heap(a,i,len);
    }
}
void heap_sort(int a[],int l,int r){
    int len = r - l + 1;
    build_Maxheap(a,len);
    for (int i = len; i >= 2; i--){
          int t = a[i];
          a[i] = a[1];
          a[1] = t;
          len--;
          build_heap(a,1,len);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
         scanf("%d",&a[i]);
    }
    if (n == 1){
        printf("0\n");
        return 0;
    } 
    heap_sort(a,1,n);
    
  //  for (int i = 1; i <= n; i++) printf("%d ",a[i]);
    //    printf("\n");
    int g = a[2] - a[1];
    for (int i = 2; i <= n - 1; i++){
        g = gcd(g,a[i + 1] - a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        ///printf("%d %d\n",a[i],a[i + 1]);
        if  (a[i] + g != a[i + 1]) {
            ans += (a[i + 1] - a[i]) / g - 1;
        }
    }
    printf("%d\n",ans);
}