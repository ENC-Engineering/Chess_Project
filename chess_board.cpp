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
}

void Board::printBoard() {
    cout<< "\n\n\n\n\n\n\n\n\n\n\t\t ";
    for(int i = 0; i < 8; i++){
        cout << " "<< (char)(97+i) << "\t\t\t ";
    }
    for(int i = 0; i < 8; i++){
        cout<< "\n\t_________________________________________________________________________________________________\n\t";
        for(int k = 0; k <= 8; k++){
            if (k==8) {
                cout<< "|";
            }
            else if ((i+k)%2 ==0) {
                cout << "|   \t\t";
            }
            else {
                cout << "||||||||||||";
            }
        }
        cout << "\n" << 8-i << "\t";
        for(int j = 0; j < 8; j++){
            if (j==0) {
                cout<< "|";
            }
            if (board[i][j]!=0) {
                if (board[i][j]->isBlack) {
                    string print = board[i][j]->type;
                    print = print + "B";
                    long p = 11 - print.size();
                    if ((i+j)%2 !=0) {
                        while (p >= 2) {
                            print = "|" + print + "|";
                            p = p-2;
                        }
                        if (p==1) {
                            print = print + "|";
                        }
                        if (j!=0) {
                            print = "|" + print;
                        }
                        cout<< print << "|";
                    }
                    else {
                        while (p >= 2) {
                            print = " " + print + " ";
                            p = p-2;
                        }
                        if (p==1) {
                            print = print + " ";
                        }
                        if (j==7) {
                            print = print + "|";
                        }
                        cout << print;
                    }
                }
                else {
                    string print = board[i][j]->type;
                    print = print + "W";
                    long p = 11 - print.size();
                    if ((i+j)%2 !=0) {
                        while (p >= 2) {
                            print = "|" + print + "|";
                            p = p-2;
                        }
                        if (p==1) {
                            print = print + "|";
                        }
                        if (j!=0) {
                            print = "|" + print;
                        }
                        cout<< print << "|";
                    }
                    else {
                        while (p >= 2) {
                            print = " " + print + " ";
                            p = p-2;
                        }
                        if (p==1) {
                            print = print + " ";
                        }
                        if (j==7) {
                            print = print + "|";
                        }
                        cout << print;
                    }
                }
            }
            else {
                if ((i+j)%2 ==0) {
                    cout << "    \t\t";
                    if (j==7) {
                        cout<< "|";
                    }
                }
                else {
                    cout << "||||||||||||";
                    if (j!=0) {
                        cout<< "|";
                    }
                }
            }
        }
        cout<< "\t" << 8-i;
        cout<< "\n\t";
        for(int k = 0; k <= 8; k++){
            if (k==8) {
                cout<< "|";
            }
            else if ((i+k)%2 ==0) {
                cout << "|   \t\t";
            }
            else {
                cout << "||||||||||||";
            }
        }
    }
    cout<< "\n\t__________________________________________________________________________________________________\n\n\t\t";
    for(int i = 0; i < 8; i++){
        cout << " "<< (char)(97+i) << "\t\t\t ";
    }
    cout << "\n\n";
}
