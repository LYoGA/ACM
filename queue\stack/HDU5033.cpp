#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const double pi = acos(-1.0);

struct Build{
    Build() {
        memset(ang, 0, sizeof(ang)); 
    }
    double x, h;    
    double ang[2];
    bool pos;
    int id; 
}b[MAXN], q[MAXN];

int t, n, m;

bool cmp1(Build a, Build b) {
    return a.x < b.x;
}

bool cmp2(Build a, Build b) {
    return a.id < b.id;
}

double deal(Build a, Build b) {
    double dx = fabs(b.x - a.x);
    double dy = b.h - a.h; 
    return dy / dx;
}

int main() {
    int cas, t = 1;
    scanf("%d", &cas); 
    while (cas--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &b[i].x, &b[i].h); 
            b[i].pos = false;
            b[i].id = i;
        } 
        scanf("%d", &m); 
        for (int i = n; i < n + m; i++) {
            scanf("%lf", &b[i].x);  
            b[i].h = 0; 
            b[i].pos = true;
            b[i].id = i;
        }
   
        n += m;
        sort(b, b + n, cmp1);
        q[0] = b[0];        
        int top = 0;
        for (int i = 1; i < n; i++) {
            if (b[i].pos == false) {
                while (top && deal(b[i], q[top]) < deal(q[top], q[top - 1]))  
                    top--;
                q[++top] = b[i];
            }
            else {
                int tmp = top; 
                while (tmp && deal(b[i], q[tmp]) < deal(b[i], q[tmp - 1]))  
                    tmp--;
                b[i].ang[0] = deal(b[i], q[tmp]);
            } 
        }

        q[0] = b[n - 1];
        top = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (b[i].pos == false) {
                while (top && deal(b[i], q[top]) < deal(q[top], q[top - 1]))  
                    top--;
                q[++top] = b[i];
            }
            else {
                int tmp = top; 
                while (tmp && deal(b[i], q[tmp]) < deal(b[i], q[tmp - 1]))  
                    tmp--;
                b[i].ang[1] = deal(b[i], q[tmp]);
            }  
        }
        
        printf("Case #%d:\n", t++);
        sort(b, b + n, cmp2);        
        for (int i = 0; i < n; i++) {
            if (b[i].pos == true) {
                double ans = pi - atan(b[i].ang[0]) - atan(b[i].ang[1]); 
                ans = ans / pi * 180;
                printf("%.4lf\n", ans); 
            }  
        }
    }
    return 0;
}
