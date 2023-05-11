#ifndef Game_h
#define Game_h

#include <stdlib.h>
#include "Colony.h"
#include <conio.h>
struct Game{
    size_t size;
    size_t capacity;
    Colony* colonies;
    size_t round;

    void (*showPopulations)(struct Game*);
    void (*startRound)(struct Game*);
    void (*read)(struct Game*);
    void (*delete)(struct Game*);
};
typedef struct Game* Game;

Game new_Game();
void showPopulations(const Game);
void startRound(const Game);
void read(const Game);
void deleteGame(const Game);
#endif