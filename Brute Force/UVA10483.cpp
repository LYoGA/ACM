#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

struct state{
    double sum, x, y, z;
}ans[MAXN];

double a, b;
int n, m, cnt;

int cmp(state a, state b) {
    if (a.sum != b.sum)
        return a.sum < b.sum;
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y < b.y;
    if (a.z != b.z)
        return a.z < b.z;
}

int judge(int i, int j, int k) {
    int sum = i + j + k;
    int mul = i * j * k;
    if (sum != mul / 10000)
        return false;
    if (mul % 10000)
        return false;
    mul /= 10000;
    if (sum < n || sum > m || mul < n || mul > m)
        return false;
    return true;    
}

void outPut() {
    sort(ans, ans + cnt, cmp);
    for (int i = 0; i < cnt; i++)
        printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n", 
                ans[i].sum, ans[i].x, ans[i].y, ans[i].z, ans[i].x, ans[i].y , ans[i].z);
}

int main() {
    while (scanf("%lf%lf", &a, &b) != EOF) {
        n = (int)(a * 100); 
        m = (int)(b * 100); 
        cnt = 0;
        for (int i = 1; (i * i * i) <= m * 10000; i++) {
            for (int j = i; (i * j * j) <= m * 10000; j++) {
                int sum = i + j; 
                int mul = i * j;
                if (mul <= 10000)
                    continue;
                int k = sum * 10000 / (mul - 10000);
                if (k < j)
                    continue;
                if (!judge(i, j, k))
                   continue;
                ans[cnt].sum = (i * j * k * 1.0) / 1000000;
                ans[cnt].x = (i * 1.0) / 100;
                ans[cnt].y = (j * 1.0) / 100;
                ans[cnt].z = (k * 1.0) / 100;
                cnt++;
            } 
        } 
        outPut();
    }     
    return 0;
}
