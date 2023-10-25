
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
                printf("%s\n", "退出")—;
                break;
            default:
                printf("%s\n", "输入错误请重新输入");
                break;
        }

    } while (input);*/

//    startGame();
    return 0;
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



