
#include "game.h"
#include "string.h"

void startGame();

void menu();

void gameStart();

void pointer();

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


int main() {

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


    printf("�������������:");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");


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

    return 0;


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



