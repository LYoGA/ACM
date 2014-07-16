#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1005;

int d[MAXN][MAXN], w1[MAXN], w2[MAXN];
int n, S;

int dp() {
    for (int i = 0; i < n; i++)
        for (int v1 = w1[i]; v1 <= S; v1++) 
            for (int v2 = w2[i]; v2 <= S; v2++) 
                if (d[v1 - w1[i]][v2 - w2[i]] != INF) 
                    d[v1][v2] = min(d[v1][v2], d[v1 - w1[i]][v2 - w2[i]] + 1); 

    int ans = INF; 
    int temp = S * S;
    for (int i = 0; i <= S; i++)
        for (int j = 0; j <= S; j++) 
            if (i * i + j * j == temp && d[i][j] != INF) 
                if (ans > d[i][j])
                    ans = d[i][j];        

    return ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &n, &S);    
        for (int i = 0; i < n; i++)
            scanf("%d %d", &w1[i], &w2[i]);
        for (int i = 0; i <= S; i++)
            for (int j = 0; j <= S; j++)
                d[i][j] = INF;
        d[0][0] = 0;
        int num = dp();
        if (num != INF)
            printf("%d\n", num);
        else
            printf("not possible\n");
    }
    return 0;
}
