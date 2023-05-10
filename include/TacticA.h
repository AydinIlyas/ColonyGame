#ifndef TacticA_h
#define TacticA_h
#include "Tactic.h"
struct TacticA{

    Tactic super;
    void (*delete)(struct TacticA*);
};
typedef struct TacticA* TacticA;

TacticA new_TacticA();
int fightA(const TacticA);
void deleteTacticA(const TacticA);
#endif