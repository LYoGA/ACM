#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1005;

char str[MAXN]; 
int vis[MAXN], num[MAXN];
int len;

int judge() {
    memset(num, 0, sizeof(num));
    for (int i = 0; i < len; i++) { 
        num[str[i] - 'a']++;
    }
    int cnt = 0;
    for (int i = 0; i < 27; i++) 
        if (num[i] % 2)
            cnt++;

    if (cnt > 1)
        return 0;
    return 1;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", str);
        len = strlen(str);
        if (!judge())
            printf("Impossible\n");
        else {
            int left = 0, right = len - 1, cnt = 0;
            while (left < right) {
                int lcur = left, rcur = right, temp, Min = INF;
                memset(vis, 0, sizeof(vis));
                for (int i = left; i < right; i++) 
                    if (!vis[i]) {
                        vis[i] = 1;
                        int lastcur = i;
                        for (int j = i + 1; j <= right; j++) 
                            if (str[i] == str[j]) {
                                vis[j] = 1;
                                lastcur = j;
                            }

                        int temp = i - left + right - lastcur;
                        if (temp < Min) {
                            Min = temp; 
                            lcur = i; 
                            rcur = lastcur;
                        }
                    }

                for (int i = lcur; i > left; i--) {
                    swap(str[i], str[i - 1]); 
                    cnt++; 
                }
                for (int i = rcur; i < right; i++) {
                    swap(str[i], str[i + 1]); 
                    cnt++; 
                } 
                left++;
                right--;
            }

            printf("%d\n", cnt);
        } 
    }
    return 0; 
}
