#ifndef COP3503_Project_chess_board_h_included__
#define COP3503_Project_chess_board_h_included__

#include <iostream>
#include <vector>
class Piece;

using namespace std;

class Board{
public:
    int boardNum;
    Piece*** board;
    Board(int boardNum, Piece* pieces[6][2]);
    void deleteBoard();
    void printBoard();
private:
    void setup(Piece*** &board, Piece* pieces[6][2]);
};

#endif
