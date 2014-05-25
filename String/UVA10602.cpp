#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 105

using namespace std;

char s[N][N], str[N][N], ans[N];

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n, num = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
            scanf("%s", s[i]);
        
        qsort(s, n, sizeof(s[0]), cmp); 
        num = strlen(s[0]);
        int i, k;
        for (i = 1; i < n; i++) {
                for (k = 0; k < strlen(s[i]); k++) {
                     if (s[i][k] != s[i - 1][k])  
                        break; 
                }      
                num += strlen(s[i]) - k;
        }        
        printf("%d\n", num);
        for (int i = 0; i < n; i++) 
                printf("%s\n", s[i]); 
    }
    return 0;
}

