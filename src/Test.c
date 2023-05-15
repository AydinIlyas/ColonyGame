#include "Game.h"
#include <time.h>
#include <stdlib.h>
int main()
{
    
    srand(time(NULL));
    int play = 1;
    while (play)
    {
        Game game = new_Game();
        game->getPopulations(game);
        game->showPopulations(game);
        game->startRounds(game);
        play=game->gameStatus;
        game->delete (game);
    }
    return 0;
}