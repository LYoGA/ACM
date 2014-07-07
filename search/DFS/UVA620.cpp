#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 105;

char str[MAXN];

int dfs(int b, int e) {
    if (b == e && str[b] == 'A')
        return 1;
    if (e - b >= 1 && str[e] == 'A' && dfs(b, e - 1))
        return 1;
    if (e - b >= 2 && str[e] == 'B' && str[e - 1] == 'A' && dfs(b, e - 2))
        return 2;
    if (e - b >= 2 && str[b] == 'B' && str[e] == 'A' && dfs(b + 1, e - 1))
        return 3;
    return 0;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", str); 
        int len = strlen(str);
        int ans = dfs(0, len - 1);
        if (ans == 1)
            printf("SIMPLE\n");
        else if (ans == 2)
            printf("FULLY-GROWN\n");
        else if (ans == 3)
            printf("MUTAGENIC\n");
        else
            printf("MUTANT\n");
    }
    return 0;
}

