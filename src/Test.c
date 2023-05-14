#include "Game.h"
typedef void* Object;
int main()
{
    srand(time(NULL));
    Game game=new_Game();
    game->getPopulations(game);
    game->showPopulations(game);
    game->startRounds(game);
    game->delete(game);
}