#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct node{
    double s, e;
}t[MAXN];

int n;
double l, w;

int cmp(node a, node b) {
    if (a.s != b.s)
        return a.s < b.s;
    else
        return a.e > b.e;
}

int main() {
    while (scanf("%d%lf%lf", &n, &l, &w) != EOF) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            double  p, r;
            scanf("%lf%lf", &p, &r); 
            if (r > w / 2) {
                double temp = sqrt(r * r - w * w / 4);
                t[cnt].s = p - temp;
                t[cnt].e = p + temp;
                cnt++;
            }
        }

        sort(t, t + cnt, cmp);
        int num = 0, flag = 0; 
        double start = 0, end = 0;
        if (t[0].s <= 0) {
            int left = 0; 
            while (left < cnt) {
                int right = left;
                while (right < cnt && t[right].s <= start) {
                    if (t[right].e >= end) 
                        end = t[right].e;
                    right++;
                }
                if (right == left) {
                    break; 
                }
                num++;
                left = right;
                start = end;
                if (start >= l) {
                    flag = 1;
                    break; 
                } 
            }  
        }

        if (flag) 
            printf("%d\n", num);
        else
            printf("-1\n");
    }    
    return 0;
}
