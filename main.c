
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

void foo7();

void foo8();

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

struct Test {
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
};

struct Test *p = (struct Test *) 0x100000;

// 函数声明
int strLength(const char *str);

void foo9();

void foo10();


void foo11();


void mystrncat(char arr1[6], char arr2[5], int i);

int getInt1();

char *my_strstr(char email[21], char substr[12]);

void foo12();

void foo13();

void foo14();

void myStrcpy1(char *arr2, const char *arr1) {

    while (*arr1 != '\0') {
        *arr2 = *arr1;
        arr1++;
        arr2++;
    }
    *arr2 = '\0';


}

void mystrcat(char *target, const char *sources) {

    while (*target != '\0') {
        target++;
    }

    while (*sources != '\0') {
        *target = *sources;
        target++;
        sources++;
    }

    *target = '\0';

}

int my_strcmp(char *arr1, char *arr2) {

    while (*arr1 == *arr2) {
        if (*arr1 == '\0') {
            return 0;
        }
        arr1++;
        arr2++;
    }

    return *arr1 - *arr2;

}
void *my_memmove(void *dest, const void *src, size_t count) {
    char *dest_char = (char *)dest;
    const char *src_char = (const char *)src;

    // 如果目标内存块在源内存块之后，需要从后向前复制
    if (dest_char > src_char && dest_char < src_char + count) {
        for (size_t i = count; i != 0; i--) {
            dest_char[i-1] = src_char[i-1];
        }
    } else {
        // 如果没有重叠，或者目标内存块在源内存块之前，从前向后复制即可
        for (size_t i = 0; i < count; i++) {
            dest_char[i] = src_char[i];
        }
    }

    return dest;
}


void foo14() {
    char data[] = "Hello, World!";
    // 故意制造重叠，以演示 memmove 的必要性
    my_memmove(data + 7, data, 6);

    printf("%s\n", data); // 输出 "Hello, Hello!"

}

void foo13() {
    int source[] = {1, 2, 3, 4, 5};       // 源数组
    int destination[5];                   // 目标数组，用于存放拷贝的数据

    // 使用 memcpy 进行内存拷贝
// 参数：目标内存地址，源内存地址，要复制的字节数
    memcpy(destination, source, sizeof(source));

    // 打印复制后的目标数组
    for (int i = 0; i < 5; i++) {
        printf("%d ", destination[i]);
    }
    printf("\n");
}

void foo12() {
    char email[] = "zpwb@biteituyake.com";
    char substr[] = "biteituyake";
    char *ret = my_strstr(email, substr);
    if (ret == NULL) {
        printf("子串不存在\n");
    } else {
        printf("%s\n", ret);
    }
}

char *my_strstr(char email[21], char substr[12]) {

        char *p = email;
        char *q = substr;

        while (*p != '\0') {

            char *start = p;
            while (*p == *q && *q != '\0') {
                p++;
                q++;
            }

            if (*q == '\0') {
                // 找到子串后，复制子串到新的内存位置
                size_t length = q - substr;
                char *match = (char *)malloc(length + 1);
                if (match) {
                    for (size_t i = 0; i < length; i++) {
                        match[i] = substr[i];
                    }
                    match[length] = '\0';
                }
                return match; // 返回新的字符串
            }

            p = start + 1;
            q = substr;
        }

        return NULL;
}

int getInt1() {
    char arr1[] = "abcl2";
    char arr2[] = "abcl";

    mystrncat(arr1, arr2, 3);

    printf("%s\n", arr1);


    return 0;
}

void mystrncat(char arr1[6], char arr2[5], int i) {

    while (*arr1 != '\0') {
        arr1++;
    }

    while (i > 0) {
        *arr1 = *arr2;
        arr1++;
        arr2++;
        i--;
    }

    *arr1 = '\0';

}


void foo11() {
    char arr1[] = "abcdef";
    char arr2[20] = {"hello3333"};

    mystrcat(arr2, arr1); // helloabcdef

    printf("%s\n", arr2); // abcdef


}


void foo10() {
    char name[20] = {0};

    strcpy(name, "zhangsan");


    printf("%s\n", name);
}

void foo9() {
    const char *myString = "Hello, World!";
    const char arr[] = "Hello, World!";

    int length = strLength(arr);
    printf("The length of the string is: %d\n", length);
}

// 函数定义
int strLength(const char *str) {
    const char *strEnd = str; // 创建一个指向字符串开始的指针

    // 移动指针直到字符串的末尾
    while (*strEnd) {
        strEnd++;
    }

    // 返回末尾指针和开始指针的差，即字符串的长度
    return strEnd - str;
}

void foo8() {//    写一个九九乘法表
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d*%d=%d ", j, i, i * j);
        }
        printf("\n");
    }
}

void foo7() {
    char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char **cp[] = {c + 3, c + 2, c + 1, c};
    char ***cpp = cp;


    printf("%d", c);
    printf("%d", *c);
    printf("%d", **c);
}

int getInt() {
    int a[4] = {1, 2, 3, 4};
    int *ptr1 = (int *) (&a + 1);
    int *ptr2 = (int *) ((int) a + 1);


    printf("%X,%X", ptr1[-1], *ptr2);


    return 0;
}

void foo6() {// 以下是注释部分：
// 地址为0x100000。如下表达式的值分别为多少？
// 但是，结构体Test实际的大小并小于20个字节
// x86

    printf("%p\n", p + 0x1);
    printf("%p\n", (unsigned long) p + 0x1);
    printf("%p\n", (unsigned int *) p + 0x1);
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



