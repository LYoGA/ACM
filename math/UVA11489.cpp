#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

char s[MAXN];
int arr[MAXN];
int n, sum, used, l;

bool judge() {
     for (int i = 0; i < l; i++) {
        if ((sum - arr[i]) % 3 == 0) {
            used = i;
            return true; 
        }  
     }
     return false;
}

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", s);        
        l = strlen(s);
        sum = 0;
        for (int i = 0; i < l; i++) {
            arr[i] = s[i] - '0';
            sum += arr[i];
        }

        printf("Case %d: ", t++);
        if (n == 1)
            printf("S\n");
        else { 
            if (!judge())              
                printf("T\n"); 
            else {
                int cnt = 0;
                for (int i = 0; i < l; i++) {
                    if (i == used) 
                        continue;
                    if (arr[i] % 3 == 0) 
                        cnt++;
                } 
                if (cnt % 2 == 0)
                    printf("S\n");
                else
                    printf("T\n");  
            } 
        }
    }
    return 0;
}
