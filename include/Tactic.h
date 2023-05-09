#ifndef Tactic_h
#define Tactic_h

#include <stdlib.h>
#include <stdio.h>
#include "time.h"
struct Tactic{
    int power;

    int (*fight)();
    void (*delete)(struct Tactic*);
};
typedef struct Tactic* Tactic;

Tactic new_Tactic();
void delete_Tactic(const Tactic);

#endif