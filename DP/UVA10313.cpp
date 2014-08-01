#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 305;
const int N = 300;

char s[MAXN];
int n, l1, l2;
long long sum, d[MAXN][MAXN]; 

void dp() {
    memset(d, 0, sizeof(d)); 
    d[0][0] = 1;
    for (int i = 0; i <= N; i++) 
        for (int j = 1; j <= N; j++) {
            if (i >= j)   
                d[i][j] = d[i - j][j] + d[i][j - 1];
            else
                d[i][j] = d[i][j - 1];     
        }
}

int main() {
    dp();
    while (gets(s) != NULL) {
        int num = sscanf(s, "%d %d %d", &n, &l1, &l2); 
        l1 = l1 > N ? N : l1;
        l2 = l2 > N ? N : l2;
        sum = 0;
        if (num == 1) 
            sum = d[n][n];  
        else if (num == 2) 
            sum = d[n][l1];  
        else
            sum = d[n][l2] - d[n][l1 - 1]; 

        printf("%lld\n", sum);
    }
    return 0;
}
