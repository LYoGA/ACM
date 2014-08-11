#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
const char dirName[][10] = {"L", "Turning", "R"};

struct Ant{
    int id;
    int p;
    int d;
    bool operator < (const Ant& a) const {
        return p < a.p; 
    }
}before[MAXN], after[MAXN];

int order[MAXN];

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        int L, T, n; 
        printf("Case #%d:\n", t++);
        scanf("%d%d%d", &L, &T, &n);
        for (int i = 0; i < n; i++) {
            int p, d; 
            char c;
            scanf("%d %c", &p, &c);
            d = (c == 'L' ? -1 : 1);
            before[i].id = i;
            before[i].p = p;
            before[i].d = d;
            after[i].id = 0; 
            after[i].p = p + T * d; 
            after[i].d = d; 
        }

        sort(before, before + n);
        for (int i = 0; i < n; i++)
            order[before[i].id] = i;

        sort(after, after + n);
        for (int i = 0; i < n - 1; i++)
            if (after[i].p == after[i + 1].p)
                after[i].d = after[i + 1].d = 0;

        for (int i = 0; i < n; i++) {
            int a = order[i];  
            if (after[a].p < 0 || after[a].p > L)
                printf("Fell off\n");
            else
                printf("%d %s\n", after[a].p, dirName[after[a].d + 1]); 

        }  
        printf("\n");
    }
    return 0;
}
