#include "Game.h"
// #include "leak_detector_c.h"
typedef void* Object;
int main()
{
    srand(time(NULL));
    Game game=new_Game();
    game->read(game);
    game->showPopulations(game);
    getch();
    game->startRound(game);
    game->delete(game);
    //130-239
}