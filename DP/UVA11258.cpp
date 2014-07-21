#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INT_Max = 2147483647;
const int MAXN = 205;

char str[MAXN];
long long d[MAXN];

void dp(int len) {
    for (int i = 1; i <= len; i++) {	//枚举前i个的最大值
        for (int j = 1; j <= 10 && j <= i; j++) {	//枚举几个为一个整数
            long long sum = 0; 
            for (int k = 0; k < j; k++) {
                sum = sum * 10 + str[i - j + k] - '0'; 
                if (sum >= 0 && sum <= INT_Max) {
                    d[i] = max(d[i], d[i - j] + sum);	//求d[i]最大值	
                }
                else
                    break;
            } 
        }
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", str); 
        int len = strlen(str);
        memset(d, 0, sizeof(d));
        dp(len);
        printf("%lld\n", d[len]);
    }
    return 0;
}
