//
// Created by lx011 on 2023/11/9.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum day {
    MON, TUE, WED, THU, FRI, SAT, SUN
};


void foozz();

void foo1111() {
    enum day d = MON;
    enum day t = TUE;

    printf("%d\n", d);
    printf("%d\n", t);

    printf("Hello, World!\n");
}

int compare_int(const void *e1, const void *e2) {
    int *p1 = (int *) e1;
    int *p2 = (int *) e2;

    return *p1 - *p2;

}

void GetMemory(char **p) {
    *p = (char *) malloc(100);

}

void Test(void) {
    char *str = NULL;
    GetMemory(&str);


    if (str != NULL) {
        strcpy(str, "hello world");
        printf("%s\n", str);
    }
    free(str);  // 不要忘记释放分配的内存
}

int main() {
    Test();
    return 0;
}


int main1(int argc, char *argv[]) {

    //写一个 realloc的示例
    /*   int *p = (int *) malloc(5 * sizeof(int));

       int * ptr = realloc(p, 10 * sizeof(int));

       if (ptr) {
           p = ptr;
       } else {
           free(p);
           p = NULL;
       }

       if (p == NULL) {
           printf("%s", strerror(errno));
           return 1;
       }
       for (int i = 0; i < 10; ++i) {
           p[i] = i;
       }
       for (int i = 0; i < 10; ++i) {
           printf("%d\n", p[i]);
       }
   */



/*
    //动态内存开辟
    //    int *p = (int *) malloc(INT_MAX*sizeof(int));

    // 开辟10个整形空间
    int *  const p = (int *) calloc(10, 4);

    const int * p1 = (int *) calloc(10, 4);

    if (p == NULL) {
        printf("%s", strerror(errno));
        return 1;
    }
    //    使用
    for (int i = 0; i < 10; ++i) {
        //       * (p+i) = i;
        p[i] = i;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d\n", p[i]); // 或者 printf("%d\n", *(p + i));
    }
*/




    return 0;
}

void foozz() {//    定义一个没有顺序的数组，然后使用qsort函数排序
    int a[] = {1, 3, 2, 5, 4};
    int len = sizeof(a) / sizeof(a[0]);

    qsort(a, len, sizeof(int), compare_int);

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        printf("%d\n", a[i]);
    }


    int arr[10] = {0};


}


