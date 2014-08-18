#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int a[8];

int main() {
    while (1) {
        for (int i = 0; i < 8; i++)
            scanf("%d", &a[i]);
        if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6] && !a[7]) 
            break;
        sort(a, a + 8);
        double Min = INF;
        do{
            double mv, mh, m; 
            double x1, x2, y1, y2;
            x1 = a[5] + a[6] + a[7];
            x2 = a[0] + a[1] + a[2];
            y1 = a[2] + a[4] + a[7];
            y2 = a[0] + a[3] + a[5];
            mv = pow((x1 - x2), 2);
            mh = pow((y1 - y2), 2);
            m = sqrt(mv + mh);
            if (Min > m)  
                Min = m;  
        } while(next_permutation(a, a + 8));
        printf("%.3lf\n", Min); 
    } 
    return 0;
}

