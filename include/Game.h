#ifndef Game_h
#define Game_h

#include <stdlib.h>
#include "Colony.h"
struct Game{
    size_t size;
    size_t capacity;
    Colony* colonies;
    
    void (*read)(struct Game*);
    void (*delete)(struct Game*);
};
typedef struct Game* Game;

Game new_Game();
void read(const Game);
void deleteGame(const Game);
#endif