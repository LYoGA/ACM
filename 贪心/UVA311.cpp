#include <iostream>
#include <cstdio>

using namespace std;

int a[7];
int three[4][2] = {{0, 0}, {7, 5}, {6, 3}, {5, 1}};

int main() {
    while (scanf("%d %d %d %d %d %d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]) != EOF) {
        if (!a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6]) 
            break; 
        int num = (a[3] + 3) / 4 + a[4] + a[5] + a[6];
        a[1] -= a[5] * 11; 
        int left_2 = three[a[3] % 4][1] + a[4] * 5;

        if (left_2 >= a[2]) {
            a[1] -= three[a[3] % 4][0]; 
            a[2] -= left_2;
            a[1] += a[2] * 4; 
            if (a[1] > 0)
                num += (a[1] + 35) / 36; 
        }
        else {
            a[1] -= three[a[3] % 4][0];
            a[2] -= left_2; 
            num += (a[2] + 8) / 9; 
            a[1] -= (9 - a[2] % 9) * 4;
            if (a[1] > 0) 
                num += (a[1] + 35) / 36; 
        } 
        printf("%d\n", num);
    } 
    return 0;
}

