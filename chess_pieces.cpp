#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include "chess_pieces.h"
#include "chess_board.h"

using namespace std;

Piece::Piece(string type, bool isBlack):type(type),isBlack(isBlack)
{}
Piece::Piece():type(""), isBlack(true)
{}
void Piece::generate_moves(Board game, int x_cor, int y_cor, stack<int> &x_cans, stack<int> &y_cans){
cout<< "t\n";
}


Rook::Rook(bool isBlack) :Piece::Piece("rook", isBlack){}
void Rook::generate_moves(Board game, int x_cor, int y_cor, stack<int> &x_cans, stack<int> &y_cans) {
            //up direction
            int i=y_cor+1;
            while(i<8){
                if (game.board[i][x_cor]!=0){
                    if (game.board[i][x_cor]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                        x_cans.push(x_cor);
                        y_cans.push(i);
                    }
                    break;
                }
                else {
                    x_cans.push(x_cor);
                    y_cans.push(i);
                }
                i++;
            }
            //down direction
            i=y_cor-1;
            while(i>=0){
                if (game.board[i][x_cor]!=0){
                    if (game.board[i][x_cor]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                        x_cans.push(x_cor);
                        y_cans.push(i);
                    }
                    break;
                }
                else {
                    x_cans.push(x_cor);
                    y_cans.push(i);
                }
                i--;
            }
            //right direction
            i=x_cor+1;
            while(i<8){
                if (game.board[y_cor][i]!=0){
                    if (game.board[y_cor][i]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(y_cor);
                    }
                    break;
                }
                else {
                    x_cans.push(i);
                    y_cans.push(y_cor);
                }
                i++;
            }
            //left direction
            i=x_cor-1;
            while(i>=0){
                if (game.board[y_cor][i]!=0){
                    if (game.board[y_cor][i]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(y_cor);
                    }
                    break;
                }
                else {
                    x_cans.push(i);
                    y_cans.push(y_cor);
                }
                i--;
            }
        }


Knight::Knight(bool isBlack) :Piece("knight", isBlack){}
    void Knight::generate_moves(Board game, int x_cor, int y_cor, stack<int> &x_cans, stack<int> &y_cans) {
            //up L's
            int i=y_cor+2;
            if (i<8){
                if (x_cor-1>=0){
                    if (game.board[i][x_cor-1]!=0){
                        if (game.board[i][x_cor]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                            x_cans.push(x_cor-1);
                            y_cans.push(i);
                        }
                    }
                    else{
                        x_cans.push(x_cor-1);
                        y_cans.push(i);
                    }
                }
                if (x_cor+1<8){
                    if (game.board[i][x_cor+1]!=0){
                        if (game.board[i][x_cor+1]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                            x_cans.push(x_cor+1);
                            y_cans.push(i);
                        }
                    }
                    else{
                        x_cans.push(x_cor+1);
                        y_cans.push(i);
                    }
                }
            }
            //down L's
            i=y_cor-2;
            if (i>=0){
                if (x_cor-1>=0){
                    if (game.board[i][x_cor-1]!=0){
                        if (game.board[i][x_cor]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                            x_cans.push(x_cor-1);
                            y_cans.push(i);
                        }
                    }
                    else{
                        x_cans.push(x_cor-1);
                        y_cans.push(i);
                    }
                }
                if (x_cor+1<8){
                    if (game.board[i][x_cor+1]!=0){
                        if (game.board[i][x_cor+1]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                            x_cans.push(x_cor+1);
                            y_cans.push(i);
                        }
                    }
                    else{
                        x_cans.push(x_cor+1);
                        y_cans.push(i);
                    }
                }
            }
            //left L's
            i=x_cor-2;
            if (i>=0){
                if (y_cor-1>=0){
                    if (game.board[y_cor-1][i]!=0){
                        if (game.board[y_cor-1][i]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                            x_cans.push(i);
                            y_cans.push(y_cor-1);
                        }
                    }
                    else{
                        x_cans.push(i);
                        y_cans.push(y_cor-1);
                    }
                }
                if (y_cor+1<8){
                    if (game.board[y_cor+1][i]!=0){
                        if (game.board[y_cor+1][i]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                            x_cans.push(i);
                            y_cans.push(y_cor+1);
                        }
                    }
                    else{
                        x_cans.push(i);
                        y_cans.push(y_cor+1);
                    }
                }
            }
            //right L's
            i=x_cor+2;
            if (i<8){
                if (y_cor-1>=0){
                    if (game.board[y_cor-1][i]!=0){
                        if (game.board[y_cor-1][i]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                            x_cans.push(i);
                            y_cans.push(y_cor-1);
                        }
                    }
                    else{
                        x_cans.push(i);
                        y_cans.push(y_cor-1);
                    }
                }
                if (y_cor+1<8){
                    if (game.board[y_cor+1][i]!=0){
                        if (game.board[y_cor+1][i]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                            x_cans.push(i);
                            y_cans.push(y_cor+1);
                        }
                    }
                    else{
                        x_cans.push(i);
                        y_cans.push(y_cor+1);
                    }
                }
            }
    }


