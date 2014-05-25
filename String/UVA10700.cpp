#include <stdio.h>
#include <string.h>
#define N 30

char str[N];
double s[N], max, min;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        gets(str);
        int i, top;
        char ch;

        i = top = 0;
        ch = '+';
        while (str[i] != '\0') {
            int num = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + str[i] - '0';
                i++; 
            }
            if (ch == '+')
                s[++top] = num;
            else
                s[top] *= num;
            if (str[i] != '\0')
                ch = str[i++];
        }
        min = 0;
        for (int i = 1; i <= top; i++)
            min += s[i];

        i = top = 0;
        ch = '*'; 
        while (str[i] != '\0') {
            int num = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + str[i] - '0';
                i++; 
            }
            if (ch == '*')
                s[++top] = num;
            else
                s[top] += num;
            if (str[i] != '\0')
                ch = str[i++]; 
        }
        max = 1;
        for (int i = 1; i <= top; i++)
            max *= s[i];
        printf("The maximum and minimum are %.0lf and %.0lf.\n", max, min);
    }
    return 0;
}
