#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 55;

char s1[MAXN], s2[MAXN];
int d[MAXN][MAXN]; 
long long f[MAXN][MAXN];

void dp(int l1, int l2) {
    for (int i = 1; i <= l1; i++) { 
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) { 
                d[i][j] = d[i - 1][j - 1] + 1; 
                f[i][j] = f[i - 1][j - 1];         
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]); 
                if (d[i - 1][j] > d[i][j - 1])
                    f[i][j] = f[i - 1][j];
                else if (d[i - 1][j] <d[i][j - 1])
                    f[i][j] = f[i][j - 1];
                else
                    f[i][j]= f[i - 1][j] + f[i][j - 1];
            }
        }
    }
}

int main() {
    int cas, t = 1; 
    scanf("%d", &cas);
    getchar();
    while (cas--) {
        gets(s1); 
        gets(s2);
       // scanf("%s %s", s1, s2); 
        int l1 = strlen(s1); 
        int l2 = strlen(s2);
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(d));
        for (int i = 0; i < MAXN; i++) {
            f[0][i] = f[i][0] = 1; 
        }
        dp(l1, l2);
        int ans = l1 + l2 - d[l1][l2];
        printf("Case #%d: %d %lld\n", t++, ans, f[l1][l2]); 
    }
    return 0;
}
