#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 1025;
const int g = 34943;

char s[N];
int b[4];

int main () {
    while (gets(s)) {
        if (strcmp(s, "#") == 0) 
            break; 
        long long num = 0, ans;
        int l = strlen(s);
        for (int i = 0; i < l; i++)
            num = (num * 256 + s[i]) % g;
        num = (num * 65536) % g;
        ans = (g - num % g) % g;
        for (int i = 0; i < 4; i++) {
            b[i] = ans % 16; 
            ans /= 16; 
        }
        printf("%X%X %X%X\n", b[3], b[2], b[1], b[0]);
    }
    return 0;
}
