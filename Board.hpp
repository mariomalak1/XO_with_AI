#ifndef UNTITLED2_BOARD_H
#define UNTITLED2_BOARD_H
using namespace std;
#include <bits/stdc++.h>

// This class represents a 3 x 3 board
// used in X_O game
class Board {
private:
    bool IsWinByRaw(char symbol);
    bool IsWinByColumn(char symbol);
    bool IsWinDiagonaly(char symbol);
protected:
    char board[3][3] = {{'0', '0', '0'}, {'0', '0', '0'}, {'0', '0', '0'}};
public:
    char &operator()(int x, int y);
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    bool validCoordinate(int x, int y);

    // function that takes the symbol and the coordinates and update the board with this
    void update_board(int x, int y, char symbol);

    // Returns true if there is any winner
    // either X or O
    bool is_winner(char symbol);

    // return true if no zeroes in the board
    bool IsDraw();

    // Display the board and the pieces on it
    void display_board();

};

bool Board::IsWinByColumn(char symbol) {
    for (int i = 0; i < 3; ++i) {
        if(board[0][i] == symbol and board[0][i] == board[1][i] and board[1][i] == board[2][i]){
            return true;
        }
    }
    return false;
}

bool Board::IsWinByRaw(char symbol) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == symbol and board[i][0] == board[i][1] and board[i][1] == board[i][2]) {
            return true;
        }
    }
    return false;
}

bool Board::IsWinDiagonaly(char symbol) {
    if(board[0][0] == symbol and  board[1][1] == board[0][0] and board[1][1] == board[2][2]){
        return true;
    }
    else if(board[0][2] == symbol and  board[1][1] == board[0][2] and board[1][1] == board[2][0]){
        return true;
    }
    return false;
}

void Board::display_board() {
    for (int i = 0; i <= 2; ++i) {
        cout << "| ";
        for (int j = 0; j <= 2; ++j) {
            if(board[i][j] == '0'){
                cout << "0" << " | ";
            }else{
                cout << board[i][j] << " | ";
            }
        }
        cout << endl;
    }
}

void Board::update_board(int x, int y, char symbol) {
    if(validCoordinate(x,y)) {
        board[x][y] = symbol;
    }else{
        cout << "please enter valid coordinates" << endl;
    }
}

bool Board::is_winner(char symbol){
    if(IsWinByRaw(symbol) or IsWinByColumn(symbol) or IsWinDiagonaly(symbol)){
        return true;
    }else{
        return false;
    }
}

bool Board::validCoordinate(int x, int y) {
    if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[x][y] == '0') {
        return true;
    }
    else{
        return false;
    }
}

bool Board::IsDraw() {
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            if(board[i][j] == '0'){
                return false;
            }
        }
    }
    return true;
}

char &Board::operator()(int x, int y) {
    return board[x][y];
}

#endif //UNTITLED2_BOARD_H