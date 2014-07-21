#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

char s1[MAXN], s2[MAXN], str1[MAXN][MAXN], str2[MAXN][MAXN];
int d[MAXN][MAXN];

int dp(int l1, int l2) {
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (strcmp(str1[i - 1], str2[j - 1]) == 0) 
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }  
    }
    return d[l1][l2];
}

int main() {
    int t = 1;
    while (gets(s1) != NULL) {
        gets(s2); 
        int l1 = strlen(s1); 
        int l2 = strlen(s2);
        int num1 = 0, num2 = 0, cnt = 0;
        for (int i = 0; i <= l1; i++) {
            if (isalpha(s1[i]) || isdigit(s1[i])) {
                str1[num1][cnt++] = s1[i]; 
            } 
            else {
                if (isalpha(s1[i - 1]) || isdigit(s1[i - 1])) {
                    str1[num1][cnt] = '\0'; 
                    num1++; 
                    cnt = 0;
                }
            } 
        }

        cnt = 0; 
        for (int i = 0; i <= l2; i++) {
            if (isalpha(s2[i]) || isdigit(s2[i])) {
                str2[num2][cnt++] = s2[i]; 
            } 
            else {
                if (isalpha(s2[i - 1]) || isdigit(s2[i - 1])) {
                    str2[num2][cnt] = '\0'; 
                    num2++; 
                    cnt = 0;
                }
            } 
        }

        memset(d, 0, sizeof(d));
        int ans = dp(num1, num2);
        if (ans)
            printf("%2d. Length of longest match: %d\n", t++, ans);
        else
            printf("%2d. Blank!\n", t++);
    }    
    return 0; 
}
