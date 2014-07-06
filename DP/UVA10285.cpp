#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

char name[MAXN];
int map[MAXN][MAXN], d[MAXN][MAXN];
int r, c;

int dp(int x, int y) {
    int& ans = d[x][y];
    if (ans > 0)
        return ans;
    ans = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i]; 
        int ty = y + dy[i];
        if (tx >= 0 && tx < r && ty >= 0 && ty < c && map[x][y] > map[tx][ty]) { 
            ans = max(ans, dp(tx, ty) + 1); 
        } 
    }
    return ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s %d %d", name, &r, &c); 
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++)
                scanf("%d", &map[i][j]);
        memset(d, 0, sizeof(d));
        int Max = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                int num = dp(i, j); 
                if (num >= Max) 
                    Max = num;
            }
        printf("%s: %d\n", name, Max);
    }
    return 0;
}
