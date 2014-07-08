#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 505;

char name[6][20] = {"front", "back", "left", "right", "top", "bottom"};
int d[MAXN][6]; 
int n, ans;

struct cube{
    int v[6];
}c[MAXN];

struct box{
    int num;
    int tname;
}save[MAXN], put[MAXN];

void dp(int now, int top, int cnt) {
    for (int i = now + 1; i <= n; i++)
        for (int j = 0; j < 6; j++) {
            if (now == 0 || (c[i].v[j] == top && d[i][j] < cnt + 1)) {
                d[i][j] = cnt + 1; 
                if (j % 2) {
                    save[cnt].num = i; 
                    save[cnt].tname = j; 
                    dp(i, c[i].v[j - 1], cnt + 1);
                } 
                else {
                    save[cnt].num = i;
                    save[cnt].tname = j;
                    dp(i, c[i].v[j + 1], cnt + 1); 
                }
            }   
        } 
    if (ans < cnt) {
        ans = cnt;  
        for (int i = 0; i < cnt; i++)
            put[i] = save[i];
    }    
}

int main() {
    int t = 0;
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) 
            for (int j = 0; j < 6; j++)
                scanf("%d", &c[i].v[j]);
        memset(d, 0, sizeof(d)); 
        ans = 0;
        dp(0, 0, 0);
        if (t++)
            printf("\n");
        printf("Case #%d\n", t);
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++)
            printf("%d %s\n", put[i].num, name[put[i].tname]);
    } 
    return 0;
}
