#ifndef Colony_h
#define Colony_h

#include "TacticA.h"
#include "TacticB.h"
typedef void* Object;
struct Colony{

    char symbol;
    int population;
    int food;
    Object Tactic;
    char tacticCh;
    int wins;
    int loses;

    void (*fight)(struct Colony*, struct Colony*);
};
typedef struct Colony* Colony;
Colony new_Colony(char symbol,int population,char tactic);
void fight(const Colony, const Colony);
void deleteColony(const Colony);
#endif