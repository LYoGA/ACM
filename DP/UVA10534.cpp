#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

int fd[MAXN], bd[MAXN], a[MAXN], b[MAXN], c[MAXN];
int n;

int search(int n, int num) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2; 
        if (num > c[mid] && num <= c[mid + 1]) 
            return mid + 1;
        else if (num <= c[mid])
            r = mid - 1;
        else
            l = mid + 1; 
    }
}

void LIS(int a[], int d[]) {
    int size = 1, temp;
    c[1] = a[1];
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] <= c[1]) 
            temp = 1;
        else if (a[i] > c[size])
            temp = ++size;
        else
            temp = search(size, a[i]);
        c[temp] = a[i];
        d[i] = temp; 
    }
} 

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) 
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            b[i] = a[n - i + 1];
        LIS(a, fd);
        LIS(b, bd);
        int ans = 0;  
        for (int i = 1;i <= n; i++) {  
            ans = max(ans, 2 * min(fd[i], bd[n - i + 1]));  
        }  
        printf("%d\n", ans - 1);
    }   
    return 0;
}
