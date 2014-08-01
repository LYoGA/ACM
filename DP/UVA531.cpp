#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

char s1[MAXN][MAXN], s2[MAXN][MAXN], s[MAXN];
int d[MAXN][MAXN], path[MAXN][MAXN];
int cnt1, cnt2, flag;

void init() {
    cnt1 = 0;
    strcpy(s1[cnt1++], s);    
    while (scanf("%s", s1[cnt1])) {
        if (strcmp(s1[cnt1], "#") == 0) 
            break;
        cnt1++; 
    } 
    cnt2 = 0;
    while (scanf("%s", s2[cnt2])) {
        if (strcmp(s2[cnt2], "#") == 0) 
            break;
        cnt2++; 
    } 
    flag = 0;
}

void LCSL(int l1, int l2) {
    memset(d, 0,sizeof(d));
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (strcmp(s1[i - 1], s2[j - 1]) == 0) {
                d[i][j] = d[i - 1][j - 1] + 1;  
                path[i][j] = 1;
            }
            else {
                if (d[i - 1][j] > d[i][j - 1]) {
                    d[i][j] = d[i - 1][j];
                    path[i][j] = 0;
                }
                else {
                    d[i][j] = d[i][j - 1];
                    path[i][j] = -1;
                }    
            }
        }  
    }
}

void outPut(int i, int j) {
    if (!i || !j)
        return;
    if (path[i][j] == 1) {
        outPut(i - 1, j - 1);
        if (flag)
            printf(" ");
        else
            flag = 1; 
        printf("%s", s1[i - 1]); 
    }
    else if (path[i][j] == 0)
        outPut(i - 1, j);
    else
        outPut(i, j - 1);
}

int main() {
    while (scanf("%s", s) != EOF) {
        init();
        LCSL(cnt1, cnt2);    
        outPut(cnt1, cnt2);
        printf("\n");
    }
    return 0;
}
