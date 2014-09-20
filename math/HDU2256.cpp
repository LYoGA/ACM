#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;


const int MOD = 1024;

int n;

struct mat {
    int s[2][2];
    mat(int a = 0, int b = 0, int c = 0, int d = 0) {
        s[0][0] = a; 
        s[0][1] = b; 
        s[1][0] = c; 
        s[1][1] = d; 
    }
    mat operator * (const mat& c) {
        mat ans; 
        sizeof(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % MOD;
        return ans;
    }
}tmp(5, 12, 2, 5);

mat pow_mod(int k) {
    if (k == 1)
        return tmp;
    mat a = pow_mod(k / 2);
    mat ans = a * a;
    if (k % 2)
        ans = ans * tmp;
    return ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n); 
        mat ans = pow_mod(n); 
        printf("%d\n", (ans.s[0][0] * 2 - 1) % MOD); 
    }
    return 0;
}
