#ifndef Colony_h
#define Colony_h

#include "TacticA.h"
#include "TacticB.h"
#include "ProductionA.h"
#include "ProductionB.h"
#include "string.h"
#include "math.h"
typedef void* Object;
typedef enum {false,true} bool;
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
    bool alive;

    void (*fight)(struct Colony*, struct Colony*);
    bool (*checkAndReset)(struct Colony*);
    void (*roundImpact)(struct Colony*);
    void (*produce)(struct Colony*);
    char* (*toString)(struct Colony*);
    void (*delete)(struct Colony*);
};
typedef struct Colony* Colony;
Colony new_Colony(char symbol,int population,char tactic,char production);
void fightColonies(const Colony, const Colony);
bool checkAndReset(const Colony);
void roundImpact(const Colony);
void produceColony(const Colony);
char* toString(const Colony);
void deleteColony(const Colony);
#endif