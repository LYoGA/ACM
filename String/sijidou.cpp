#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 105;

char s[N][N];
char a[N] = "lizhirou";
char b[N] = "sijidou";
char ans[N];

int  main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) 
            scanf("%s", s[i]);
        for (int i = 0; i < n; i++) {
            int l = strlen(s[i]); 
            for (int j = 0; j < l; j++) {
                for (int k = j, o = 0; o < 8; o++, k++) {
                    ans[o] = s[i][k]; 
                } 
                if (strcmp(ans, a) == 0) {
                    printf("%s", b); 
                    j += 7;
                } 
                else 
                    printf("%c", s[i][j]);
            }       
            printf("\n"); 
        } 
    }
    return 0;
}
