#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "valid_Game.h"
#include "valid_terminal.h"
#include "valid_utils.h"
int main(void) {
    srand(time(NULL) * 100);
    Game game;
    initGame(&game);
    while (1) {
        int aiGuess = beforeTurn(&game);
        int guess = requestNewGuess(aiGuess);
        if (guess == -1) {
            revert1Turn(&game);
            continue;
        }
        Result res = requestNewGuessResult(guess);
        GameResult gameResult = takeGuessResult(&game, guess, res);
        if (gameResult != Ongoing) {
            endGame(&game, gameResult);
            break;
        }
    }
    return 0;
}
