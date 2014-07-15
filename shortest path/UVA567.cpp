#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N =25;
const int INF = 1 << 20;
int d[N][N], n;

void init() {
    for (int i = 1; i < N; i++) {
        d[i][i] = 0; 
        for (int j = i + 1; j < N; j++) 
            d[i][j] = d[j][i] = INF;
    }
    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a); 
        d[1][a] = d[a][1] = 1;
    }
    for (int i = 2; i <= 19; i++) {
        scanf("%d", &n); 
        for (int j = 0; j < n; j++) {
            scanf("%d", &a); 
            d[i][a] = d[a][i] = 1;
        }  
    }
}

void Floyd() {
    for (int k = 1; k <= 20; k++)
       for (int i = 1; i <=20; i++) 
           for (int j = 1; j <=20; j++)
               if (d[i][k] != INF && d[k][i] != INF) 
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b); 
        printf("%2d to %2d: %d\n", a, b, d[a][b]); 
    }
}

int main() {
    int cas = 0;
    while (scanf("%d", &n) != EOF) {
        init(); 
        Floyd(); 
        printf("Test Set #%d\n", ++cas); 
        solve();
        printf("\n");
    }

}
