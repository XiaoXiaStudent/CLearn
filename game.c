//
// Created by youzi on 2023/7/12.
//

#include "game.h"


void initBoard(char board[Row][Col], int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int i1 = 0; i1 < col; i1++) {
            board[i][i1] =' ';
        }
    }
}

void displayBoard(char pString[Row][Col], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int i1 = 0; i1 < col; i1++) {
            printf("%c", pString[i][i1]);
        }
        printf("\n");
    }

}
