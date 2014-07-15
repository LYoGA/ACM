#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 40005;

int a[MAXN], c[MAXN], d[MAXN];
int n;

int search(int n, int num) {
    int l = 1, r = n;
    while (l <= n) {
        int mid = (l + r) / 2; 
        if (num > c[mid] && num <= c[mid + 1]) 
            return mid + 1;
        else if (num <= c[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
}

int LIS() {
    int size = 1, Max = 0, temp;
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
        if (d[i] > Max)
            Max = d[i];
    }
    return Max;
}

int main() {
    int cas;    
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n); 
        for (int i = 1; i <= n; i++) 
            scanf("%d", &a[i]); 
        memset(d, 0, sizeof(d));
        cout << LIS() << endl;
    }
    return 0;
}
