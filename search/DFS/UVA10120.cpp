#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, flag;

void dfs(int cur, int d) {
    if (flag)
        return;
    if (cur == m) {
        flag = 1; 
        return;
    }
    int step = 2 * (d + 1) - 1;
    if (cur + step <= n && cur + step >= 1) {
        dfs(cur + step, d + 1);
    }
    if (cur - step >= 1 && cur - step <= n) {
        dfs(cur - step, d + 1);
    }
    return;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        if (m == 0 && n == 0)
            break;
        if (n >= 50) {
            printf("Let me try!\n");
            continue;
        }
        flag = 0; 
        dfs(1, 1);
        if (flag) 
            printf("Let me try!\n");
        else
            printf("Don't make fun of me!\n"); 
    }
    return 0;
}
