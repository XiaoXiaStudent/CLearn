
#include <stdlib.h>
#include "game.h"
#include "string.h"

void startGame();

void menu();

void gameStart();

void pointer();

void foo();

void foo1();

void foo2();

void foo3();

void foo4();

void foo5();

void foo6();

int getInt();

int my_strlen(char *str) {
    // 如果当前字符是结束符 '\0'，则返回0
    if (*str == '\0') {
        return 0;
    }
    // 否则，返回1加上对剩余部分的递归调用的结果
    return 1 + my_strlen(str + 1);
}

// 定义书的结构体
struct Book {
    char title[50];   // 书名
    char author[50];  // 作者名
    float price;      // 价格
};


void changeOrder() {

    int numbers[10] = {0};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("请一次性输入%d个数字（以空格分隔）: ", size);

    for (int i = 0; i < size; ++i) {
        scanf("%d", &numbers[i]);
    }


//    调整数组顺序
    int *start = numbers;

    int *end = &numbers[size - 1];

    while (start < end) {

        while ((start < end) && (*start % 2 == 0)) {
            start++;
        }

        while ((start < end) && (*end % 2 == 1)) {
            end--;
        }

        if (start < end) {
            int temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
        for (int i = 0; i < size; ++i) {
            printf("%d ", numbers[i]);
        }
        printf("\n");

    }
}

void print2(int (*p)[3], int r, int c) {
    int i = 0;
    for (i = 0; i < r; i++) {
        int j = 0;
        for (j = 0; j < c; j++) {
            printf("%d ", *((*p + i) + j));
        }
        printf("\n");
    }
}

int compare(const void *e1, const void *e2) {
    return *((int *) e1) - *((int *) e2);
}


void swap(char *a, char *b, size_t size) {

    for (int i = 0; i < size; ++i) {

        char temp = *b;
        *b = *a;
        *a = temp;

        a++;
        b++;

    }

}

void my_qsort(void *base, int size, int width, int (*compare)(const void *, const void *)) {
    for (int i = 0; i < size - 1; i++) {

        int j = 0;

        for (j = 0; j < size - 1 - i; j++) {

            if (compare((char *) base + j * width, (char *) base + (j + 1) * width) > 0) {

                swap((char *) base + j * width, (char *) base + (j + 1) * width, width);
            }

        }


    }
}

struct Test
{
    int Num;
    char* pcName;
    short sDate;
    char cha[2];
    short sBa[4];
};

struct Test* p = (struct Test*)0x100000;

int main() {

    char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };
    char** cp[] = { c + 3, c + 2, c + 1, c };
    char*** cpp = cp;


    *cpp[-1];
    cpp[-1][-1]  ;

}

int getInt() {
    int a[4] = {1, 2, 3, 4 };
    int* ptr1 = (int*)(&a + 1);
    int* ptr2 = (int*)((int)a + 1);


    printf("%X,%X", ptr1[-1], *ptr2);


    return 0;
}

void foo6() {// 以下是注释部分：
// 地址为0x100000。如下表达式的值分别为多少？
// 但是，结构体Test实际的大小并小于20个字节
// x86

    printf("%p\n", p + 0x1);
    printf("%p\n", (unsigned long)p + 0x1);
    printf("%p\n", (unsigned int*)p + 0x1);
}

void foo5() {//        for (int i = 0; i < size - 1; i++) {
//
//        int j = 0;
//
//        for (j = 0; j < size - 1 - i; j++) {
//
//            if (arr[j] > arr[j+1]) {
//                int temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//            }
//
//        }
//    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
//        printf("%d", arr[i]);
//    }

}

void foo4() {//    冒泡排序
    int arr[] = {5, 1, 2, 3, 18, 3, 15, 7, 8, 9};


    int size = sizeof(arr) / sizeof(arr[0]);


//    qsort(arr, size, sizeof(arr[0]), compare);
    my_qsort(arr, size, sizeof(arr[0]), compare);
}

