#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct job{
    int num;
    double day, money, fine;
}j[1005];

int cmp(job a, job b) {
    if (fabs(a.fine - b.fine) > 0.000001)
        return a.fine > b.fine;
    return a.num < b.num;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n; 
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &j[i].day, &j[i].money);       
            j[i].fine = j[i].money / j[i].day;
            j[i].num = i + 1;
        } 
        sort(j, j + n, cmp);
        for (int i = 0; i < n - 1; i++)
            printf("%d ", j[i].num);
        printf("%d", j[n - 1].num);
        if (cas)
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}
