#include "Game.h"
// #include "leak_detector_c.h"
typedef void* Object;
int main()
{
    srand(time(NULL));
    Game game=new_Game();
    game->read(game);
    Colony* candidates=game->colonies;
    for(int i=0;i<game->size;i++)
    {
        char* str=candidates[i]->toString(candidates[i]);
        printf("%s",str);
    }
    printf("Size: %d\t\tCapacity: %d",game->size,game->capacity);
    //130-239
}