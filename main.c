
#include "game.h"

void startGame();

void menu();




int main() {
    int input = 0;
    /*do {

        menu();
        scanf("%d", &input);

        switch (input) {
            case 1:
                startGame();
                break;

            case 0:
                printf("%s\n", "�˳���Ϸ!");
                break;
            default:
                printf("%s\n", "�������");
                break;
        }

    } while (input);*/

    startGame();
    return 0;
}

void menu() {

    printf("%s\n", "****��Ϸ�˵�******");

    printf("%s\n", "1. ��ʼ��Ϸ 0.�˳�");
}

void startGame() {
    char board[Row][Col] = {0};

//    ��ʼ������
    initBoard(board, Row, Col);
    displayBoard(board, Row, Col);

}



