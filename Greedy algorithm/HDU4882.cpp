#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

struct problem{
    int time, num;
    double k;
}p[MAXN];

int n;
long long ans = 0, sum = 0;

double cmp(problem a, problem b) {
    return a.k > b.k;
}

int main() {
    scanf("%d", &n);    
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].time);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].num);
    for (int i = 0; i < n; i++)
        p[i].k = p[i].num / (p[i].time * 1.0);
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++) {
        sum += p[i].time;
        ans += sum * p[i].num; 
    }

    cout << ans << endl;
    return 0;
}
