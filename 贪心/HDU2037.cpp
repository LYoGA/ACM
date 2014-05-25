#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;
int n, cnt;

struct state{
    int start, end;
}s[N];

bool cmp(const state& a, const state& b) {
    return a.end < b.end;
}

int main() {
    while (scanf("%d", &n) && n) {
        cnt = 0;
        for (int i = 0; i < n; i++) 
            scanf("%d %d", &s[i].start, &s[i].end); 
        sort(s, s + n, cmp);
        int t = -1; 
        for (int i = 0; i < n; i++) {
            if (s[i].start >= t) { 
                t = s[i].end;
                cnt++; 
            } 
        }
        printf("%d\n", cnt);
    }
    return 0;
}

