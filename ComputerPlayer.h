//
// Created by lap top eur on ١٥/١١/٢٠٢٢.
//

#ifndef X_O_COMPUTERPLAYER_H
#define X_O_COMPUTERPLAYER_H
#include "Player.hpp"
#include <vector>

struct ComputerMove{
    int x, y, score;

    // constructor to initialize by score only
    ComputerMove(int Score){
        score = Score;
    }

    // empty constructor
    ComputerMove(){}
};

class ComputerPlayer : public Player{
private:
    ComputerMove theBestMove(Board &board, char symbol);
public:
    // constructor that initialize
    ComputerPlayer(char symbol);

    void beforeMove(Board &board);


};

ComputerPlayer::ComputerPlayer(char symbol): Player(symbol) {
    this->symbol = symbol;
    this->name = "Virtual Player";
}

// it made as the computer is play with symbol o only and the human is x
// it's the function that returns with the highest score, MiniMax Algorithm
ComputerMove ComputerPlayer::theBestMove(Board &board, char symbol) {

    // the base case
    if (board.is_winner('o')) {
        return ComputerMove(10);
    }
    else if(board.is_winner('x')){
        return ComputerMove(-10);
    }
    else if(board.IsDraw()){
        return ComputerMove(0);
    }

    // vector to save all the moves done
    vector<ComputerMove>moves;

    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            if(board.validCoordinate(x,y)){
                ComputerMove move;
                move.x = x;
                move.y = y;

                board(x,y) = symbol;

                if(symbol == 'x'){
                    move.score = theBestMove(board, 'o').score;
                }else{
                    move.score = theBestMove(board, 'x').score;
                }

                moves.push_back(move);

                // to remove the symbol I put it
                board(x,y) = '0';
            }
        }
    }

    int bestMove;
    if(symbol == 'o'){
        int bestScore = -10000000;
        for (int i = 0; i < moves.size(); ++i) {
            if(moves[i].score > bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }else{
        int bestScore = 10000000;
        for (int i = 0; i < moves.size(); ++i) {
            if(moves[i].score < bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    return moves[bestMove];
}

void ComputerPlayer::beforeMove(Board &board) {
    ComputerMove BestMove = theBestMove(board, 'o');
    board.update_board(BestMove.x, BestMove.y, 'o');
    cout << "Computer Play o in " << BestMove.x << "  " << BestMove.y << endl;
}


// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool IsEmptyCoordinate(Board &board){
    for (int i = 0;i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board(i, j) == '0')
                return true;
    return false;
}

#endif //X_O_COMPUTERPLAYER_H


