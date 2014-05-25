#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int ca, cb, na, nb, n; 
    while (scanf("%d %d %d", &ca, &cb, &n) != EOF) {
       if (cb == n) {
            printf("fill B\n"); 
            printf("success\n"); 
            continue;
       } 
       na = nb = 0;
       while (nb != n) {
            if (na == 0) {
                printf("fill A\n"); 
                na += ca;
            } 
            if (nb == cb) {
                printf("empty B\n");   
                nb = 0;
            } 
            nb += na;
            na = 0;
            if (cb < nb) {
                na = nb - cb; 
                nb = cb;
            }  
            printf("pour A B\n");
       }
       printf("success\n");
    }    
    return 0;
}
