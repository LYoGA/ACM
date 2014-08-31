#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000005;

int arr[MAXN], b[MAXN];
int n, k;
long long cnt;


void merge_sort(int * a, int x, int y, int *b) {
    if (y - x > 1) {
        int m = x + (y - x) / 2; 
        int p = x, q = m, i = x; 
        merge_sort(a, x, m, b);
        merge_sort(a, m, y, b);
        while (p < m || q < y) {
            if (q >= y || (p < m && a[p] <= a[q]))
                b[i++] = a[p++];
            else {
                b[i++] = a[q++];  
                cnt += m - p; 
            }
        }
        for (i = x; i < y; i++)
            a[i] = b[i];
    }
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]);
        cnt = 0;
        merge_sort(arr, 0, n, b);
        if (cnt - k > 0)
            cnt -= k;
        else 
            cnt = 0;
        cout << cnt << endl;
    } 
    return 0;
}
