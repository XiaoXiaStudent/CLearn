
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

struct Test {
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
};

struct Test *p = (struct Test *) 0x100000;

// ��������
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

    // ���Ŀ���ڴ����Դ�ڴ��֮����Ҫ�Ӻ���ǰ����
    if (dest_char > src_char && dest_char < src_char + count) {
        for (size_t i = count; i != 0; i--) {
            dest_char[i-1] = src_char[i-1];
        }
    } else {
        // ���û���ص�������Ŀ���ڴ����Դ�ڴ��֮ǰ����ǰ����Ƽ���
        for (size_t i = 0; i < count; i++) {
            dest_char[i] = src_char[i];
        }
    }

    return dest;
}


void foo14() {
    char data[] = "Hello, World!";
    // ���������ص�������ʾ memmove �ı�Ҫ��
    my_memmove(data + 7, data, 6);

    printf("%s\n", data); // ��� "Hello, Hello!"

}

void foo13() {
    int source[] = {1, 2, 3, 4, 5};       // Դ����
    int destination[5];                   // Ŀ�����飬���ڴ�ſ���������

    // ʹ�� memcpy �����ڴ濽��
// ������Ŀ���ڴ��ַ��Դ�ڴ��ַ��Ҫ���Ƶ��ֽ���
    memcpy(destination, source, sizeof(source));

    // ��ӡ���ƺ��Ŀ������
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
        printf("�Ӵ�������\n");
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
                // �ҵ��Ӵ��󣬸����Ӵ����µ��ڴ�λ��
                size_t length = q - substr;
                char *match = (char *)malloc(length + 1);
                if (match) {
                    for (size_t i = 0; i < length; i++) {
                        match[i] = substr[i];
                    }
                    match[length] = '\0';
                }
                return match; // �����µ��ַ���
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

// ��������
int strLength(const char *str) {
    const char *strEnd = str; // ����һ��ָ���ַ�����ʼ��ָ��

    // �ƶ�ָ��ֱ���ַ�����ĩβ
    while (*strEnd) {
        strEnd++;
    }

    // ����ĩβָ��Ϳ�ʼָ��Ĳ���ַ����ĳ���
    return strEnd - str;
}

void foo8() {//    дһ���žų˷���
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

void foo6() {// ������ע�Ͳ��֣�
// ��ַΪ0x100000�����±��ʽ��ֵ�ֱ�Ϊ���٣�
// ���ǣ��ṹ��Testʵ�ʵĴ�С��С��20���ֽ�
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



