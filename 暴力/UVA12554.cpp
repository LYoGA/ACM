#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110
using namespace std;

char name[N][N];
char s1[16][20] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", 
                    "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", name[i]);
    int m = (n / 16 + 1) * 16;
    for (int i = 0; i < m; i++) {
            printf("%s: %s\n", name[i % n], s1[i % 16]);   
    }     
    return 0;
}
