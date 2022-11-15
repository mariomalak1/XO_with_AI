#ifndef _XO_CLASSES_H
#define _XO_CLASSES_H

using namespace std;
///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
protected:
    string name;
    char symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    Player (char symbol);

    // constructor that takes string which this is name of player, and it's symbol
    Player (string name, char symbol);

    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);

    // Give player info as a string
    string to_string();

    // Get symbol used by player
    char get_symbol();
};

Player::Player(char symbol) {
    this->symbol = symbol;
}

Player::Player(string name, char symbol) {
    this->symbol = symbol;
    this->name = name;
}

void Player::get_move(int &x, int &y) {
    cout << name << " Please enter your move x and y (0 to 2) separated by spaces : ";
    cin >> x >> y;
    if (x > 2 or x < 0 or y > 2 or y < 0){
        cout << "please enter a valid coordinate" << endl;
        get_move(x,y);
    }
}

string Player::to_string() {
    string playerInfo = "player name : " + name + " his symbol : " + symbol;
    return playerInfo;
}

char Player::get_symbol() {
    return symbol;
}



#endif
