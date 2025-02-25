#include <iostream>
#include <string>
using namespace std;

class board {
    private:
        int board_state[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    public:
        bool game_over() {
            for (int i = 0; i < 3; i++) {
                if (board_state[i*3] == board_state[i*3+1] && board_state[i*3+1] == board_state[i*3+2]) {
                    return true;
                } else if (board_state[i] == board_state[i+3] && board_state[i+3] == board_state[i+6]) {
                    return true;
                }
            }

            if (board_state[0] == board_state[4] && board_state[4] == board_state[8]) {
                return true;
            }

            if (board_state[2] == board_state[4] && board_state[4] == board_state[6]) {
                return true;
            }
            return false;
        }

        bool make_move(int player, int pos) {
            if (pos < 0 || pos > 8) {
                return false;
            } else if (board_state[pos] >= 0) {
                board_state[pos] = -1*player;
                return true;
            } else {
                return false;
            }
        }

        string stringify_board() {
            string brd;
            for (int i = 0; i < 9; i++) {
                if (board_state[i] == -1) {
                    brd = brd + " X ";
                } else if (board_state[i] == -2) {
                    brd = brd + " O ";
                } else {
                    brd = brd + " " + to_string(i) +" ";
                }
                if ((i + 1) % 3 == 0) {
                    brd = brd + "\n";
                }
            }
            return brd;
        }    
};

int main() {
    board ttt;
    int player = 1;
    int turn = 0;
    cout << "Welcome to Tic Tac Toe.\nThis game is played in the console.\n In order to select a square enter a number 0-8 such that the numbers correspond to a space on the board as shown:\n";
    while(!ttt.game_over() && turn < 9) {
        cout << ttt.stringify_board();
        cout << "Player " << player << " , please select a square.\n";
        int pos;
        cin >> pos;
        while(!ttt.make_move(player, pos)) {
            cout << "Sorry, this is an invalid square.\n";
            cout << "Player " << player << ", please select a square.\n";
            cin >> pos;
        }
        if (ttt.game_over()) {
            cout << ttt.stringify_board();
            cout << "Player " << player << " has won the game.\nTerminating program.";
        } else {
            player = player == 1 ? 2 : 1;
            turn++;
        }
        if (turn >= 8 && !ttt.game_over()) {
            cout << "It's a draw. Terminating program.";
        }
    }
    return 0;
}