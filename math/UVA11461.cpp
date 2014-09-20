#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int vis[MAXN];

int judge(int n) {
    double a = sqrt((double)n);
    int b = (int)a;
    if (a - b < 1e-6)
        return true;
    return false;
}

int main() {
    int a, b; 
    while (scanf("%d%d", &a, &b) && (a || b)) {
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = a; i <= b; i++) {
            if (judge(i)) {
                cnt++;  
            }
        }    
        printf("%d\n", cnt);
    }
    return 0;
}
