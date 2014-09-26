#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 50005;

int f[N], rank[N];
int n;

void init() {
    for (int i = 1; i <= n; i++) {
        f[i] = i; 
        rank[i] = 0;
    } 
}

int find(int x) {
    int t;
    if (x != f[x]) {
        t = f[x]; 
        f[x] = find(f[x]); 
        rank[x] = (rank[x] + rank[t]) % 3;
    }
    return f[x];
}

void Union(int d, int x, int y, int fx, int fy) {
    f[fy] = fx;
    rank[fy] = (rank[x] - rank[y] + 3 + d - 1) % 3;
}

int main() {
    int k, cnt = 0; 
    int x, y, d, f1, f2; 
    scanf("%d %d", &n, &k);
    init(); 
    while(k--) {
        scanf("%d%d%d", &d, &x, &y); 
        if (x > n || y > n) 
            cnt++; 
        else if (d == 2 && x == y)
            cnt++;
        else {
            f1 = find(x); 
            f2 = find(y);
            if (f1 == f2) {
                if (d == 1 && rank[x] != rank[y]) 
                    cnt++;
                else {
                    if (d == 2 && rank[y] != (rank[x] + 1) % 3) 
                        cnt++; 
                }  
            } 
            else 
                Union(d, x, y, f1, f2);
        }
        printf("%d\n", cnt);


    }
    return 0;
}



