#ifndef COP3503_Project_chess_pieces_h
#define COP3503_Project_chess_pieces_h

#include <iostream>
#include <string>
#include "chess_pieces.h"

using namespace std;

class Piece {
public:
    const std::string type;
    const bool isBlack;
    Piece(std::string type, bool isBlack):type(type),isBlack(isBlack)
    {}
    virtual void move()
    {}
};


class Rook : public Piece {
public:
    Rook(bool isBlack) :Piece("rook", isBlack){}
    void move() {
        
    }
};

class Knight : public Piece {
public:
    Knight(bool isBlack) :Piece("knight", isBlack){}
    void move() {
        
    }
    
};

class Bishop : public Piece {
public:
    Bishop(bool isBlack) :Piece("bishop", isBlack){}
    void move() {
        
    }
    
};

class Queen : public Piece {
public:
    Queen(bool isBlack) :Piece("queen", isBlack){}
    void move() {
        
    }
    
};

class King : public Piece {
public:
    King(bool isBlack) :Piece("king", isBlack){}
    void move() {
        
    }
};

class Pawn : public Piece {
public:
    Pawn(bool isBlack) :Piece("pawn", isBlack){}
    void move() {
        
    }
};

#endif
