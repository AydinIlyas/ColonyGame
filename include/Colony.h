#ifndef Colony_h
#define Colony_h

#include "TacticA.h"
#include "TacticB.h"
#include "ProductionA.h"
#include "ProductionB.h"
#include "string.h"
#include "math.h"
typedef void* Object;
struct Colony{

    char symbol;
    int population;
    int food;
    Object Tactic;
    Object Production;
    char tacticCh;
    char productionCh;
    int wins;
    int loses;

    void (*fight)(struct Colony*, struct Colony*);
    void (*produce)(struct Colony*);
    char* (*toString)(struct Colony*);
    void (*delete)(struct Colony*);
};
typedef struct Colony* Colony;
Colony new_Colony(char symbol,int population,char tactic,char production);
void fight(const Colony, const Colony);
void produce(const Colony);
char* toString(const Colony);
void deleteColony(const Colony);
#endif