//
//  main.c
//
//  Created by Matthias Konrath on 09.10.17.
//  Copyright © 2017 Matthias Konrath. All rights reserved.
//  Compile with: gcc -o main main.cpp -lssl -lcrypto
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*
 * Colors for the terminal
 */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"



class Player {
private:
    char symbol = 0;
    char* name = NULL;

public:
    Player(char SYMBOL, char* NAME) {
        this->symbol = SYMBOL;
        this->name = NAME;
    }

    char get_symbol() {
        return this->symbol;
    }

    char* get_name() {
        return this->name;
    }

    ~Player() {}
};


class GameController {
private:
    Player* player0;
    Player* player1;

    int board[3][3];

    void reset_board() {
        // Reset the board
        for (size_t i0 = 0; i0 < 3; i0++) {
            for (size_t i1 = 0; i1 < 3; i1++) {
                board[i0][i1] = 0;
            }
        }
    }

public:
    GameController(Player* PLAYER0, Player* PLAYER1) {
        // Store the player objects
        this->player0 = PLAYER0;
        this->player1 = PLAYER1;

        // Reset the board
        this->reset_board();
    }

    /*
     * Print the current board on the screen
     */
    void show_board() {
        printf("Board:\n");
        printf("+-------+\n");
        for (size_t i0 = 0; i0 < 3; i0++) {
            printf("| ");
            for (size_t i1 = 0; i1 < 3; i1++) {
                // Check if the field is already set
                if (this->board[i0][i1] != 0) {
                    // Check if the field is set by player 0 or 1
                    if (this->board[i0][i1] == 1) {
                        printf("%c", this->player0->get_symbol());
                    } else {
                        printf("%c", this->player1->get_symbol());
                    }
                // If the field is not set use a special symbol
                } else {
                    printf("-");
                }
                // Ensure spacing between the symbols
                if (i1 == 0 || i1 == 1) {
                    printf(" ");
                }
            }
            printf(" |\n");
        }
        printf("+-------+\n");
    }

    /*
     * Get a move from a player
     */
    bool get_move(Player* PLAYER, int POS_X, int POS_Y) {
        // Check if the Position exists
        if (POS_X <= 2 && POS_Y <= 2) {
            // Check if the possition is already taken
            if (this->board[POS_X][POS_Y] == 0) {
                // Check if the player exists
                if (PLAYER == this->player1) {
                    this->board[POS_X][POS_Y] = 1;
                    return true;
                }
                // Check if the player exists
                if (PLAYER == this->player0) {
                    this->board[POS_X][POS_Y] = 2;
                    return true;
                }
            }
        }
        return false;
    }

    /*
     * Check if a player wone
     */
    bool check_for_winner() {
        // Check for three in a row
        for (size_t i0 = 0; i0 < 3; i0++) {
            if (this->board[i0][0] == this->board[i0][1] && this->board[i0][1] == this->board[i0][2] && this->board[i0][0] != 0) {
                // Find the winner
                if (this->board[i0][0] == 1) {
                    printf("Player %s has won!\n", this->player0->get_name());
                } else {
                    printf("Player %s has won!\n", this->player1->get_name());
                }
                return true;
            }
        }

        // Check for three in a row
        for (size_t i0 = 0; i0 < 3; i0++) {
            if (this->board[0][i0] == this->board[1][i0] && this->board[1][i0] == this->board[2][i0] && this->board[0][i0] != 0) {
                // Find the winner
                if (this->board[0][i0] == 1) {
                    printf("Player %s has won!\n", this->player0->get_name());
                } else {
                    printf("Player %s has won!\n", this->player1->get_name());
                }
                return true;
            }
        }

        // Check for other possible wins
        if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[1][1] != 0) {
            // Find the winner
            if (this->board[1][1] == 1) {
                printf("Player %s has won!\n", this->player0->get_name());
            } else {
                printf("Player %s has won!\n", this->player1->get_name());
            }
            return true;
        }
        if (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[0][2] && this->board[1][1] != 0) {
            // Find the winner
            if (this->board[1][1] == 1) {
                printf("Player %s has won!\n", this->player0->get_name());
            } else {
                printf("Player %s has won!\n", this->player1->get_name());
            }
            return true;
        }
        return false;
    }


    ~GameController() {}
};




/*
 * Main loop
 */
int main(int argc, char **argv)
{

    Player player0 = Player('x', "matthias");
    Player player1 = Player('o', "bernhard");

    GameController game = GameController(&player0, &player1);
    game.show_board();

    int pos_x, pos_y;

    for (size_t i = 0; i < 9; i++) {
        // Select the player
        if (i % 2 == 0) {
            do {
                printf("\nPlayer %s has to enter a position:\n", player0.get_name());
                printf("\tPosition X:"); scanf("%d", &pos_x);
                printf("\tPosition Y:"); scanf("%d", &pos_y);
            } while(game.get_move(&player0, pos_x, pos_y) == false);
        } else {
            do {
                printf("\nPlayer %s has to enter a position:\n", player1.get_name());
                printf("\tPosition X:"); scanf("%d", &pos_x);
                printf("\tPosition Y:"); scanf("%d", &pos_y);
            } while(game.get_move(&player1, pos_x, pos_y) == false);
        }
        game.show_board();
        if (game.check_for_winner()) {
            printf("GAME FINISHED!\n");
            break;
        }
    }

	/*
	 * Terminate the programm successfully
	 */
    return 0;
}