Bishop::Bishop(bool isBlack) :Piece("bishop", isBlack) {}
    void Bishop::generate_moves(Board game, int x_cor, int y_cor, stack<int> &x_cans, stack<int> &y_cans) {
            cout<<"Can move ";
            //up-right direction
            int i=y_cor+1;
        int j=x_cor+1;
            while(i<8 && j<8){
                if (game.board[j][i]!=0){
                    if (game.board[j][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(j);
                        y_cans.push(i);
                        cout<<"("<<j<<","<<i<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(j);
                    y_cans.push(i);
                    cout<<"("<<j<<","<<i<<") ";
                }
                i++;
                j++;
            }
            //down right direction
            i=y_cor-1;
            j=x_cor+1;
            while(i>=0 && j<8){
                if (game.board[j][i]!=0){
                    if (game.board[j][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(j);
                        y_cans.push(i);
                        cout<<"("<<j<<","<<i<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(j);
                    y_cans.push(i);
                    cout<<"("<<j<<","<<i<<") ";
                }
                i--;
                j++;
            }
            //up left direction
            i=x_cor-1;
            j=y_cor+1;
            while(i>=0 && j<8){
                if (game.board[i][j]!=0){
                    if (game.board[i][j]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(j);
                        cout<<"("<<i<<","<<j<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(i);
                    y_cans.push(j);
                    cout<<"("<<i<<","<<j<<") ";
                }
                i--;
                j++;
            }
            //down left direction
            i=x_cor-1;
            j=y_cor-1;
            while(i>=0 && j>=0){
                if (game.board[i][j]!=0){
                    if (game.board[i][j]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(j);
                        cout<<"("<<i<<","<<j<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(i);
                    y_cans.push(j);
                    cout<<"("<<i<<","<<j<<") ";
                }
                i--;
                j--;
            }
        }


Queen::Queen(bool isBlack) :Piece("queen", isBlack){}
    void Queen::generate_moves(Board game, int x_cor, int y_cor, stack<int> &x_cans, stack<int> &y_cans) {
            cout<<"Can move ";
            //up-right direction
            int i=y_cor+1;
        int j=x_cor+1;
            while(i<8 && j<8){
                if (game.board[j][i]!=0){
                    if (game.board[j][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(j);
                        y_cans.push(i);
                        cout<<"("<<j<<","<<i<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(j);
                    y_cans.push(i);
                    cout<<"("<<j<<","<<i<<") ";
                }
                i++;
                j++;
            }
            //down right direction
            i=y_cor-1;
            j=x_cor+1;
            while(i>=0 && j<8){
                if (game.board[j][i]!=0){
                    if (game.board[j][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(j);
                        y_cans.push(i);
                        cout<<"("<<j<<","<<i<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(j);
                    y_cans.push(i);
                    cout<<"("<<j<<","<<i<<") ";
                }
                i--;
                j++;
            }
            //up left direction
            i=x_cor-1;
            j=y_cor+1;
            while(i>=0 && j<8){
                if (game.board[i][j]!=0){
                    if (game.board[i][j]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(j);
                        cout<<"("<<i<<","<<j<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(i);
                    y_cans.push(j);
                    cout<<"("<<i<<","<<j<<") ";
                }
                i--;
                j++;
            }
            //down left direction
            i=x_cor-1;
            j=y_cor-1;
            while(i>=0 && j>=0){
                if (game.board[i][j]!=0){
                    if (game.board[i][j]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(j);
                        cout<<"("<<i<<","<<j<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(i);
                    y_cans.push(j);
                    cout<<"("<<i<<","<<j<<") ";
                }
                i--;
                j--;
            }
            //up direction
            i=y_cor+1;
            while(i<8){
                if (game.board[x_cor][i]!=0){
                    if (game.board[x_cor][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(x_cor);
                        y_cans.push(i);
                        cout<<"("<<x_cor<<","<<i<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(x_cor);
                    y_cans.push(i);
                    cout<<"("<<x_cor<<","<<i<<") ";
                }
                i++;
            }
            //down direction
            i=y_cor-1;
            while(i>=0){
                if (game.board[x_cor][i]!=0){
                    if (game.board[x_cor][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(x_cor);
                        y_cans.push(i);
                        cout<<"("<<x_cor<<","<<i<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(x_cor);
                    y_cans.push(i);
                    cout<<"("<<x_cor<<","<<i<<") ";
                }
                i--;
            }
            //right direction
            i=x_cor+1;
            while(i<8){
                if (game.board[i][y_cor]!=0){
                    if (game.board[i][y_cor]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(y_cor);
                        cout<<"("<<i<<","<<y_cor<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(i);
                    y_cans.push(y_cor);
                    cout<<"("<<i<<","<<y_cor<<") ";
                }
                i++;
            }
            //left direction
            i=x_cor-1;
            while(i>=0){
                if (game.board[i][y_cor]!=0){
                    if (game.board[i][y_cor]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(y_cor);
                        cout<<"("<<i<<","<<y_cor<<") ";
                    }
                    break;
                }
                else {
                    x_cans.push(i);
                    y_cans.push(y_cor);
                    cout<<"("<<i<<","<<y_cor<<") ";
                }
                i--;
            }
        }


King::King(bool isBlack) :Piece("king", isBlack){}
    void King::generate_moves(Board game, int x_cor, int y_cor, stack<int> &x_cans, stack<int> &y_cans) {
            cout<<"Can move ";
            //up-right direction
            int i=y_cor+1;
            int j=x_cor+1;
            if(i<8 && j<8){
                if (game.board[j][i]!=0){
                    if (game.board[j][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(j);
                        y_cans.push(i);
                        cout<<"("<<j<<","<<i<<") ";
                    }
                }
                else {
                    x_cans.push(j);
                    y_cans.push(i);
                    cout<<"("<<j<<","<<i<<") ";
                }
            }
            //down right direction
            i=y_cor-1;
            j=x_cor+1;
            if (i>=0 && j<8){
                if (game.board[j][i]!=0){
                    if (game.board[j][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(j);
                        y_cans.push(i);
                        cout<<"("<<j<<","<<i<<") ";
                    }
                }
                else {
                    x_cans.push(j);
                    y_cans.push(i);
                    cout<<"("<<j<<","<<i<<") ";
                }
            }
            //up left direction
            i=x_cor-1;
            j=y_cor+1;
            if (i>=0 && j<8){
                if (game.board[i][j]!=0){
                    if (game.board[i][j]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(j);
                        cout<<"("<<i<<","<<j<<") ";
                    }
                }
                else {
                    x_cans.push(i);
                    y_cans.push(j);
                    cout<<"("<<i<<","<<j<<") ";
                }
            }
            //down left direction
            i=x_cor-1;
            j=y_cor-1;
            if (i>=0 && j>=0){
                if (game.board[i][j]!=0){
                    if (game.board[i][j]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(j);
                        cout<<"("<<i<<","<<j<<") ";
                    }
                }
                else {
                    x_cans.push(i);
                    y_cans.push(j);
                    cout<<"("<<i<<","<<j<<") ";
                }
            }
            //up direction
            i=y_cor+1;
            if (i<8){
                if (game.board[x_cor][i]!=0){
                    if (game.board[x_cor][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(x_cor);
                        y_cans.push(i);
                        cout<<"("<<x_cor<<","<<i<<") ";
                    }
                }
                else {
                    x_cans.push(x_cor);
                    y_cans.push(i);
                    cout<<"("<<x_cor<<","<<i<<") ";
                }
            }
            //down direction
            i=y_cor-1;
            if (i>=0){
                if (game.board[x_cor][i]!=0){
                    if (game.board[x_cor][i]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(x_cor);
                        y_cans.push(i);
                        cout<<"("<<x_cor<<","<<i<<") ";
                    }
                }
                else {
                    x_cans.push(x_cor);
                    y_cans.push(i);
                    cout<<"("<<x_cor<<","<<i<<") ";
                }
            }
            //right direction
            i=x_cor+1;
            if (i<8){
                if (game.board[i][y_cor]!=0){
                    if (game.board[i][y_cor]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(y_cor);
                        cout<<"("<<i<<","<<y_cor<<") ";
                    }
                }
                else {
                    x_cans.push(i);
                    y_cans.push(y_cor);
                    cout<<"("<<i<<","<<y_cor<<") ";
                }
            }
            //left direction
            i=x_cor-1;
            if (i>=0){
                if (game.board[i][y_cor]!=0){
                    if (game.board[i][y_cor]->isBlack!=game.board[x_cor][y_cor]->isBlack){
                        x_cans.push(i);
                        y_cans.push(y_cor);
                        cout<<"("<<i<<","<<y_cor<<") ";
                    }
                }
                else {
                    x_cans.push(i);
                    y_cans.push(y_cor);
                    cout<<"("<<i<<","<<y_cor<<") ";
                }
            }
        }


Pawn::Pawn(bool isBlack) :Piece("pawn", isBlack){}
    void Pawn::generate_moves(Board game, int x_cor, int y_cor, stack<int> &x_cans, stack<int> &y_cans) {
            cout<<"Can move ";
            //Black moves down
            if (game.board[y_cor][x_cor]->isBlack){
                int i=y_cor+1;
                if (i<8){
                    if (game.board[i][x_cor]==0){
                        x_cans.push(x_cor);
                        y_cans.push(i);
                    }
                    if (x_cor+1<8){
                        if (game.board[i][x_cor+1]!=0){
                            if (game.board[i][x_cor+1]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                                x_cans.push(x_cor+1);
                                y_cans.push(i);
                            }
                        }
                    }
                    if (x_cor-1>=0){
                        if (game.board[i][x_cor-1]!=0){
                            if (game.board[i][x_cor-1]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                                x_cans.push(x_cor-1);
                                y_cans.push(i);
                            }
                        }
                    }
                }
                //Can move down two at start
                if (y_cor==1){
                    if (game.board[i][x_cor]==0){
                        if (game.board[i+1][x_cor]==0){
                            x_cans.push(x_cor);
                            y_cans.push(i+1);
                        }
                    }
                }
            }
            //White moves up
            else{
                int i=y_cor-1;
                if (i>=0){
                    if (game.board[i][x_cor]==0){
                        x_cans.push(x_cor);
                        y_cans.push(i);
                    }
                    if (x_cor+1<8){
                        if (game.board[i][x_cor+1]!=0){
                            if (game.board[i][x_cor+1]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                                x_cans.push(x_cor+1);
                                y_cans.push(i);
                            }
                        }
                    }
                    if (x_cor-1>=0){
                        if (game.board[i][x_cor]!=0){
                            if (game.board[i][x_cor-1]->isBlack!=game.board[y_cor][x_cor]->isBlack){
                                x_cans.push(x_cor-1);
                                y_cans.push(i);
                            }
                        }
                    }
                }
                //Can move up two at start
                //Fix this
                if (y_cor==6){
                    if (game.board[i][x_cor]==0){
                        if (game.board[i-1][x_cor]==0){
                            x_cans.push(x_cor);
                            y_cans.push(i-1);
                        }
                    }
                }

            }
        }
