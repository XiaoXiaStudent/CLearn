
#include "game.h"

void startGame();

void menu();

int my_strlen(char* str) {
    // �����ǰ�ַ��ǽ����� '\0'���򷵻�0
    if (*str == '\0') {
        return 0;
    }
    // ���򣬷���1���϶�ʣ�ಿ�ֵĵݹ���õĽ��
    return 1 + my_strlen(str + 1);
}


int main() {


    int len = my_strlen("abcdef");
    printf("%d\n", len);
    return 0;


    /**
     * ����δ����У�int* pa �� pa �в�ͬ�ĺ��壺

    pa ��һ��ָ����������ڴ洢һ�������ĵ�ַ������ִ�� int* pa = &a;����ʵ�����ǽ����� a ���ڴ��ַ��ֵ�� pa��

    *pa �ǽ����ò���������ʹ�� *pa����ʵ�����Ƿ��� pa ��ָ����ڴ��ַ�е����ݡ�����������У�*pa ��ֵ���Ǳ��� a ��ֵ��Ҳ���� 10��

    ���ԣ�

    pa �Ǳ��� a �ĵ�ַ��
    *pa �Ǵ洢�ڸõ�ַ��ֵ���� 10��
    ���⣬���� pa + 1;��������������� pa ָ���ֵ�������ӵ���ȡ��������ָ����������͵Ĵ�С����Ϊ pa ��һ�� int ָ�룬����ͨ������� int �� 4 �ֽڣ����� pa + 1 ��ʹָ������ƶ� 4 ���ֽڡ���������δ����У���û�н������ֵ�� pa������ pa ��ֵ����ı䡣
         */
    int a = 10;

    int* pa = &a;

    pa + 1;

    printf("%p\n", pa);


    printf("%p\n", (void*)pa);
    return 0;
    /*do {

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