void foo3() {
    int a[3][4] = {0};

    printf("%d\n", sizeof(a));  //48
    printf("%d\n", sizeof(a[0][0])); //4
    printf("%d\n", sizeof(a[0])); //16


    printf("%d\n", sizeof(a[0] + 1));//4/8


    printf("%d\n", sizeof(*(a[0] + 1)));//4
    printf("%d\n", sizeof(a + 1));//4/8
    printf("%d\n", sizeof(*(a + 1)));//16
    printf("%d\n", sizeof(&a[0] + 1));//4/8
    printf("%d\n", sizeof(*(&a[0] + 1)));//4
    printf("%d\n", sizeof(*a));
    printf("%d\n", sizeof(a[3]));
}

void foo2() {
    char *p = "abcedf";


    printf("%d\n", strlen(&p));
    printf("%d\n", strlen(&p + 1));
}














//    int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7} };
//    print2(arr, 3, 5);




//    int len = my_strlen("ab11cdef");
//    printf("%d\n", len);

// 初始化一个Book结构体变量
/*    struct Book myBook;

    strcpy(myBook.title, "C Programming for Experts");
    strcpy(myBook.author, "John Doe");
    myBook.price = 29.99;

    // 输出书的信息
    printf("Book Information:\n");
    printf("Title: %s\n", myBook.title);
    printf("Author: %s\n", myBook.author);
    printf("Price: $%.2f\n", myBook.price);*/


void foo1() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int (*p)[10] = &arr;

    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < sz; i++) {
        printf("%d ", *(*p + i)); // P是指向数组的指针，*p指的就是这个数组，所以(*p+i)是数组的地址+偏移地址
        // 因此*(*p+i)是获取数组元素的实际值
    }
}

void foo() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 5, 6};
    int arr3[] = {3, 4, 5, 6, 7};

    int *parr[3] = {arr1, arr2, arr3};


    int size = sizeof(arr1) / sizeof(arr1[0]); // 假设所有数组都有相同的大小

    for (int i = 0; i < 3; i++) { // 遍历parr数组
        for (int j = 0; j < size; j++) { // 遍历每个数组中的元素
//            printf("%d ", parr[i][j]);
            printf("%d ", *(parr[i] + j));
        }
        printf("\n"); // 打印换行，使每个数组的输出在不同的行
    }
}

void pointer() {/**
 * 在这段代码中，int* pa 和 pa 有不同的含义：

pa 是一个指针变量，用于存储一个整数的地址。当你执行 int* pa = &a;，你实际上是将变量 a 的内存地址赋值给 pa。

*pa 是解引用操作。当你使用 *pa，你实际上是访问 pa 所指向的内存地址中的内容。在这个例子中，*pa 的值就是变量 a 的值，也就是 10。

所以：

pa 是变量 a 的地址。
*pa 是存储在该地址的值，即 10。
另外，关于 pa + 1;：这个操作增加了 pa 指针的值，但增加的量取决于它所指向的数据类型的大小。因为 pa 是一个 int 指针，并且通常情况下 int 是 4 字节，所以 pa + 1 会使指针向后移动 4 个字节。但是在这段代码中，您没有将结果赋值给 pa，所以 pa 的值不会改变。
     */
    int a = 10;

    int *pa = &a;

    pa + 1;

    printf("%p\n", pa);


    printf("%p\n", (void *) pa);
}

void gameStart() {/*do {

    menu();
    scanf("%d", &input);

    switch (input) {
        case 1:
            startGame();
            break;

        case 0:
            printf("%s\n", "退出")—;
            break;
        default:
            printf("%s\n", "输入错误请重新输入");
            break;
    }

} while (input);*/

//    startGame();

}

void menu() {

    printf("%s\n", "****五子棋******");

    printf("%s\n", "1.开始游戏 0.退出游戏");
}

void startGame() {
    char board[Row][Col] = {0};


    initBoard(board, Row, Col);
    displayBoard(board, Row, Col);


}



