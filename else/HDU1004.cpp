#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1005;

char s[N][20], ans[20];

int main() {
    int n, max;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) 
            scanf("%s", s[i]);         
        max = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(s[i], s[j]) == 0) 
                    cnt++; 
            } 
            if (cnt >= max) {
                max = cnt;
                strcpy(ans, s[i]); 
            }
        }
        printf("%s\n", ans);
    }
    return 0;
}
