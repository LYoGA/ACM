#include <stdio.h>
#include <string.h>
#define MAXN 1000100

typedef struct {
    int value;
    int num;
}QUEUE;

QUEUE queue[MAXN];

int main() {
    int T;
    char name[10];
    char s[20];
    scanf("%d",&T);
    while (T--) {
        scanf("%s", s);
        int front = 1;  //当前离开人的编号
        int cnt = 0;    //面试人数
        int head = 1;   //表示队列第一个
        int rear = 0;   //队列的长度
        int rp;
        while (scanf("%s",s) != EOF) {
            if (!strcmp(s,"END"))
                break;
            if (strcmp(s, "C") == 0) {
                scanf("%s%d", name, &rp);
                while (head <= rear && rp > queue[rear].value)
                    rear--;
                queue[++rear].value = rp;
                queue[rear].num = ++cnt;
            }
            else if (strcmp(s, "G") == 0) {
                while (head <= rear && queue[head].num <= front)  //单调队列元素下标单调递增
                    head++;
                front++;
            }
            else if (strcmp(s, "Q") == 0)
                printf("%d\n",head > rear ? -1 : queue[head].value);
        }
    }
    return 0;
}

