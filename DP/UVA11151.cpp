#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

char str[MAXN];
int d[MAXN][MAXN];

int main() {
    int cas;
    scanf("%d", &cas);
    getchar();
    while (cas--) {
        gets(str);
        int l = strlen(str);
        memset(d, 0, sizeof(d));
        for (int i = 0; i < l; i++)
            d[i][i] = 1;
        for (int i = l - 1; i >= 0; i--) 
            for (int j = i + 1; j < l; j++) {
                if (str[i] == str[j] && i != j)           
                    d[i][j] = d[i + 1][j - 1] + 2;   
                else 
                    d[i][j] = max(d[i + 1][j], d[i][j - 1]);
            } 
        printf("%d\n", d[0][l - 1]);
    }
    return 0;
}

