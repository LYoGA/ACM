#include <iostream>
#include <cstdio>
#include <cstring>
#define N 10005

int arr[N], answer[N];
int n;

void init(int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void solve(int l, int h) {
    int t = l;
    if (l == h) return; 
    for (int i = l; i <= h; i += 2)
        answer[t++] = arr[i];
    for (int i = l + 1; i <= h; i += 2)
        answer[t++] = arr[i];
    for (int i = l; i <= h; i++)
        arr[i] = answer[i];
    solve(l, (l + h) / 2);
    solve((l + h) / 2 + 1, h);
}
int main() {
    while (scanf("%d", &n) && n) {
        init(n);         
        solve(0, n - 1);  
        printf("%d:", n);
        for (int i = 0; i < n; i++)
            printf(" %d", answer[i]);
        printf("\n");
    }
    return 0;
} 
