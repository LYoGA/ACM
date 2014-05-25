#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 1000005
using namespace std;

int arr[N], a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int l, m; 
        scanf("%d %d", &l, &m); 
        for (int i = 0; i < m; i++) 
            scanf("%d", &arr[i]);
        for (int i = 0; i < m; i++) {
            int temp;
            a[i] = abs(arr[i] - l);  
            b[i] = arr[i];
            if (a[i] > b[i]) {
                temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
        }
        sort(a, a + m);
        sort(b, b + m);
        printf("%d %d\n", a[m - 1], b[m - 1]);
    } 
    return 0;
}
