#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 205;
int vis[N];

int main() {
    int cas;
    int time;
    scanf("%d", &cas);
    while (cas--) {
        int n;
        int min = 0;
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a = (a - 1) / 2;
            b = (b - 1) / 2;
            if (a > b) 
                swap(a, b);
            for (int i = a; i <= b; i++) {
                vis[i]++; 
                if (vis[i] > min)
                    min = vis[i]; 
            }
         
        }  
        printf("%d\n", min * 10);
    }
    return 0;
}
