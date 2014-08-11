#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

struct node{
    int x, y;
}a[MAXN];

int arr[MAXN], b[MAXN], order[MAXN];
int n;

int cmp(node a, node b) {
    return a.y < b.y;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i].x); 
            if (a[i].x < 0)
                a[i].y = abs(a[i].x);
            else
                a[i].y = a[i].x;
        }
        sort(a, a + n, cmp);

        int cnt = 1, flag ;
        if (a[0].x == a[0].y)
            flag = 1;
        else
            flag = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].x == a[i].y && !flag) {
                flag = 1; 
                cnt++;
            } 
            else if (a[i].x != a[i].y && flag) {
                flag = 0; 
                cnt++; 
            } 
        }
        printf("%d\n", cnt); 
    }
    return 0;
}
