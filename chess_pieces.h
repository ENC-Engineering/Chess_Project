#ifndef COP3503_Project_chess_pieces_h
#define COP3503_Project_chess_pieces_h

#include <iostream>
#include <string>
#include <stack>
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
    bool move(int x_cor, int y_cor) {
        bool has_moved=false;
        stack<int> x_cans;
        stack<int> y_cans;
        cout<<"Can move "
        //up direction
        int i=y_cor+1;
        while(i<8){
            if (board[x_cor][i]!=0){
                if (board[x_cor][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[x_cor][i]!=0){
                if (board[x_cor][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][y_cor]!=0){
                if (board[i][y_cor]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][y_cor]!=0){
                if (board[i][y_cor]->isBlack!=board[x_cor][y_cor]->isBlack){
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
        //Checks the stack of available moves and compares to where you want to move
        int x_move_to=0;
        int y_move_to=0;
        bool x_input = false;
        bool y_input = false;
        //This while loop will be replaced with a "listen for click" function
        while (!y_input || !x_input) {
            x_move_to=0;
            y_move_to=0;
            cout<< "Where would you like to move (x,y)?"
            int i=0;
            line = getline();
            for (int j=0; j<2; j++) {
                while (!(line.at(i)>48 && line.at(i)<57)) {
                    i++;
                }
                if (line.at(i) && j=0) {
                    cin>>x_move_to;
                    x_input = true;
                }
                else if (line.at(i) && j=1) {
                    cin>> y_move_to;
                    y_input = true;
                }
                else {
                    cout<< "Invalid Input. Please enter in the form (x,y)";
                    break;
                }
            
            }
        }
        while(!x_cans.empty() && !y_cans.empty()){
            if (x_move_to==x_cans.top() && y_move_to==y_cans.top()){
                Piece* temp=board[x_cor][y_cor];
                board[x_move_to][y_move_to]=board[x_cor][y_cor];
                board[x_cor][y_cor]=0;
                //Checks to make sure you didnt put yourself in check
                has_moved=true;
                //if checked yourself is true then move piece back and hasMoved = false
                break;
            }
            x_cans.pop();
            y_cans.pop();
        }
        return has_moved;
    }
};

class Knight : public Piece {
public:
    Knight(bool isBlack) :Piece("knight", isBlack){}
    bool move(int x_cor, int y_cor) {
        bool has_moved=false;
        stack<int> x_cans;
        stack<int> y_cans;
        cout<<"Can move ";
        //up L's
        int i=y_cor+2;
        if (i<8){
            if (x_cor-1>=0){
                if (board[x_cor-1][i]!=0){
                    if (board[x_cor-1][i]->isBlack!=board[x_cor][y_cor]){
                        cout<<"("<<x_cor-1<<","<<i<<") "
                        x_cans.push(x_cor-1);
                        y_cans.push(i);
                    }
                }
                else{
                    cout<<"("<<x_cor-1<<","<<i<<") "
                    x_cans.push(x_cor-1);
                    y_cans.push(i);
                }
            }
            if (x_cor+1<8){
                if (board[x_cor+1][i]!=0){
                    if (board[x_cor+1][i]->isBlack!=board[x_cor][y_cor]){
                        cout<<"("<<x_cor+1<<","<<i<<") "
                        x_cans.push(x_cor+1);
                        y_cans.push(i);
                    }
                }
                else{
                    cout<<"("<<x_cor+1<<","<<i<<") "
                    x_cans.push(x_cor+1);
                    y_cans.push(i);
                }
            }
        }
        //down L's
        i=y_cor-2;
        if (i>=0){
            if (x_cor-1>=0){
                if (board[x_cor-1][i]!=0){
                    if (board[x_cor-1][i]->isBlack!=board[x_cor][y_cor]){
                        cout<<"("<<x_cor-1<<","<<i<<") "
                        x_cans.push(x_cor-1);
                        y_cans.push(i);
                    }
                }
                else{
                    cout<<"("<<x_cor-1<<","<<i<<") "
                    x_cans.push(x_cor-1);
                    y_cans.push(i);
                }
            }
            if (x_cor+1<8){
                if (board[x_cor+1][i]!=0){
                    if (board[x_cor+1][i]->isBlack!=board[x_cor][y_cor]){
                        cout<<"("<<x_cor+1<<","<<i<<") "
                        x_cans.push(x_cor+1);
                        y_cans.push(i);
                    }
                }
                else{
                    cout<<"("<<x_cor+1<<","<<i<<") "
                    x_cans.push(x_cor+1);
                    y_cans.push(i);
                }
            }
        }
        //left L's
        i=x_cor-2;
        if (i>=0){
            if (y_cor-1>=0){
                if (board[i][y_cor-1]!=0){
                    if (board[i][y_cor-1]->isBlack!=board[x_cor][y_cor]){
                        cout<<"("<<i<<","<<y_cor-1<<") "
                        x_cans.push(i);
                        y_cans.push(y_cor-1);
                    }
                }
                else{
                    cout<<"("<<i<<","<<y_cor-1<<") "
                    x_cans.push(i);
                    y_cans.push(y_cor-1);
                }
            }
           if (y_cor+1>=0){
                if (board[i][y_cor+1]!=0){
                    if (board[i][y_cor+1]->isBlack!=board[x_cor][y_cor]){
                        cout<<"("<<i<<","<<y_cor+1<<") "
                        x_cans.push(i);
                        y_cans.push(y_cor+1);
                    }
                }
                else{
                    cout<<"("<<i<<","<<y_cor+1<<") "
                        x_cans.push(i);
                        y_cans.push(y_cor+1);
                }
            }
        }
        //right L's
        i=x_cor+2;
        if (i<8){
            if (y_cor-1>=0){
                if (board[i][y_cor-1]!=0){
                    if (board[i][y_cor-1]->isBlack!=board[x_cor][y_cor]){
                        cout<<"("<<i<<","<<y_cor-1<<") "
                        x_cans.push(i);
                        y_cans.push(y_cor-1);
                    }
                }
                else{
                    cout<<"("<<i<<","<<y_cor-1<<") "
                    x_cans.push(i);
                    y_cans.push(y_cor-1);
                }
            }
           if (y_cor+1>=0){
                if (board[i][y_cor+1]!=0){
                    if (board[i][y_cor+1]->isBlack!=board[x_cor][y_cor]){
                        cout<<"("<<i<<","<<y_cor+1<<") "
                        x_cans.push(i);
                        y_cans.push(y_cor+1);
                    }
                }
                else{
                    cout<<"("<<i<<","<<y_cor+1<<") "
                    x_cans.push(i);
                    y_cans.push(y_cor+1);
                }
            }
        }
        //Checks the stack of available moves and compares to where you want to move
        int x_move_to=0;
        int y_move_to=0;
        bool x_input = false;
        bool y_input = false;
        //This while loop will be replaced with a "listen for click" function
        while (!y_input || !x_input) {
            x_move_to=0;
            y_move_to=0;
            cout<< "Where would you like to move (x,y)?"
            int i=0;
            line = getline();
            for (int j=0; j<2; j++) {
                while (!(line.at(i)>48 && line.at(i)<57)) {
                    i++;
                }
                if (line.at(i) && j=0) {
                    cin>>x_move_to;
                    x_input = true;
                }
                else if (line.at(i) && j=1) {
                    cin>> y_move_to;
                    y_input = true;
                }
                else {
                    cout<< "Invalid Input. Please enter in the form (x,y)";
                    break;
                }
            
            }
        }
        while(!x_cans.empty() && !y_cans.empty()){
            if (x_move_to==x_cans.top() && y_move_to==y_cans.top()){
                Piece* temp=board[x_cor][y_cor];
                board[x_move_to][y_move_to]=board[x_cor][y_cor];
                board[x_cor][y_cor]=0;
                //Checks to make sure you didnt put yourself in check
                has_moved=true;
                //if checked yourself is true then move piece back and hasMoved = false
                break;
            }
            x_cans.pop();
            y_cans.pop();
        }
        return has_moved; 
    }
    
};

class Bishop : public Piece {
public:
    Bishop(bool isBlack) :Piece("bishop", isBlack){}
    bool move(int x_cor, int y_cor) {
        bool has_moved=false;
        stack<int> x_cans;
        stack<int> y_cans;
        cout<<"Can move "
        //up-right direction
        int i=y_cor+1;
        int j=x_cor+1
        while(i<8 && j<8){
            if (board[j][i]!=0){
                if (board[j][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[j][i]!=0){
                if (board[j][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][j]!=0){
                if (board[i][j]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][j]!=0){
                if (board[i][j]->isBlack!=board[x_cor][y_cor]->isBlack){
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
        //Checks the stack of available moves and compares to where you want to move
        int x_move_to=0;
        int y_move_to=0;
        bool x_input = false;
        bool y_input = false;
        //This while loop will be replaced with a "listen for click" function
        while (!y_input || !x_input) {
            x_move_to=0;
            y_move_to=0;
            cout<< "Where would you like to move (x,y)?"
            int i=0;
            line = getline();
            for (int j=0; j<2; j++) {
                while (!(line.at(i)>48 && line.at(i)<57)) {
                    i++;
                }
                if (line.at(i) && j=0) {
                    cin>>x_move_to;
                    x_input = true;
                }
                else if (line.at(i) && j=1) {
                    cin>> y_move_to;
                    y_input = true;
                }
                else {
                    cout<< "Invalid Input. Please enter in the form (x,y)";
                    break;
                }
            
            }
        }
        while(!x_cans.empty() && !y_cans.empty()){
            if (x_move_to==x_cans.top() && y_move_to==y_cans.top()){
                Piece* temp=board[x_cor][y_cor];
                board[x_move_to][y_move_to]=board[x_cor][y_cor];
                board[x_cor][y_cor]=0;
                //Checks to make sure you didnt put yourself in check
                has_moved=true;
                //if checked yourself is true then move piece back and hasMoved = false
                break;
            }
            x_cans.pop();
            y_cans.pop();
        }
        return has_moved;
    }        
};

class Queen : public Piece {
public:
    Queen(bool isBlack) :Piece("queen", isBlack){}
    bool move(int x_cor, int y_cor) {
        bool has_moved=false;
        stack<int> x_cans;
        stack<int> y_cans;
        cout<<"Can move "
        //up-right direction
        int i=y_cor+1;
        int j=x_cor+1
        while(i<8 && j<8){
            if (board[j][i]!=0){
                if (board[j][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[j][i]!=0){
                if (board[j][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][j]!=0){
                if (board[i][j]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][j]!=0){
                if (board[i][j]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[x_cor][i]!=0){
                if (board[x_cor][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[x_cor][i]!=0){
                if (board[x_cor][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][y_cor]!=0){
                if (board[i][y_cor]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][y_cor]!=0){
                if (board[i][y_cor]->isBlack!=board[x_cor][y_cor]->isBlack){
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
        //Checks the stack of available moves and compares to where you want to move
        int x_move_to=0;
        int y_move_to=0;
        bool x_input = false;
        bool y_input = false;
        //This while loop will be replaced with a "listen for click" function
        while (!y_input || !x_input) {
            x_move_to=0;
            y_move_to=0;
            cout<< "Where would you like to move (x,y)?"
            int i=0;
            line = getline();
            for (int j=0; j<2; j++) {
                while (!(line.at(i)>48 && line.at(i)<57)) {
                    i++;
                }
                if (line.at(i) && j=0) {
                    cin>>x_move_to;
                    x_input = true;
                }
                else if (line.at(i) && j=1) {
                    cin>> y_move_to;
                    y_input = true;
                }
                else {
                    cout<< "Invalid Input. Please enter in the form (x,y)";
                    break;
                }
            
            }
        }
        while(!x_cans.empty() && !y_cans.empty()){
            if (x_move_to==x_cans.top() && y_move_to==y_cans.top()){
                Piece* temp=board[x_cor][y_cor];
                board[x_move_to][y_move_to]=board[x_cor][y_cor];
                board[x_cor][y_cor]=0;
                //Checks to make sure you didnt put yourself in check
                has_moved=true;
                //if checked yourself is true then move piece back and hasMoved = false
                break;
            }
            x_cans.pop();
            y_cans.pop();
        }
        return has_moved;
    }
};

class King : public Piece {
public:
    King(bool isBlack) :Piece("king", isBlack){}
    bool move(int x_cor, int y_cor) {
        bool has_moved=false;
        stack<int> x_cans;
        stack<int> y_cans;
        cout<<"Can move "
        //up-right direction
        int i=y_cor+1;
        int j=x_cor+1
        if(i<8 && j<8){
            if (board[j][i]!=0){
                if (board[j][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[j][i]!=0){
                if (board[j][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][j]!=0){
                if (board[i][j]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][j]!=0){
                if (board[i][j]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[x_cor][i]!=0){
                if (board[x_cor][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[x_cor][i]!=0){
                if (board[x_cor][i]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][y_cor]!=0){
                if (board[i][y_cor]->isBlack!=board[x_cor][y_cor]->isBlack){
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
            if (board[i][y_cor]!=0){
                if (board[i][y_cor]->isBlack!=board[x_cor][y_cor]->isBlack){
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
        //Checks the stack of available moves and compares to where you want to move
        int x_move_to=0;
        int y_move_to=0;
        bool x_input = false;
        bool y_input = false;
        //This while loop will be replaced with a "listen for click" function
        while (!y_input || !x_input) {
            x_move_to=0;
            y_move_to=0;
            cout<< "Where would you like to move (x,y)?"
            int i=0;
            line = getline();
            for (int j=0; j<2; j++) {
                while (!(line.at(i)>48 && line.at(i)<57)) {
                    i++;
                }
                if (line.at(i) && j=0) {
                    cin>>x_move_to;
                    x_input = true;
                }
                else if (line.at(i) && j=1) {
                    cin>> y_move_to;
                    y_input = true;
                }
                else {
                    cout<< "Invalid Input. Please enter in the form (x,y)";
                    break;
                }
            
            }
        }
        while(!x_cans.empty() && !y_cans.empty()){
            if (x_move_to==x_cans.top() && y_move_to==y_cans.top()){
                Piece* temp=board[x_cor][y_cor];
                board[x_move_to][y_move_to]=board[x_cor][y_cor];
                board[x_cor][y_cor]=0;
                //Checks to make sure you didnt put yourself in check
                has_moved=true;
                //if checked yourself is true then move piece back and hasMoved = false
                break;
            }
            x_cans.pop();
            y_cans.pop();
        }
        return has_moved;
    }
};

class Pawn : public Piece {
public:
    Pawn(bool isBlack) :Piece("pawn", isBlack){}
    bool move(int x_cor,int y_cor) {
        bool has_moved=false;
        stack<int> x_cans;
        stack<int> y_cans;
        cout<<"Can move "
        //Black moves down
        if (board[x_cor][y_cor]->isBlack){
            int i=y_cor-1;
            if (i>=0){
                if (board[x_cor][i]==0){
                    cout<<"("<<x_cor<<","<<i<<") "
                    x_cans.push(x_cor);
                    y_cans.push(i);
                }
                if (x_cor+1<8){
                    if (board[x_cor+1][i]!=0){
                        if (board[x_cor+1][i]->isBlack!=board[x_cor][y_cor]){
                            cout<<"("<<x_cor+1<<","<<i<<") "
                            x_cans.push(x_cor+1);
                            y_cans.push(i);
                        }
                    }
                }
                if (x_cor-1>=0){
                    if (board[x_cor-1][i]!=0){
                        if (board[x_cor-1][i]->isBlack!=board[x_cor][y_cor]){
                            cout<<"("<<x_cor-1<<","<<i<<") "
                            x_cans.push(x_cor-1);
                            y_cans.push(i);
                        }
                    }
                }
            }
            //Can move down two at start
            if (y_cor==6){
                if (board[x_cor][i-1]==0){
                    cout<<"("<<x_cor<<","<<i<<") "
                    x_cans.push(x_cor);
                    y_cans.push(i-1);
                }
            }
        }
        //White moves up
        else{
            int i=y_cor+1;
            if (i<8){
                if (board[x_cor][i]==0){
                    cout<<"("<<x_cor<<","<<i<<") "
                    x_cans.push(x_cor);
                    y_cans.push(i);
                }
                if (x_cor+1<8){
                    if (board[x_cor+1][i]!=0){
                        if (board[x_cor+1][i]->isBlack!=board[x_cor][y_cor]){
                            cout<<"("<<x_cor+1<<","<<i<<") "
                            x_cans.push(x_cor+1);
                            y_cans.push(i);
                        }
                    }
                }
                if (x_cor-1>=0){
                    if (board[x_cor-1][i]!=0){
                        if (board[x_cor-1][i]->isBlack!=board[x_cor][y_cor]){
                            cout<<"("<<x_cor-1<<","<<i<<") "
                            x_cans.push(x_cor-1);
                            y_cans.push(i);
                        }
                    }
                }
            }
            //Can move up two at start
            if (y_cor==1){
                if (board[x_cor][i+1]==0){
                    cout<<"("<<x_cor<<","<<i<<") "
                    x_cans.push(x_cor);
                    y_cans.push(i+1);
                }
            }
        }
        //Checks the stack of available moves and compares to where you want to move
        int x_move_to=0;
        int y_move_to=0;
        bool x_input = false;
        bool y_input = false;
        //This while loop will be replaced with a "listen for click" function
        while (!y_input || !x_input) {
            x_move_to=0;
            y_move_to=0;
            cout<< "Where would you like to move (x,y)?"
            int i=0;
            line = getline();
            for (int j=0; j<2; j++) {
                while (!(line.at(i)>48 && line.at(i)<57)) {
                    i++;
                }
                if (line.at(i) && j=0) {
                    cin>>x_move_to;
                    x_input = true;
                }
                else if (line.at(i) && j=1) {
                    cin>> y_move_to;
                    y_input = true;
                }
                else {
                    cout<< "Invalid Input. Please enter in the form (x,y)";
                    break;
                }
            
            }
        }
        while(!x_cans.empty() && !y_cans.empty()){
            if (x_move_to==x_cans.top() && y_move_to==y_cans.top()){
                Piece* temp=board[x_cor][y_cor];
                board[x_move_to][y_move_to]=board[x_cor][y_cor];
                board[x_cor][y_cor]=0;
                //Checks to make sure you didnt put yourself in check
                has_moved=true;
                //if checked yourself is true then move piece back and hasMoved = false
                break;
            }
            x_cans.pop();
            y_cans.pop();
        }
        return has_moved;        
    }
};

#endif
