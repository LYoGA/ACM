#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1005;

char str[MAXN], ans[MAXN];

void init(int i) {
    ans[0] = str[i];
    ans[1] = str[i + 1];
    ans[2] = str[i + 2];
    ans[3] = str[i + 3];    
}

int main() {
    int num = 0;
    while (scanf("%s", str) != EOF) {
        int len = strlen(str); 
        for (int i = 0; i < len; i++) {
            if (isupper(str[i])) 
                str[i] = str[i] + 32;
        }
        for (int i = 0; i < len; i++) {
            init(i); 
            if (strcmp(ans, "doge") == 0)
                num++;
        }
    }        
    printf("%d\n", num);
    return 0;
}
