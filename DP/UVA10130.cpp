#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int d[MAXN], p[MAXN], w[MAXN]; 
int n, g;

void dp() {
    for (int i = 0; i < n; i++) 
        for(int j = 30; j >= w[i]; j--) 
            if (d[j] < d[j - w[i]] + p[i])  
                d[j] = d[j - w[i]] + p[i];
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n); 
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i], &w[i]);
        scanf("%d", &g);
        int m, sum = 0;
        memset(d, 0, sizeof(d));
        dp();
        for (int i = 0; i < g; i++) {
            scanf("%d", &m); 
            sum += d[m];
        }
        printf("%d\n", sum);
    }
    return  0;
}
