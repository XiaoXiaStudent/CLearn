//
// Created by youzi on 2023/7/12.
//

#include "game.h"


void initBoard(char board[Row][Col], int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int i1 = 0; i1 < col; i1++) {
            board[i][i1] = ' ';
        }
    }
}



void displayBoard(char pString[Row][Col], int row, int col) {
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++){

            printf(" %c ", pString[i][j]);
            if (j < col - 1) {
                printf("|");
            }
        }
        printf("\n");

        if (i < row - 1) {
            for (int z = 0; z < col; z++){

                printf("---");
                if (z < row - 1) {

                    printf("|");
                }
            }
            printf("\n");
        }
    }

}
//
//void displayBoard(char pString[Row][Col], int row, int col) {
//    for (int i = 0; i < row; i++) {
//
//        printf(" %c | %c | %c \n", pString[i][0], pString[i][1], pString[i][2]);
//        if (i < row - 1) {
//
//            printf("---|---|--- \n");
//        }
//    }
//
//}
