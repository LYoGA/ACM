#include <stdio.h>
#include <string.h>
#define N 705
using namespace std;

struct point{
    int x, y;
}p[N];

int vis[N][N], mark[N];
char str[50];

int cas, max, cnt, ans;  
int i, j, k, l;

int main () {
    scanf("%d", &cas);
    getchar();
    getchar();
    while (cas--) {
        max = 0, cnt = 0;  
        memset(vis, 0, sizeof(vis)); 
        memset(mark, 0, sizeof(mark));

        while (gets(str) && str[0] != '\0') {
            sscanf(str, "%d%d", &p[cnt].x, &p[cnt].y); 
            cnt++;
        }
        for (i = 0; i < cnt; i++) {
            for (j = i + 1; j < cnt; j++) {   
                if (vis[i][j])  continue;
                ans = 0; 
                for (k = 0; k < cnt; k++) 
                    if (p[k].y * (p[i].x - p[j].x) == (p[i].y - p[j].y) * p[k].x + p[j].y * p[i].x - p[i].y * p[j].x) {
                        mark[ans++] = k;                
                        for (l = 0; l < ans - 1; l++)
                            vis[mark[l]][k] = vis[k][mark[l]] = 1;
                }
                if (max < ans)
                    max = ans;
            }
        } 
        printf("%d\n", max);
        if (cas)
            printf("\n");
    }
    return 0;
}
