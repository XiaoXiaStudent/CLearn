
#include "game.h"
#include "string.h"

void startGame();

void menu();

void gameStart();

void pointer();

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


int main() {

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

        while ((start < end) && ( *start % 2 == 0)) {
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


    }


    printf("你输入的数字是:");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");


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

    return 0;


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



