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

public:
    Player() {

    }

    ~Player() {}
};

class GameController {
private:
    Player* player0;
    Player* player1;

    int board[3][3];

public:
    GameController(Player* PLAYER0, Player* PLAYER1) {
        // Store the player objects
        this->player0 = PLAYER0;
        this->player1 = PLAYER1;

        // Reset the board
        for (size_t i0 = 0; i0 < 3; i0++) {
            for (size_t i1 = 0; i1 < 3; i1++) {
                board[i0][i1] = 0;
            }
        }
    }

    void show_board() {
        printf("+-----+\n");
        printf("|x+x+x|\n");
        printf("|x+x+x|\n");
        printf("|x+x+x|\n");
        printf("+-----+\n");
    }



    ~GameController() {}
};




/*
 * Main loop
 */
int main(int argc, char **argv)
{





	/*
	 * Terminate the programm successfully
	 */
    return 0;
}
