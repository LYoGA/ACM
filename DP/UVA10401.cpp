#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int MAXN = 20;

char str[MAXN];
long long d[MAXN][MAXN], ans;
int len;

int change(char c) {
    if (isdigit(c)) 
        return c - '0';
    if (isalpha(c))
        return c - 'A' + 10;
}

void init() {
    if (str[0] == '?')
        for (int i = 1; i <= len; i++)
            d[1][i] = 1;
    else 
        d[1][change(str[0])] = 1;
}

void dp() {
    for (int i = 2; i <= len; i++) {
        if (str[i - 1] == '?') {
            for (int j = 1; j <= len; j++) {
                for (int k = 1; k <= len; k++)  
                    if (abs(k - j) > 1)
                        d[i][j] += d[i - 1][k]; 
            } 
        } 
        else {
            int cur = change(str[i - 1]); 
            for (int k = 1; k <= len; k++) 
                if (abs(k - cur) > 1)
                    d[i][cur] += d[i - 1][k]; 
        }  
    }
}

int main() {
    while (scanf("%s", str) != EOF) {
        len = strlen(str);  
        memset(d, 0, sizeof(d));
        init();
        dp();
        ans = 0;
        for (int i = 1; i <= len; i++) 
            ans += d[len][i];
        printf("%lld\n", ans);
    }
    return 0;
}
