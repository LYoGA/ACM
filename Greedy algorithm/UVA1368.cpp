#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int N = 55;

char str[N][MAXN], s[MAXN];
int m, n, Min;
int num[4];

int Max(int a, int c, int g, int t) {
    return max(a, max(c, max(g, t)));
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &m, &n); 
        for (int i = 0; i < m; i++)
            scanf("%s", str[i]);
        Min = 0;
        int a, c, g, t;
        for (int i = 0; i < n; i++) { 
            a = c = g = t = 0;
            for (int j = 0; j < m; j++) {
                if (str[j][i] == 'A')
                    a++;
                else if (str[j][i] == 'C')
                    c++;
                else if (str[j][i] == 'G')
                    g++;
                else if (str[j][i] == 'T')
                    t++; 
            }
            int k = Max(a, c, g, t);
            Min += m - k;
            if (k == a) 
                s[i] = 'A';
            else if (k == c) 
                s[i] = 'C';
            else if (k == g) 
                s[i] = 'G';
            else if (k == t) 
                s[i] = 'T'; 
        }
        s[n] = '\0';
        printf("%s\n",s);
        printf("%d\n", Min);

    }
    return 0;
}
