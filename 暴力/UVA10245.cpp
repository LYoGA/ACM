#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct node{
    double x, y;
}n[10005];

int cmp(node a, node b) {
    return a.x < b.x;
}

int main() {
    int t;
    while (scanf("%d", &t) && t) {
        for (int i = 0; i < t; i++) 
            scanf("%lf %lf", &n[i].x, &n[i].y);
        sort(n, n + t, cmp);
        double min = 10000;
        for (int i = 0; i < t; i++) 
            for (int j = i + 1; j < t; j++) {
                if (fabs(n[i].x - n[j].x) >= min) 
                    break; 
                double x = (n[i].x - n[j].x) * (n[i].x - n[j].x);
                double y = (n[i].y - n[j].y) * (n[i].y - n[j].y);
                double z = sqrt(x + y);
                if (min > z) 
                    min = z;
            }
        if (min >= 10000)
            printf("INFINITY\n");
        else 
            printf("%.4lf\n", min);
    }
    return 0;
}
