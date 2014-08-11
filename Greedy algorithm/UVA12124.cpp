#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int cnt;
map<string, int> id;
int ID(string s) {
    if (!id.count(s))
        id[s] = cnt++;
    return id[s];
}

struct Component {
    int price;
    int quality;
};
int n, b;
vector<Component> comp[MAXN];

bool ok(int q) {
    int sum = 0;
    for (int i = 0; i < cnt; i++) {
        int cheapest = b + 1, m = comp[i].size(); 
        for (int j = 0; j < m; j++) 
            if (comp[i][j].quality >= q)
                cheapest = min(cheapest, comp[i][j].price);
        if (cheapest == b + 1)
            return false;
        sum += cheapest;
        if (sum > b) 
            return false;
    }
    return true;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &b); 
    
        cnt = 0;
        for (int i = 0; i < n; i++)
            comp[i].clear();
        id.clear();

        int maxq = 0;
        for (int i = 0; i < n; i++) {
            char type[30], name[30]; 
            int p, q;
            scanf("%s%s%d%d", type, name, &p, &q);
            maxq = max(maxq, q);
            comp[ID(type)].push_back((Component){p, q});
        }
        
        int L = 0, R = maxq;
        while (L < R) {
            int mid = L + (R - L + 1) / 2; 
            if (ok(mid)) 
                L = mid;
            else
                R = mid - 1;
        
        }
        printf("%d\n", L);
        printf("%d\n", num);

    }
    return 0;
}
