#ifndef COP3503_Project_chess_board_h
#define COP3503_Project_chess_board_h

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "chess_pieces.h"
#include "chess_board.h"

using namespace std;

class Board{
public:
    int boardNum;
    Piece*** board;
    Board(int boardNum, Piece pieces[6][2]) {
        this->boardNum = boardNum;
        setup(board, pieces);
    }
    void deleteBoard() {
        for (int i=7; i>=0; i--) {
            delete[] board[i];
        }
        delete[] board;
        //delete this;
    }
private:
    void setup(Piece*** &board, Piece pieces[6][2]) {
        
        board = new Piece**[8];
        
        for (int i = 0; i < 8; i++) {
            board[i] = new Piece*[8];
        }
        for (int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                //5=rook,4=knight,3=bishop,2=queen,1=king,0=pawn
                if (i == 0){
                    if (j == 0 || j == 7)
                        board[i][j] = &pieces[5][0];
                    else if (j == 1 || j == 6)
                        board[i][j] = &pieces[4][0];
                    else if (j == 2 || j == 5)
                        board[i][j] = &pieces[3][0];
                    else if (j == 3)
                        board[i][j] = &pieces[2][0];
                    else if (j == 4)
                        board[i][j] = &pieces[1][0];
                }
                else if (i == 1)
                    board[i][j] = &pieces[0][0];
                
                else if (i == 7){
                    if (j == 0 || j == 7)
                        board[i][j] = &pieces[5][1];
                    else if (j == 1 || j == 6)
                        board[i][j] = &pieces[4][1];
                    else if (j == 2 || j == 5)
                        board[i][j] = &pieces[3][1];
                    else if (j == 3)
                        board[i][j] = &pieces[2][1];
                    else if (j == 4)
                        board[i][j] = &pieces[1][1];
                }
                else if (i == 6)
                    board[i][j] = &pieces[0][1];
                else
                    board[i][j] = new Piece();
            }
        }
    }
};

#endif
