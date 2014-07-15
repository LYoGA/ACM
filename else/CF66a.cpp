#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;

char str[4][30] = {"127", "32767", "2147483647", "9223372036854775807"};
char s[N];

void solve(char *a, int b) {
    if (b > 19)
        printf("BigInteger\n");
    else if (b == 19) {
        if (strcmp(a, str[3]) > 0) 
            printf("BigInteger\n");
        else 
            printf("long\n");
    }
    else if (b < 19) {
        if (b > 10) 
            printf("long\n");
        else if (b == 10) {
            if (strcmp(a, str[2]) > 0) 
                printf("long\n");
            else 
                printf("int\n");
        }
        else if (b < 10) {
            if (b > 5) 
                printf("int\n");
            else if (b == 5){
                if (strcmp(a, str[1]) > 0)  
                    printf("int\n"); 
                else 
                    printf("short\n");
            }
            else if (b < 5) {
                if (b > 3)  
                    printf("short\n");
                else if (b == 3) {
                    if (strcmp(a, str[0]) > 0) 
                        printf("short\n"); 
                    else 
                        printf("byte\n");
                }  
                else if (b < 3)
                    printf("byte\n");
            } 
        } 
    }
}

int main() {
    while (scanf("%s", &s) != EOF) {
        int l = strlen(s);
        solve(s, l);
    } 
    return 0;
}
