#ifndef TacticB_h 
#define TacticB_h 

#include "Tactic.h"
#include <stdlib.h>
#include <stdio.h>
struct TacticB{
    Tactic super;
    void (*delete)(struct TacticB*);
};
typedef struct TacticB* TacticB;

TacticB new_TacticB();
int fightB(const TacticB);
void deleteTacticB(const TacticB);

#endif