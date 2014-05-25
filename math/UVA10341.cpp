#include <iostream>  
#include <cstdio>  
#include <cmath>  

using namespace std;  

int p, q, r, s, t, u;  
const double e = exp(1);  

double deal(double x) {  
    return p * pow(e, -x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;  
}  

int main() {  
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {  
        if (deal(0) < 0 || deal(1) > 0) {  
            cout << "No solution" << endl;  
        }  
        else {  
            double mid, z = 1e-8, x = 0, y = 1;  
            while (fabs(z) > 1e-9) {
                mid = (x + y) / 2;  
                z = deal(mid);  
                if (z > 0) {  
                    x = mid;  
                }  
                else {  
                    y = mid;  
                }   
            }
            printf("%.4lf\n", mid);  
        }  
    }  
    return 0;  
}  
