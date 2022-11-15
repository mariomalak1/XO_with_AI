///////////////////////////////////////////
// This class represents the engine that runs
// X-O games and gives players turns, sees if
// either of them won or it is draw.
// It has one method to start and run the game.

#ifndef UNTITLED2_GAMEMANGER_H
#define UNTITLED2_GAMEMANGER_H
#include "Board.hpp"
#include "ComputerPlayer.h"

class GameManager {
public:
    int x, y;

    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If drawn, declare so and end
    void run();
    void playWithComputer(Board &board, Player player1);
    void playWithHuman(Board &board, Player player1);
};

void GameManager::run() {
    string name1;
    char symbol1, choose;
    Board board;

    cout << "enter your name : ";
    getline(cin, name1);
    symbol1 = 'x';
    Player player1(name1, symbol1);
    cout << player1.to_string() << endl;


    cout << "to play with someone enter y, if you want to play with computer enter c : ";
    cin >> choose;
    if(choose == 'y' or choose == 'Y'){
        playWithHuman(board, player1);
    }else if(choose == 'c' or choose == 'C'){
        playWithComputer(board, player1);
    }else{
        cout << "enter a valid value c or y." << endl;
        run();
    }

}

void GameManager::playWithComputer(Board &board, Player player1) {
    ComputerPlayer player2('o');

    while (true) {
        board.display_board();
        coordinatePlayer1:
        player1.get_move(x,y);
        if(! board.validCoordinate(x,y)){
            cout << "please enter valid coordinate" << endl;
            goto coordinatePlayer1;
        }

        board.update_board(x,y,player1.get_symbol());
        cout << "-------------------------------" << endl;
        board.display_board();

        if(board.is_winner(player1.get_symbol())){
            cout << player1.to_string() << " is winner" << endl;
            break;
        } else if(board.IsDraw()){
            cout << "no one is winner, it's draw" << endl;
            break;
        }

        // computer plays now
        cout << "-------------------------------" << endl;
        player2.beforeMove(board);
        // check win to computer
        if(board.is_winner(player2.get_symbol())){
            board.display_board();
            cout << "Computer is winner" << endl;
            break;
        }
        else if(board.IsDraw()){
            board.display_board();
            cout << "no one is winner, it's draw" << endl;
            break;
        }
    }
}

void GameManager::playWithHuman(Board &board, Player player1) {
    string name2;
    char symbol2;
    cout << "what's name of the second player : ";
    getline(cin, name2);
    symbol2 = 'o';

    Player player2(name2, symbol2);
    cout << player2.to_string() << endl;

    while (true) {
        board.display_board();
        coordinatePlayer1:
        player1.get_move(x,y);
        if(! board.validCoordinate(x,y)){
            cout << "please enter valid coordinate" << endl;
            goto coordinatePlayer1;
        }

        board.update_board(x,y,player1.get_symbol());
        cout << "-------------------------------" << endl;
        board.display_board();

        if(board.is_winner(player1.get_symbol())){
            cout << player1.to_string() << " is winner" << endl;
            break;
        } else if(board.IsDraw()){
            cout << "no one is winner, it's draw" << endl;
            break;
        }

        coordinatePlayer2:
        player2.get_move(x,y);
        if(! board.validCoordinate(x,y)){
            cout << "please enter valid coordinate" << endl;
            goto coordinatePlayer2;
        }
        cout << "-------------------------------" << endl;
        board.update_board(x,y,symbol2);
        if(board.is_winner(player2.get_symbol())){
            board.display_board();
            cout << name2 << " is winner" << endl;
            break;
        }
        else if(board.IsDraw()){
            board.display_board();
            cout << "no one is winner, it's draw" << endl;
            break;
        }
    }
}


#endif //UNTITLED2_GAMEMANGER_H
