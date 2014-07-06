#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 155;

int n, cnt, d[MAXN], G[MAXN][MAXN];

struct block{
    int x, y, z;
    void f(int a, int b, int c) {
        x = a;  
        y = b;
        z = c;
    }
}s[MAXN];

int check(int i, int j) {
    if ((s[i].x < s[j].x && s[i].y < s[j].y) || (s[i].x < s[j].y && s[i].y < s[j].x))
        return 1;
    else
        return 0;
}

int dp(int i) {
    int &ans = d[i];
    if (ans > 0)
        return ans;
    ans = s[i].z;
    for (int j = 0; j < cnt; j++) 
        if (G[i][j])
            ans = max(ans, dp(j) + s[i].z);
    return ans;
}

int main() {
    int cas = 1;
    while (scanf("%d", &n) && n) { 
        int a, b, c;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &a, &b, &c); 
            s[cnt++].f(a, b, c); 
            s[cnt++].f(a, c, b); 
            s[cnt++].f(b, c, a); 
        }
        memset(d, 0, sizeof(d));
        memset(G, 0, sizeof(G));
        for (int i = 0; i < cnt; i++) 
            for (int j = 0; j < cnt; j++) 
                G[i][j] = check(i, j);  
           
        int Max = 0;            
        for (int i = 0; i < cnt; i++) {
            int num = dp(i); 
            if (num >= Max)
                Max = num; 
        }
        printf("Case %d: maximum height = %d\n", cas++, Max);
    }    
    return 0;
}
