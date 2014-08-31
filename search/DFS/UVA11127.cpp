#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 32;

char str[MAXN];
int n, ans;

bool judge(int s, int d) {
    int k = (1 << d) - 1;
    int a = s & k;
    s = s >> d;
    int b = s & k;
    s = s >> d;
    int c = s & k;
    if (a == b && b == c)
        return true;
    else
        return false;
}//利用位运算，右移d位，判断是否存在3个子串相同

void dfs(int s, int cnt) {
    int num = cnt / 3;  
    int t = n - cnt - 1;
    for (int i = 1; i <= num; i++) {
        if (judge(s >> (t + 1), i)) 
            return;
    }
    if (cnt == n) {
        ans++;
        return;
    }
    else if (str[cnt] == '0') {
         dfs(s, cnt + 1);
    }
    else if (str[cnt] == '1') {
         dfs(s + (1 << t), cnt + 1);
    }
    else if (str[cnt] == '*') {
         dfs(s, cnt + 1);
         dfs(s + (1 << t), cnt + 1);  
    }
    return;
}

int main() {
    int cas = 1;
    while (scanf("%d", &n) && n) {
        scanf("%s", str);
        ans = 0;
        dfs(0, 0); 
        printf("Case %d: %d\n", cas++, ans);
    }    
    return 0;
}
