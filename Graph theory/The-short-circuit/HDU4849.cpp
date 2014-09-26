#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const long long INF = 0x03F3F3F3F;

long long x[MAXN * MAXN], y[MAXN * MAXN], z[MAXN * MAXN], d[MAXN * MAXN], g[MAXN][MAXN];
long long  n, m, x0, x1, y0, y1, v[MAXN * MAXN], M[MAXN * MAXN];

void init() {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(z, 0, sizeof(z));
    memset(g, 0, sizeof(g));
    x[0] = x0;
    x[1] = x1;
    y[0] = y0;
    y[1] = y1;
    int k = n * n;
    for (int i = 2; i < k; i++)
        x[i] = (12345 + (x[i - 1] * 23456) % 5837501 + (x[i - 2] * 34567) % 5837501 + ((x[i - 1] % 5837501) * (x[i - 2] % 5837501) * 45678) % 5837501) % 5837501;
    for (int i = 2; i < k; i++) 
        y[i] = (56789 + (y[i - 1] * 67890) % 9860381 + (y[i - 2] * 78901) % 9860381 + ((y[i - 1] % 9860381) * (y[i - 2] % 9860381) * 89012) % 9860381) % 9860381;
    for (int i = 0; i < k; i++)
        z[i] = (x[i] * 90123 % 8475871 + y[i]) % 8475871 + 1;    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) 
                continue;
            else {
                g[i][j] = z[n * i + j]; 
            }  
        } 
}

void Dijkstra() {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    memset(M, 0, sizeof(M)); 
    for (int i = 0; i < n; i++) 
        d[i] = (i == 0 ? 0 : INF);
    for (int i = 0; i < n; i++) {
        int a;
        long long b = INF; 
        for (int y = 0; y < n; y++)
            if (!v[y] && d[y] <= b)
                b = d[a = y];
        v[a] = 1;
        for (int y = 0; y < n; y++)
            d[y] = min(d[y], d[a] + g[a][y]); 
    }
}

int main() {
    while (cin >> n >> m >> x0 >> x1 >> y0 >> y1) {
        init();
        Dijkstra();

        long long p, Min = INF, ans = INF; 
        for (int i = 1; i < n; i++) {
            M[d[i] % m] = 1;
        }
        for (long long i = 0; i < m; i++) {
            if (M[i]) {
                p = i; 
                break;
            }
        }
        cout << p << endl;
    }    
    return 0;
}
