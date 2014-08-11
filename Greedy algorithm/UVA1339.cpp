#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

char s1[MAXN], s2[MAXN];
int num1[MAXN], num2[MAXN], v1[MAXN], v2[MAXN];

int main() {
    while (gets(s1) != NULL) {
        gets(s2); 
        int len = strlen(s1), flag = 1;
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(v1, 0, sizeof(v1));
        memset(v2, 0, sizeof(v2));
        for (int i = 0; i < len; i++) {
            num1[s1[i] - 'A']++;
            num2[s2[i] - 'A']++; 
        }
        for (int i = 0; i < 26; i++) {
            v1[num1[i]]++; 
            v2[num2[i]]++; 
        }
        for (int i = 0; i < 26; i++) {
            if (v1[i] != v2[i]) {
                flag = 0; 
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
