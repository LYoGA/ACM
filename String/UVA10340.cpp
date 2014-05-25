#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010

using namespace std;

char str1[N], str2[N];
int s[N];

int main() {
    while (scanf("%s", str1) != EOF) {
        scanf("%s", str2); 
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        memset(s, 0, sizeof(s));
        if (len1 > len2)
            printf("No\n");
        else {
            int k = 0;
            for (int i = 0; i < len1; i++) {
                for (int j = k; j < len2; j++) {
                    if (str1[i] == str2[j]) { 
                        s[i] = 1;   
                        k = j + 1;
                        break; 
                    }      
                }        
            }         
            int flag = 0;
            for (int i = 0; i < len1; i++)
                if (!s[i]) {
                    flag = 1;
                    break; 
                }
            if (flag) 
                printf("No\n");
            else
                printf("Yes\n"); 
        } 
    }
    return 0;
}
