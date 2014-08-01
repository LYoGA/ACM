#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

struct jogger{
    int A, B;
}p[MAXN];

int vis[MAXN * 2 + 5];
int k, n, cnt;

int cmp(jogger a, jogger b) {
    if (a.B != b.B)
        return a.B < b.B;
    return a.A > b.A;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &k, &n); 
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].A, &p[i].B); 
            p[i].A += MAXN;
            p[i].B += MAXN;
            if (p[i].A > p[i].B)
                swap(p[i].A, p[i].B);
        }

        cnt = 0;
        memset(vis, 0, sizeof(vis));
        sort(p, p + n, cmp); 
        for (int i = 0; i < n; i++) {
            if (p[i].B - p[i].A <= k - 1) {
                for (int j = p[i].A; j <= p[i].B; j++) 
                    if (!vis[j]) {
                        vis[j] = 1; 
                        cnt++; 
                    }  
            }
            else {
                int temp = 0;         
                for (int j = p[i].A; j <= p[i].B; j++) 
                    if (vis[j])
                        temp++;
                if (temp >= k) 
                    continue;
                for (int j = p[i].B; j >= p[i].A; j--) {
                    if (!vis[j]) {
                        vis[j] = 1; 
                        cnt++;
                        temp++;
                    }                 
                    if (temp >= k)
                        break;
                }
            }
        }

        printf("%d\n", cnt);
         for (int i = 0; i < MAXN * 2 + 5; i++)
             if (vis[i] && cnt) {
                 printf("%d\n", i - MAXN); 
                 cnt--;
             }
         if (cas)
             printf("\n");
    }
    return 0;
}
