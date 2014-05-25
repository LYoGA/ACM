#include <iostream>
#include <cstdio>
#include <cstring>
#define N 22

using namespace std;

int map[N][N], vis[N], arr[N], v[N];
int n, a, b, cnt, count, k = 1;

void judge(int n) {
    v[n] = 1;
    for (int i = 1; i < N; i++)
        if(map[n][i] && !v[i])
            judge(i);
}

void dfs(int x) {
    if (x == n){
        cnt++;
        for (int i = 0; i < count - 1; i++)
            printf("%d ", arr[i]);
        printf("%d\n", arr[count - 1]);
        return;
    }
    for (int i = 1; i < N; i++) {
        if ((map[x][i] || map[i][x]) && !vis[i] && v[i]) {
                arr[count++] = i;
                vis[i] = 1;
                dfs(i);
                vis[i] = 0;
                count--; 
        }  
    } 
}

int main() {
    while (scanf("%d", &n)) {
        memset(vis, 0, sizeof(vis));
        memset(map, 0, sizeof(map));
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        count = 0;

        while (scanf("%d %d", &a, &b) && a && b) {
            map[a][b] = 1; 
            map[b][a] = 1;
        }  
        vis[1] = 1;
        arr[count++] = 1;
        judge(n);
        printf("CASE %d:\n", k++);
        dfs(1);
        printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, n);
    }
    return 0;
}
