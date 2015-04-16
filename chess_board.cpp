#include <iostream>
#include <vector>
#include "chess_board.h"
#include "chess_pieces.h"


Board::Board(int boardNum, Piece* pieces[6][2]) {
    this->boardNum = boardNum;
    setup(board, pieces);
}
void Board::deleteBoard() {
        for (int i=7; i>=0; i--) {
            delete[] board[i];
        }
        delete[] board;
        //delete this;
    }
void Board::setup(Piece*** &board, Piece* pieces[6][2]) {
    
    board = new Piece**[8];
    
    for (int i = 0; i < 8; i++) {
        board[i] = new Piece*[8];
    }
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            //5=rook,4=knight,3=bishop,2=queen,1=king,0=pawn
            if (i == 0){
                if (j == 0 || j == 7)
                    board[i][j] = pieces[5][0];
                else if (j == 1 || j == 6)
                    board[i][j] = pieces[4][0];
                else if (j == 2 || j == 5)
                    board[i][j] = pieces[3][0];
                else if (j == 3)
                    board[i][j] = pieces[2][0];
                else if (j == 4)
                    board[i][j] = pieces[1][0];
            }
            else if (i == 1)
                board[i][j] = pieces[0][0];
            
            else if (i == 7){
                if (j == 0 || j == 7)
                    board[i][j] = pieces[5][1];
                else if (j == 1 || j == 6)
                    board[i][j] = pieces[4][1];
                else if (j == 2 || j == 5)
                    board[i][j] = pieces[3][1];
                else if (j == 3)
                    board[i][j] = pieces[2][1];
                else if (j == 4)
                    board[i][j] = pieces[1][1];
            }
            else if (i == 6)
                board[i][j] = pieces[0][1];
            else
                board[i][j] = 0;
        }
    }
    board[2][6] = pieces[0][1];
}

void Board::printBoard() {
    cout<< "\t\t";
    for(int i = 0; i < 8; i++){
        cout << " "<< i+1 << "\t\t\t";
    }
    for(int i = 0; i < 8; i++){
        cout<< "\n\t_________________________________________________________________________________________________\n";
        for(int i = 0; i <= 8; i++){
            cout << "\t|    \t";
        }
        cout << "\n" << 8-i << "\t|\t";
        for(int j = 0; j < 8; j++){
            if (board[i][j]!=0) {
                if (board[i][j]->isBlack) {
                    cout<< board[i][j]->type<<"B\t|\t";
                }
                else {
                    cout<< board[i][j]->type<<"W\t|\t";
                }
            }
            else {
                cout<< "\t   \t|\t";
            }
        }
        cout<< "\n";
        for(int i = 0; i <= 8; i++){
           cout << "\t|    \t";
        }
    }
    cout<< "\n\t__________________________________________________________________________________________________\n\n";
}
