#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

char str[MAXN], Lsy[MAXN], Rsy[MAXN], vis[MAXN];
int arr[MAXN], front[MAXN], back[MAXN];
int cnt1, cnt2, eql, Lnum, ans, flag, L, R;

int init() {
    cnt1 = 1, cnt2 = eql = L = R = 0;
    int l = strlen(str), sum = 0; 
    sscanf(str, "%d", &arr[0]);
    sum = arr[0];
    for (int i = 0; i < l; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '=') {
            if (str[i] == '=')
                eql = i;
            if (!eql) {
                Lsy[L] = str[i];
                L++;
            }
            else if (eql != i) {
                Rsy[R] = str[i];
                R++;
            }
            sscanf(str + i + 1, "%d", &arr[cnt1]);
            sum += arr[cnt1++];
        } 
    }

    Lnum = 1;
    for (int i = 0; i < l; i++) {
        if (i < eql && str[i] == '+') 
            Lnum++;
        else if (i > eql && str[i] == '-')
            Lnum++; 
    }
    return sum;
}

int dfs(int k, int pos, int cur) {
    if (k == Lnum) {
        if (cur == ans)  
            return true;
        return false;
    }
    if (Lnum - k > cnt1 - pos)
        return false;
    if (pos < cnt1 && cur + arr[pos] <= ans) {
        vis[pos] = 1; 
        if (dfs(k + 1, pos + 1, cur + arr[pos])) 
            return true;
        vis[pos] = 0;
    }
    if (pos < cnt1 && dfs(k, pos + 1, cur)) 
        return true;
    return false;
}

void outPut() {
    int x = 0, y = 0;
    for (int i = 0; i < cnt1; i++) {
        if (vis[i]) 
            front[x++] = arr[i];
        else
            back[y++] = arr[i]; 
    }

    printf("%d", front[--x]);
    for (int i = 0; i < L; i++) {
        printf(" %c ", Lsy[i]); 
        if (Lsy[i] == '+')
            printf("%d", front[--x]);
        if (Lsy[i] == '-')
            printf("%d", back[--y]); 
    }
    printf(" = ");
    printf("%d", back[--y]); 
    for (int i = 0; i < R; i++) {
        printf(" %c ", Rsy[i]); 
        if (Rsy[i] == '+')
            printf("%d", back[--y]);  
        if (Rsy[i] == '-')
            printf("%d", front[--x]);
    }
    printf("\n");
}

int main() {
    while (gets(str)) {
        int s = init(); 
        if (s % 2)
            printf("no solution\n");
        else {
            ans = s / 2;
            memset(vis, 0, sizeof(vis));
            if (dfs(0, 0, 0))
                outPut();  
            else 
                printf("no solution\n");
        }
    }    
    return 0;
}

