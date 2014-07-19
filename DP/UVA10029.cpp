#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 25005;

struct String{
    char s[20];
    int len;
}str[MAXN];

int d[MAXN];
int cnt = 1;

int check(int n, int m) {
    int flag = 0;
    if (str[n].len == str[m].len) {
        for (int i = 0; i < str[n].len; i++) {  
            if (str[n].s[i] != str[m].s[i]) {
                if (flag)  
                    return 0;
                else
                    flag = 1; 
            }
        }
        if (flag)
            return 1; 
    }
    else if (str[n].len == str[m].len + 1) {
        for (int i = 0, j = 0; i < str[n].len; i++) {
            if (str[n].s[i] != str[m].s[j]) {
                if (flag) 
                    return 0;
                else
                    flag = 1;
                continue;
            }   
            j++;
        } 
        if (flag)
            return 1;
    }
    else if (str[n].len == str[m].len - 1) {
        for (int i = 0, j = 0; i < str[m].len; i++) {
            if (str[n].s[j] != str[m].s[i]) {
                if (flag) 
                    return 0;
                else
                    flag = 1;
                continue;
            }   
            j++;
        } 
        if (flag)
            return 1; 
    }
    else
        return 0;
}

int dp() {
    int Max = 0;
    for (int i = 1; i < cnt; i++) {
        d[i] = 1;
        for (int j = 1; j < i; j++) 
            if (check(i, j)) {
                d[i] = max(d[i], d[j] + 1);
                Max = max(Max, d[i]); 
            }
    }
    return Max;
}

int main() {
    while (gets(str[cnt].s) != NULL) { 
        str[cnt].len = strlen(str[cnt].s);
        cnt++; 
    }

    memset(d, 0, sizeof(d));
    int ans = dp(); 
    printf("%d\n", ans);
    return 0;
}
