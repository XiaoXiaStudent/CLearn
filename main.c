
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
    // �����ǰ�ַ��ǽ����� '\0'���򷵻�0
    if (*str == '\0') {
        return 0;
    }
    // ���򣬷���1���϶�ʣ�ಿ�ֵĵݹ���õĽ��
    return 1 + my_strlen(str + 1);
}

// ������Ľṹ��
struct Book {
    char title[50];   // ����
    char author[50];  // ������
    float price;      // �۸�
};


void changeOrder() {

    int numbers[10] = {0};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("��һ��������%d�����֣��Կո�ָ���: ", size);

    for (int i = 0; i < size; ++i) {
        scanf("%d", &numbers[i]);
    }


//    ��������˳��
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

void foo6() {// ������ע�Ͳ��֣�
// ��ַΪ0x100000�����±��ʽ��ֵ�ֱ�Ϊ���٣�
// ���ǣ��ṹ��Testʵ�ʵĴ�С��С��20���ֽ�
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

void foo4() {//    ð������
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

// ��ʼ��һ��Book�ṹ�����
/*    struct Book myBook;

    strcpy(myBook.title, "C Programming for Experts");
    strcpy(myBook.author, "John Doe");
    myBook.price = 29.99;

    // ��������Ϣ
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
        printf("%d ", *(*p + i)); // P��ָ�������ָ�룬*pָ�ľ���������飬����(*p+i)������ĵ�ַ+ƫ�Ƶ�ַ
        // ���*(*p+i)�ǻ�ȡ����Ԫ�ص�ʵ��ֵ
    }
}

void foo() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 5, 6};
    int arr3[] = {3, 4, 5, 6, 7};

    int *parr[3] = {arr1, arr2, arr3};


    int size = sizeof(arr1) / sizeof(arr1[0]); // �����������鶼����ͬ�Ĵ�С

    for (int i = 0; i < 3; i++) { // ����parr����
        for (int j = 0; j < size; j++) { // ����ÿ�������е�Ԫ��
//            printf("%d ", parr[i][j]);
            printf("%d ", *(parr[i] + j));
        }
        printf("\n"); // ��ӡ���У�ʹÿ�����������ڲ�ͬ����
    }
}

void pointer() {/**
 * ����δ����У�int* pa �� pa �в�ͬ�ĺ��壺

pa ��һ��ָ����������ڴ洢һ�������ĵ�ַ������ִ�� int* pa = &a;����ʵ�����ǽ����� a ���ڴ��ַ��ֵ�� pa��

*pa �ǽ����ò���������ʹ�� *pa����ʵ�����Ƿ��� pa ��ָ����ڴ��ַ�е����ݡ�����������У�*pa ��ֵ���Ǳ��� a ��ֵ��Ҳ���� 10��

���ԣ�

pa �Ǳ��� a �ĵ�ַ��
*pa �Ǵ洢�ڸõ�ַ��ֵ���� 10��
���⣬���� pa + 1;��������������� pa ָ���ֵ�������ӵ���ȡ��������ָ����������͵Ĵ�С����Ϊ pa ��һ�� int ָ�룬����ͨ������� int �� 4 �ֽڣ����� pa + 1 ��ʹָ������ƶ� 4 ���ֽڡ���������δ����У���û�н������ֵ�� pa������ pa ��ֵ����ı䡣
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
            printf("%s\n", "�˳�")��;
            break;
        default:
            printf("%s\n", "�����������������");
            break;
    }

} while (input);*/

//    startGame();

}

void menu() {

    printf("%s\n", "****������******");

    printf("%s\n", "1.��ʼ��Ϸ 0.�˳���Ϸ");
}

void startGame() {
    char board[Row][Col] = {0};


    initBoard(board, Row, Col);
    displayBoard(board, Row, Col);


}



