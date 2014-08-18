#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 20;

char s1[MAXN], s2[MAXN];
int p1[MAXN], p2[MAXN], num1[MAXN], num2[MAXN];

void change(char ch, int *p) {
    if (ch == 'Y') p[17] = 1;
    else if (ch == 'X') p[16] = 1;
    else if (ch == '2') p[15]++;
    else if (ch == 'A') p[14]++;
    else if (ch == 'K') p[13]++;
    else if (ch == 'Q') p[12]++;
    else if (ch == 'J') p[11]++;
    else if (ch == 'T') p[10]++;
    else p[ch - '0']++;  
}

void count(int n, int *num) {
    if (n == 1) num[1]++;
    else if (n == 2) num[2]++;
    else if (n == 3) num[3]++;
    else if (n == 4) num[4]++;
}

int slove(int n) {
    if (n == 1) return 1;
    else if (n == 2 && num1[2]) return 1; 
    else if (n == 2 && p1[16] && p1[18]) return 1; 
    else if (n == 3 && num1[3]) return 1;
    else if (n == 4 && (num1[4] || (num1[3] && num1[1]))) return 1;
    else if (n == 5 && num1[3] && num1[2]) return 1; 
    else if (n == 6 && num1[4]) return 1;
    return 0;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s%s", s1, s2); 
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        for (int i = 0; i < l1; i++) 
            change(s1[i], p1);
        for (int i = 0; i < l2; i++)
            change(s2[i], p2);
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        for (int i = 0; i < 18; i++) 
            count(p1[i], num1); 
        for (int i = 0; i < 18; i++) 
            count(p2[i], num2); 

        int flag = 0;
        if (l1 <= 6) //判断是否能直接把牌走完的情况
            flag = slove(l1);  
        
        if (flag) {
            printf("Yes\n");
            continue;
        }

        if (p1[16] && p1[17]) { //判断双方是否存在一方有王炸的情况
            printf("Yes\n");
            continue; 
        }
        if (p2[16] && p2[17]) {
            printf("No\n");
            continue; 
        }

        if (num1[4]) {  //判断炸的存在的情况
            int a = 1, b = 1;
            for (int i = 18; i >= 3; i--) 
                if (p1[i] == 4) {
                    a = i;
                    break;
                }
            for (int i = 18; i >= 3; i--) 
                if (p2[i] == 4) {
                    b = i;
                    break;
                }
            if (a > b)
                flag = 1;
            if (b > a)  
                flag = -1;
        }
        if (flag == 1) {
            printf("Yes\n");
            continue;
        }
        if (flag == -1) {
            printf("No\n");
            continue;
        }

        int c = 0;  //判断之存在对手有炸的情况
        for (int i = 18; i >= 3; i--) 
            if (p2[i] == 4) {
                c = 1;
                break;
            }
        if (c) {
            printf("No\n");
            continue;
        }

        if (num1[3]) {  //判断有三带能否直接获胜的情况
            int a = 1, b = 1;
            for (int i = 18; i >= 3; i--) 
                if (p1[i] == 3) {
                    a = i;
                    break;
                }
            for (int i = 18; i >= 3; i--) 
                if (p2[i] == 3) {
                    b = i;
                    break;
                }
            if (num1[2] && !num2[2]) {
                flag = 1; 
            }
            if (a > b)
                flag = 1; 
        }
        if (num1[2]) {  //判断出对子能否直接获胜的情况
            int a = 1, b = 1;
            for (int i = 18; i >= 3; i--) 
                if (p1[i] == 2 || p1[i] == 3) {
                    a = i;
                    break;
                }
            for (int i = 18; i >= 3; i--) 
                if (p2[i] == 2 || p2[i] == 3) {
                    b = i;
                    break;
                }
            if (a >= b)
                flag = 1; 
        }
        if (num1[1]) {  //判断出单能否直接获胜的情况
            int a = 1, b = 1;
            for (int i = 18; i >= 3; i--) 
                if (p1[i]) {
                    a = i;
                    break;
                }
            for (int i = 18; i >= 3; i--) 
                if (p2[i]) {
                    b = i;
                    break;
                }
            if (a >= b)
                flag = 1; 
        }

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
