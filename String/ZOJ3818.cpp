#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char str[55];

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", str); 
        string s;
        int len = strlen(str);
        for (int i = 0; i < len; i++)
            if (isupper(str[i]) || islower(str[i]))
                s += str[i];
        len = s.length();
        int flag = 0;
        for (int i = 1; i < len / 2 && !flag; i++) {
            for (int j = 1; j < len / 2 && !flag; j++) {
                string A = s.substr(0, i); 
                string B = s.substr(i, j); 
                if (A == B) 
                    continue;
                if (A + B + A + B + A == s) {
                    flag = 1;
                    break;
                }
                if (len - (i + j) * 3 > 0) {
                    string AB = A + B; 
                    string C = s.substr(2 * (i + j), len - (i + j) * 3); 
                    if (A == C || B == C)
                        continue;
                    if (AB + AB + C + AB == s) {
                        flag = 1; 
                        break; 
                    }
                } 
            } 
        } 
        if (flag)
            printf("Yes\n");
        else
            printf("No\n"); 
    }
    return 0;
}
