#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    long long a;
    double mid;
    for (int i = 2; i < 100000000; i++) {
        a = (double)i * (i + 1); 
        a /= 2; 
        mid = sqrt(a);
        a = mid;
        if (fabs(mid - (double)a) < 1e-10)
            printf("%10d%10d\n", a, i);
    }
    return 0;
}


/*#include <iosteam>
#include <cstdio>

int main() {
    printf("%10d%10d\n", 6, 8);
    printf("%10d%10d\n", 35, 49);
    printf("%10d%10d\n", 204, 288);
    printf("%10d%10d\n", 1189, 1681);
    printf("%10d%10d\n", 6930, 9800);
    printf("%10d%10d\n", 40391, 57121);
    printf("%10d%10d\n", 235416, 332928);
    printf("%10d%10d\n", 1372105, 1940449);
    printf("%10d%10d\n", 7997214, 11309768);
    printf("%10d%10d\n", 46611179, 65918161);
    return 0;
}*/
