
#include "game.h"

void startGame();

void menu();


int main() {




 int a = 0;

    char ch[10] = {0};


    printf("%d\n", sizeof(ch));



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
    return 0;
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



