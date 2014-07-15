#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 100005

using namespace std;

struct  node {
    int x, y;
}a[N], b[N];


int cmp(node a, node b){ 
    return a.y > b.y;
}

int main() {
    int n;
    scanf("%d", &n);  
    while (n--) {
        int out = 0, in = 0, start = 0, end;  
        scanf("%d", &end); 
        while (scanf("%d %d", &a[in].x, &a[in].y)) { 
            if (!a[in].x && !a[in].y)
                break;
            in++; 
        }
        sort(a, a + in, cmp); 
        while (start < end) {
            int i;
            for (i = 0; i < in; i++) {
                if (a[i].x <= start && a[i].y > start) {
                    start = a[i].y; 
                    b[out++] = a[i]; 
                    break; 
                }
            }
            if (i == in) break;
        }
        if (start < end) printf("0\n");
        else {
            printf("%d\n", out);
            for (int i = 0; i < out; i++)
                printf("%d %d\n", b[i].x, b[i].y);
        }
        if (n)
            printf("\n");  
    }
    return 0;
}
