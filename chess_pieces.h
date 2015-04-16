#ifndef COP3503_Project_chess_pieces_h__included__
#define COP3503_Project_chess_pieces_h__included__

#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
class Board;

class Piece {
public:
    const std::string type;
    const bool isBlack;
    Piece(std::string type, bool isBlack);
    Piece();
    virtual void generate_moves(Board game, int x_cor, int y_cor, std::stack<int> &x_cans, std::stack<int> &y_cans)=0;
};


class Rook : public Piece {
public:
    Rook(bool isBlack);
    void generate_moves(Board game, int x_cor, int y_cor, std::stack<int> &x_cans, std::stack<int> &y_cans);
};

class Knight : public Piece {
public:
    Knight(bool isBlack);
    void generate_moves(Board game, int x_cor, int y_cor, std::stack<int> &x_cans, std::stack<int> &y_cans);
    
};

class Bishop : public Piece {
public:
    Bishop(bool isBlack);
    void generate_moves(Board game, int x_cor, int y_cor, std::stack<int> &x_cans, std::stack<int> &y_cans);
};


class Queen : public Piece {
public:
    Queen(bool isBlack);
    void generate_moves(Board game, int x_cor, int y_cor, std::stack<int> &x_cans, std::stack<int> &y_cans);
};


class King : public Piece {
public:
    King(bool isBlack);
    void generate_moves(Board game, int x_cor, int y_cor, std::stack<int> &x_cans, std::stack<int> &y_cans);
};


class Pawn : public Piece {
public:
    Pawn(bool isBlack);
    void generate_moves(Board game, int x_cor, int y_cor, std::stack<int> &x_cans, std::stack<int> &y_cans);
};

#endif
