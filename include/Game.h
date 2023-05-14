#ifndef Game_h
#define Game_h
#include "Colony.h"
#include <conio.h>
struct Game{
    size_t size;
    size_t capacity;
    Colony* allColonies;
    size_t round;
    short gameStatus;

    void (*showPopulations)(struct Game*);
    void (*startRounds)(struct Game*);
    void (*getPopulations)(struct Game*);
    void (*delete)(struct Game*);
};
typedef struct Game* Game;

Game new_Game();
void showPopulations(const Game);
void startRounds(const Game);
void getPopulations(const Game);
void deleteGame(const Game);
#endif