#include<stdio.h>
#include<string.h>

int chang(int n) {
    int m = 0;
    while (n != 0) {
        m += n % 10;
        n = n / 10;
    }
    return m;
}

int main() {
    char str[1000];                              
    while(scanf("%s", str) != EOF) {
        if (strcmp(str, "0") == 0)
            break;
        int len = strlen(str), sum = 0;
        for(int i = 0; i < len; i++)
            sum += str[i] - '0';       
        while(sum > 9)
            sum = chang(sum);
        printf("%d\n",sum);
    }
}
