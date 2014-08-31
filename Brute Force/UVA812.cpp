#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 55;

int arr[MAXN][MAXN], sum[MAXN][MAXN];
int num[MAXN], x[MAXN * MAXN + 5];
int w, b, ans, n;

vector<int> v[MAXN];

void dfs(int cnt, int s) {
    if (cnt == w) {
        x[s] = 1;   
        return;
    }
    int l = v[cnt].size();
    for (int i = 0; i < l; i++)
        dfs(cnt + 1, s + v[cnt][i]);
}

void outPut() {
    int c = 10;
    for (int i = 0; i < MAXN * MAXN; i++) {
        if (c == 0) 
            break;
        if (x[i]) { 
            printf(" %d", i); 
            c--;
        }
    } 
    printf("\n");
}

int main() {
    int t = 0;
    while (scanf("%d", &w) && w) {
        memset(sum, 0, sizeof(sum));
        memset(num, 0, sizeof(num));
        for (int i = 0; i < w; i++) {
            scanf("%d", &b);
            num[i] = b;
            for (int j = 0; j < b; j++) { 
                scanf("%d", &arr[i][j]);
                arr[i][j] = 10 - arr[i][j];
                sum[i][j] = sum[i][j - 1] + arr[i][j];
            } 
        } 
        
        ans = 0;
        for (int i = 0; i < w; i++) {
            int Max = 0;
            v[i].clear();
            v[i].push_back(0);
            for (int j = 0; j < num[i]; j++) { 
                if (sum[i][j] > Max) {
                    v[i].clear();
                    v[i].push_back(j + 1);  
                    Max = sum[i][j];
                }
                else if (sum[i][j] == Max)
                    v[i].push_back(j + 1);
            }  
            ans += Max; 
        } 

        memset(x, 0, sizeof(x));
        dfs(0, 0);

        if (t) 
            printf("\n");
        printf("Workyards %d\n", ++t);
        printf("Maximum profit is %d.\n", ans);
        printf("Number of pruls to buy:");
        outPut();
    }
    return 0;
}
