#ifndef TacticA_h
#define TacticA_h
#include "Tactic.h"
struct TacticA{

    Tactic super;
    int (*fight)(struct TacticA*);
    void (*delete)(struct TacticA*);
};
typedef struct TacticA* TacticA;

TacticA new_TacticA();
int fight(const TacticA);
void deleteTacticA(const TacticA);
#endif