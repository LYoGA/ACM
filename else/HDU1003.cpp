#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1005;

struct node{
    int x1, y1, x2, y2, r, g, b;
}s[N];

int n, m, flag;
int R, G, B;

void init() {
    for (int i = 0; i < N; i++) 
        s[i].r = s[i].g = s[i].b = 255;
}

void solve(int a, int b) {
    R = G = B = 255;
    for (int i = 0; i < n; i++) {
        if (a >= s[i].x1 && a <= s[i].x2 && b >= s[i].y1 && b <= s[i].y2) {
            R = s[i].r;
            G = s[i].g;
            B = s[i].b;
        }
    }
}

int main () {
    while (scanf("%d %d", &n, &m) && n && m) {
        init();
        for (int i = 0; i < n; i++) 
            scanf("%d %d %d %d %d %d %d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2, &s[i].r, &s[i].g, &s[i].b);
        for (int i = 0; i < m; i++) {
            int a, b; 
            scanf("%d %d", &a, &b);
            solve(a, b);
            printf("%d %d %d\n", R, G, B);
        } 
    }
    return 0;
}





