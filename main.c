
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
                printf("%s\n", "退出游戏!");
                break;
            default:
                printf("%s\n", "输入错误");
                break;
        }

    } while (input);*/

    startGame();
    return 0;
}

void menu() {

    printf("%s\n", "****游戏菜单******");

    printf("%s\n", "1. 开始游戏 0.退出");
}

void startGame() {
    char board[Row][Col] = {0};

//    初始化棋盘
    initBoard(board, Row, Col);
    displayBoard(board, Row, Col);

}



