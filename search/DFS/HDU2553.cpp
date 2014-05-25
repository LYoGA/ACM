#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 15;

int n, num, m;
int vis[N], q[N];

void find(int cur) {
    if (cur == m) {
        num++;
        return; 
    }
    else {
        for (int i = 0; i < m; i++) {
            int ok = 1; 
            vis[cur] = i;   
            for (int j = 0; j < cur; j++) {
                if (vis[cur] ==vis[j] || cur - vis[cur] == j - vis[j] || cur + vis[cur] == j + vis[j]) { 
                    ok = 0;
                    break;
                }
            }
            if (ok)
                find(cur + 1);
        } 
    }
}

int main() {
    for (m = 1; m <= 10; m++) {
        num = 0; 
        find(0);
        q[m] = num;
    }
    while (scanf("%d", &n) && n) {
        printf("%d\n", q[n]); 
    }
    return 0;
}
